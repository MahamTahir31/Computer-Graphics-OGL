

#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <fileapi.h>

void PlayBackgroundSound(const wchar_t* filename);
void PlayForegroundSound(const wchar_t* filename);

typedef PVOID HWAV;

typedef struct {
    HWAVEOUT hWaveOut;
    HANDLE hEvent;
    HANDLE hThread;
    WAVEFORMATEX WaveFormatEx;
    BOOL bWaveShouldDie;
    BOOL bLoop;
    WAVEHDR Hdr;
} WAV, * PWAV;

void CALLBACK RepeatCallback(HWAVEOUT hwo, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
    PWAV pWav = (PWAV)dwInstance;

    switch (uMsg)
    {
    case WOM_DONE:
        if (!pWav->bLoop) pWav->bWaveShouldDie = TRUE;
        SetEvent(pWav->hEvent);
        break;
    }
}

BOOL ReadWavFile(const wchar_t* pFileName, PWAV pWav)
{
    typedef struct saad
    {
        UCHAR IdentifierString[4];
        DWORD dwLength;
    } RIFF_CHUNK, * PRIFF_CHUNK;

    typedef struct
    {
        WORD  wFormatTag;         // Format category
        WORD  wChannels;          // Number of channels
        DWORD dwSamplesPerSec;    // Sampling rate
        DWORD dwAvgBytesPerSec;   // For buffer estimation
        WORD  wBlockAlign;        // Data block size
        WORD  wBitsPerSample;
    } WAVE_FILE_HEADER, * PWAVE_FILE_HEADER;

    BOOL bSampleLoaded = FALSE;
    HANDLE hFile;
    RIFF_CHUNK RiffChunk = { 0 };
    DWORD dwBytes, dwReturnValue;
    WAVE_FILE_HEADER WaveFileHeader;
    DWORD dwIncrementBytes;

    if (hFile = CreateFileW(pFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL))
    {
        char szIdentifier[5] = { 0 };
        SetFilePointer(hFile, 12, NULL, FILE_CURRENT);

        ReadFile(hFile, &RiffChunk, sizeof(RiffChunk), &dwBytes, NULL);
        ReadFile(hFile, &WaveFileHeader, sizeof(WaveFileHeader), &dwBytes, NULL);

        pWav->WaveFormatEx.wFormatTag = WaveFileHeader.wFormatTag;
        pWav->WaveFormatEx.nChannels = WaveFileHeader.wChannels;
        pWav->WaveFormatEx.nSamplesPerSec = WaveFileHeader.dwSamplesPerSec;
        pWav->WaveFormatEx.nAvgBytesPerSec = WaveFileHeader.dwAvgBytesPerSec;
        pWav->WaveFormatEx.nBlockAlign = WaveFileHeader.wBlockAlign;
        pWav->WaveFormatEx.wBitsPerSample = WaveFileHeader.wBitsPerSample;
        pWav->WaveFormatEx.cbSize = 0;

        dwIncrementBytes = dwBytes;

        do {
            SetFilePointer(hFile, RiffChunk.dwLength - dwIncrementBytes, NULL, FILE_CURRENT);
            dwReturnValue = GetLastError();
            if (dwReturnValue == 0)
            {
                dwBytes = ReadFile(hFile, &RiffChunk, sizeof(RiffChunk), &dwBytes, NULL);
                dwIncrementBytes = 0;
                memcpy(szIdentifier, RiffChunk.IdentifierString, 4);
            }

        } while (_stricmp(szIdentifier, "data") && dwReturnValue == 0);

        if (dwReturnValue == 0)
        {
            pWav->Hdr.lpData = (char*)LocalAlloc(LMEM_ZEROINIT, RiffChunk.dwLength);
            pWav->Hdr.dwBufferLength = RiffChunk.dwLength;
            ReadFile(hFile, pWav->Hdr.lpData, RiffChunk.dwLength, &dwBytes, NULL);
            CloseHandle(hFile);
            bSampleLoaded = TRUE;
        }
    }
    return bSampleLoaded;
}

DWORD WINAPI PlayThread(PVOID pDataInput)
{
    PWAV pWav = (PWAV)pDataInput;

    while (!pWav->bWaveShouldDie)
    {
        waveOutPrepareHeader(pWav->hWaveOut, &pWav->Hdr, sizeof(WAVEHDR));
        waveOutWrite(pWav->hWaveOut, &pWav->Hdr, sizeof(WAVEHDR));
        WaitForSingleObject(pWav->hEvent, INFINITE);
    }

    waveOutReset(pWav->hWaveOut);
    return 0;
}

void StopPlayingWavFile(HWAV HWAV)
{
    PWAV pWav = (PWAV)HWAV;

    if (pWav)
    {
        if (pWav->hThread)
        {
            pWav->bWaveShouldDie = TRUE;

            SetEvent(pWav->hEvent);
            WaitForSingleObject(pWav->hThread, INFINITE);

            CloseHandle(pWav->hEvent);
            CloseHandle(pWav->hThread);
        }

        if (pWav->hWaveOut)
        {
            waveOutClose(pWav->hWaveOut);
        }

        if (pWav->Hdr.lpData)
        {
            LocalFree(pWav->Hdr.lpData);
        }

        LocalFree(pWav);
    }
}

HWAV PlayWavFile(const wchar_t* filename, BOOL bLoop)
{
    PWAV pWav = NULL;

    if (pWav = (PWAV)LocalAlloc(LMEM_ZEROINIT, sizeof(WAV)))
    {
        pWav->bLoop = bLoop;
        if (ReadWavFile(filename, pWav))
        {
            if (waveOutOpen(&pWav->hWaveOut, WAVE_MAPPER, &pWav->WaveFormatEx, (ULONG)RepeatCallback, (ULONG)pWav, CALLBACK_FUNCTION) != MMSYSERR_NOERROR)
            {
                StopPlayingWavFile((HWAV)pWav);
                pWav = NULL;
            }
            else
            {
                DWORD dwThreadId;
                pWav->hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
                pWav->hThread = CreateThread(NULL, 0, PlayThread, pWav, 0, &dwThreadId);
            }
        }
        else
        {
            StopPlayingWavFile((HWAV)pWav);
            pWav = NULL;
        }
    }

    return (HWAV)pWav;
}

void PlayBackgroundSound(const wchar_t* filename)
{
    static HWAV hWav = NULL;

    if (hWav) {
        StopPlayingWavFile(hWav);
        hWav = NULL;
    }

    if (filename != NULL) {
        hWav = PlayWavFile(filename, true);
    }
}

void PlayForegroundSound(const wchar_t* filename)
{
    HWAV hWav = NULL;

    if (filename != NULL) {
        hWav = PlayWavFile(filename, false);
    }
}
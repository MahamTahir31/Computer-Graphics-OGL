#include <Gl/glut.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include "pixMap.h"
#include "Mario.h"

using namespace std;

int screenWidth = 640;
int screenHeight = 480;


Mario m(Point2(0, 0));


void myKB_Handler(unsigned char key, int mx, int my)
{
	switch (key)
	{
	case 'r':
		m.changeMode(Mario::RUN);
		break;
	case 'j':
		m.changeMode(Mario::JUMP);
		break;
	}
	glutPostRedisplay();
}

void pressKeySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		//m.setPosition(-40, 0); // shows animation and sets position but do not change position
		m.changePosition(-40, 0);
		m.changeMode(Mario::RUN);
		break;

	case GLUT_KEY_RIGHT:
		//m.setPosition(20, 0);
		m.changePosition(20, 0);
		m.changeMode(Mario::RUN);
		break;

	case GLUT_KEY_UP:
		if (m.pos_Y < 12)
			//m.setPosition(4, 5);
			m.changePosition(4, 15);
		m.changeMode(Mario::JUMP);
		break;

	case GLUT_KEY_DOWN:
		break;
	}
	glutPostRedisplay();
}

void releaseKeySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;

	case GLUT_KEY_UP:
		if (m.pos_Y != 0)
		{
			m.setPosition(m.pos_X, 0);
			m.changeMode(Mario::STAY);
		}
		break;

	case GLUT_KEY_DOWN:

		break;
	}
	glutPostRedisplay();
}

void myInit(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glViewport(0, 0, screenWidth, screenHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_ALPHA_TEST); // in dono ko comment krne se full pic arhi hai with BG
	glAlphaFunc(GL_EQUAL, 1.0);
	m.changeMode(Mario::STAY);
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m.render();
	glFlush();
}

void spinner(int t)
{
	glutPostRedisplay();
	glutTimerFunc(500, spinner, t);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("---My Mario---");

	glutDisplayFunc(myDisplay);
	glutSpecialFunc(pressKeySpecial);
	glutSpecialUpFunc(releaseKeySpecial);
	glutKeyboardFunc(myKB_Handler);

	myInit();
	glutMainLoop();
}

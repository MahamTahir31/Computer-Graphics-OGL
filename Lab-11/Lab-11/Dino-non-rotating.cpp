#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "Canvas.h"

using std::cout;
using std::fstream;
using std::ios;

const int SCREENWIDTH = 680;
const int SCREENHEIGHT = 480;

Point2 CP1;
Canvas cvs(SCREENWIDTH, SCREENHEIGHT, "Dino Transformation - Part b");

const float SCALE_FACTOR = 13.0;

void drawPolyLineFile(const char* fileName)
{
	fstream inStream;

	inStream.open(fileName, ios::in);	// open the file

	if (inStream.fail())
	{
		cout << "can't open it!"; return;
	}

	// clear the screen

//GLint numpolys, numPoints, x ,y;

	GLfloat numpolys, numPoints, x, y;
	inStream >> numpolys;		           // read the number of polylines


	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       //number of points in first PolyLine  
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	inStream.close();
}



void drawDino() {
	glBegin(GL_LINE_STRIP);
	glClear(GL_COLOR_BUFFER_BIT);
	drawPolyLineFile("dino.txt");
	glFlush();
	glutSwapBuffers();
	glEnd();
}
void DinoTransform() {
	glTranslatef(SCREENWIDTH / 2.0, SCREENHEIGHT / 2.0, 0.0);
	const int numMotifs = 12;
	for (int i = 0; i < numMotifs; i++)
	{
		cvs.initCT(); // init CT at each iteration
		cvs.scale2D(0.115, 0.115);
		cvs.rotate2D(i * 360 / numMotifs); // rotate
		cvs.translate2D(0, 900); // shift along y-axis
		cvs.rotate2D(i * -360 / numMotifs);
		drawDino();
	}


}
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);  // set white background color
	glColor3f(0.0f, 0.0f, 0.0f);  // set the drawing color
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	cvs.setWindow(0.0, SCREENWIDTH, 0.0, SCREENHEIGHT);
	cvs.setViewport(0, SCREENWIDTH, 0, SCREENHEIGHT);
	DinoTransform();
	glFlush();
}
void main(int argc, char** argv) {
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
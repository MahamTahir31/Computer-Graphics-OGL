#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "Canvas.h"

# define PI 3.1415926

const int SCREENWIDTH = 680;
const int SCREENHEIGHT = 480;

Point2 CP1;
Canvas cvs(SCREENWIDTH, SCREENHEIGHT, "Hexagonal Tilings");


void drawHexagon(int x, int y)
{
	glTranslatef(x, y, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(0, 0);
	glVertex2i(20, 0);
	glVertex2i(25, 10);
	glVertex2i(20, 20);
	glVertex2i(0, 20);
	glVertex2i(-5, 10);
	glVertex2i(0, 0);
	glEnd();
}

void drawHexagonTilings(int x, int y, int r, int start_position_x, int start_position_y) {

	cvs.translate2D(0, 0);
	cvs.pushCT(); // so we can return here
	for (int i = 0; i < y; i++)// for each column
	{
		cvs.pushCT();
		for (int j = 0; j < x; j++) // for each row
		{
			drawHexagon(start_position_x, start_position_y);
			// move to the right
			cvs.translate2D(-start_position_x, -(start_position_y - 20));
		}
		// back to the start of this column
		cvs.popCT();
		// move to the next column
		cvs.translate2D(1.5 * r, pow(-1, i + 1) * sin(PI / 3.) * 0.75 * r);
	}


	cvs.popCT();
}

void myInit(void) {
	cvs.initCT();
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
	drawHexagonTilings(10, 10, 16, 200, 200);
	glFlush();
}
void main(int argc, char** argv) {

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
//#include <windows.h>
//#include <gl/glut.h>
//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//const float PI = 3.1415926536;
//const int width = 1600;
//const int height = 900;
//
//class GLintPoint
//{
//public:
//	GLint x, y;
//};
//
//class Point2
//{
//public:
//	float x, y;
//
//	void set(float dx, float dy)
//	{
//		x = dx;
//		y = dy;
//	}
//
//	void set(Point2& p)
//	{
//		x = p.x;
//		y = p.y;
//	}
//
//	Point2(float xx, float yy)
//	{
//		x = xx;
//		y = yy;
//	}
//
//	Point2()
//	{
//		x = y = 0;
//	}
//};
//
//class Turtle {
//private:
//	int CD = 90;
//	Point2 CP;
//
//public:
//	Turtle() {
//		CP.set(0, 0);
//	}
//
//	Turtle(Point2 currPosition) {
//		CP.set(currPosition);
//	}
//
//	void moveTo(Point2 p) {
//		CP.set(p);
//	}
//
//	void drawForward(int steps) {
//		float radian = CD * PI / 180;
//		float stepsf = (float)steps / 100;
//		float nextX = CP.x + cos(radian) * stepsf;
//		float nextY = CP.y + sin(radian) * stepsf;
//
//		glBegin(GL_LINES);
//		glVertex2f(CP.x, CP.y);
//		glVertex2f(nextX, nextY);
//		glEnd();
//		glFlush();
//
//		CP.set(nextX, nextY);
//	}
//
//	void turnRight() {
//		CD = CD - 90;
//		cout << "CD: " << CD << endl;
//	}
//
//	void turnleft() {
//		CD = CD + 90;
//		cout << "CD: " << CD << endl;
//	}
//
//	void turn(int degrees) {
//		CD = CD + degrees;
//		cout << "CD: " << CD << endl;
//	}
//};
//
//Turtle t(Point2(-0.5, -0.5));
//
//void myInit(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glClearColor(1, 1, 1, 0);
//	glColor3f(0, 0, 0);
//}
//
//void drawLogo(int sideLength) {
//	t.turn(-30);
//	t.drawForward(sideLength);
//	t.turn(-60);
//	t.drawForward(sideLength);
//	t.turn(120);
//	t.drawForward(sideLength);
//	t.turn(-60);
//	t.drawForward(sideLength);
//	t.turn(-120);
//	t.drawForward(sideLength);
//	t.turn(-60);
//	t.drawForward(sideLength);
//	t.turn(120);
//	t.drawForward(sideLength);
//	t.turn(-60);
//	t.drawForward(sideLength);
//	t.turn(-120);
//	t.drawForward(sideLength);
//	t.turn(-60);
//	t.drawForward(sideLength);
//	t.turn(120);
//	t.drawForward(sideLength);
//	t.turn(-60);
//	t.drawForward(sideLength);
//}
//
//void drawShape() {
//	glColor3f(0, 0, 0);
//	drawLogo(30);
//
//}
//void render()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glViewport(10, 10, width, height);
//	drawShape();
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glutInitWindowSize(width, height);
//	glutCreateWindow("logo");
//	glutDisplayFunc(render);
//	myInit();
//	glutMainLoop();
//	return 0;
//}
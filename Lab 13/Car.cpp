//#include <gl/glut.h>
//#include<cmath>
//#include<iostream>
//using namespace std;
//float speed = 0;
//float deg = 0;
//bool isMoving = false;
//
//
//
//
//void drawRoof() {
//    glBegin(GL_QUADS);
//    glShadeModel(GL_SMOOTH);
//
//    glBegin(GL_QUADS);
//    glColor3f(0.0f, 1.0f, 0.0f);
//
//    glVertex2f(-4.0f, 0.0f);
//    glColor3f(1.0f, 0.5f, 0.0f);
//    glVertex2f(-4.0f, 4.0f);
//
//    glColor3f(0.5f, 0.0f, 0.5f);
//    glVertex2f(4.0f, 4.0f);
//    glColor3f(1.0f, 1.0f, 0.0f);
//    glVertex2f(4.0f, 0.0f);
//
//    glEnd();
//}
//
//void drawBody() {
//    glBegin(GL_QUADS);
//    glShadeModel(GL_SMOOTH);
//
//    glBegin(GL_QUADS);
//    glColor3f(1.0f, 1.0f, 1.0f);
//
//    glVertex2f(-6.0f, -3.0f);
//    glColor3f(1.0f, 0.5f, 0.0f);
//    glVertex2f(-6.0f, 3.0f);
//
//    glColor3f(0.0f, 1.0f, 0.0f);
//    glVertex2f(6.0f, 3.0f);
//    glColor3f(1.0f, 1.0f, 0.0f);
//    glVertex2f(6.0f, -3.0f);
//
//    glEnd();
//}
//
//
//void drawTyre() {
//
//    glBegin(GL_POLYGON);
//    glColor3f(0.1f, 0.1f, 0.1f);
//    for (int i = 0; i < 360; i++) {
//        float radian = i * 3.14159265358979323846 / 180;
//        float x = cos(radian) * 2.0f;
//        float y = sin(radian) * 2.0f;
//        glVertex2f(x, y);
//    }
//    glEnd();
//
//
//    glBegin(GL_POLYGON);
//    glColor3f(0.3f, 0.3f, 0.3f);
//    for (int i = 0; i < 360; i++) {
//        float radian = i * 3.14159265358979323846 / 180;
//        float x = cos(radian) * 1.5f;
//        float y = sin(radian) * 1.5f;
//        glVertex2f(x, y);
//    }
//    glEnd();
//
//
//    glPushMatrix();
//    glRotatef(deg, 0, 0, 1);
//    glBegin(GL_LINES);
//    glColor3f(0.1f, 0.1f, 0.1f);
//    for (int i = 0; i < 360; i += 30) {
//        float start_x = cos(i * 3.14159265358979323846 / 180) * 1.5f;
//        float start_y = sin(i * 3.14159265358979323846 / 180) * 1.5f;
//        float end_x = cos(i * 3.14159265358979323846 / 180) * 2.0f;
//        float end_y = sin(i * 3.14159265358979323846 / 180) * 2.0f;
//        glVertex2f(0.0f, 0.0f);
//        glVertex2f(start_x, start_y);
//        glVertex2f(0.0f, 0.0f);
//        glVertex2f(end_x, end_y);
//    }
//    glEnd();
//    glPopMatrix();
//}
//
//
//
//
//void processMenuEvents(int option)
//{
//    switch (option) {
//    case 1:
//        isMoving = true;
//        speed = -5;
//        deg = -5;
//        break;
//
//    case 101:
//        exit(0);
//        break;
//    }
//}
//
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    if (speed >= 27) {
//        speed = -27;
//    }
//    glPushMatrix();
//    glTranslatef(speed, 4, 0);
//    drawRoof();
//    glPushMatrix();
//    glTranslatef(0, -2, 0);
//    drawBody();
//    glPushMatrix();
//    glTranslatef(-4, -2, 0);
//    drawTyre();
//    glPushMatrix();
//    glTranslatef(8, 0, 0);
//    drawTyre();
//    glPopMatrix();
//    glPopMatrix();
//    glPopMatrix();
//    glPopMatrix();
//    glFlush();
//}
//void Timer(int value)
//{
//    speed += 0.05;
//    deg += 2;
//    display();
//    glutTimerFunc(30, Timer, 1);
//
//}
//void reshape(GLsizei w, GLsizei h)
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-20, 20, -20, 20);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//void init()
//{
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-20, 20, -20, 20);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Burhan Racing Car");
//    init();
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutTimerFunc(30, Timer, 1);
//    glutCreateMenu(processMenuEvents);
//    glutAddMenuEntry("Reset", 1);
//    glutAddMenuEntry("Exit", 101);
//    glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//    glutMainLoop();
//    return 0;
//}
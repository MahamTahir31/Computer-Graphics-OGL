//#include <GL/glut.h>
//#include <cmath>
//#include "Canvas.h"
//
//Canvas cvs(640, 480, "Gear Wheel");
//const double PI = 3.14159265358979323846;
//const int numTeeth = 30;
//const double toothWidth = 10.0;
//const double radius = 100.0;
//const double gearThickness = 20.0;
//const double rotationSpeed = 1.0;
//const double centerCircleRadius = 10.0; // Smaller center circle radius
//
//void tooth0() { // draw tooth of gear
//    glBegin(GL_LINE_STRIP);
//    glVertex2f(0.0, 0.0);
//    glVertex2f(0.2, 0.2);
//    glVertex2f(0.6, 0.2);
//    glVertex2f(0.6, 0.8);
//    glVertex2f(0.2, 0.8);
//    glVertex2f(0.0, 1.0);
//    glEnd();
//}
//
//void tooth1(double r) {
//    double rad = 6.0 * PI / 180.0;
//    double sin6 = r * sin(rad);
//    double cos6 = r * cos(rad);
//    glPushMatrix();
//    cvs.pushCT();
//    cvs.translate2D(cos6, -sin6); // shape of tooth 
//    cvs.scale2D(2.0 * sin6, 2.0 * sin6); // size of tooth
//    tooth0(); // draw tooth of gear
//    cvs.popCT(); // for setting model view transformation
//}
//
//void gear(double r) {
//    for (int i = 0; i < numTeeth; ++i) {
//        tooth1(r);
//        cvs.rotate2D(360.0 / numTeeth);
//    }
//}
//
//void drawGear() {
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glPushMatrix(); // to save current state of matrix in matrix stack
//
//    // Rotate the gear
//    static double angle = 0.0;
//    angle += rotationSpeed;
//    glRotatef(angle, 0.0, 0.0, 1.0); // transformation - rotation
//
//    gear(radius); // gear when moving
//
//    // Draw the smaller center circle
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2f(0.0, 0.0);
//    for (int i = 0; i <= 360; i += 10) {
//        double radian = i * PI / 180.0;
//        glVertex2f(centerCircleRadius * cos(radian), centerCircleRadius * sin(radian));
//    }
//    glEnd();
//
//    glPopMatrix(); // restore the previously saved matrix state from the matrix stack
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT); 
//    // matrices are used to perform various transformations such as translation, rotation, scaling, and projection
//    glLoadIdentity(); // reset the current matrix to the identity matrix.
//
//    drawGear(); // to draw gear
//
//    // forces all the issued commands to be sent to the graphics hardware for processing
//    glFlush();
//}
//
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    // left, right, bottom, top, near, and far
//    glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1); 
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutIdleFunc(display); // update the display continuously during idle time (when system is idle - not handling another event)
//
//    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // clear the window to white
//
//    glutMainLoop();
//
//    return 0;
//}
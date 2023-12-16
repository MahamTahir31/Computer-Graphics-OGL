//#include <windows.h>
//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <iostream>
//#include <fstream>
//#include <cmath>
//using namespace std;
//
//const int screenwidth = 650;
//const int screenheight = 450;
//const int numdinosaurs = 24;  // number of dinosaurs in the circle
//const float circleradius = min(screenwidth, screenheight) * 0.4;  // radius of the circle
//
//void drawdinosaur(string filename) {
//    fstream instream;
//    instream.open(filename, ios::in);
//
//    if (instream.fail()) {
//        cout << "can't open " << filename << endl;
//        return;
//    }
//
//    // read the number of polylines in the dinosaur
//    GLfloat numpolys, numpoints, x, y;
//    instream >> numpolys;
//
//    for (int j = 0; j < numpolys; j++) {
//        instream >> numpoints;
//        glBegin(GL_LINE_STRIP);
//
//        for (int i = 0; i < numpoints; i++) {
//            instream >> x >> y;
//            glVertex2f(x, y);
//        }
//
//        glEnd();
//    }
//
//    instream.close();
//}
//
//void myinit(void) {
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glPointSize(2.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, (GLdouble)screenwidth, 0.0, (GLdouble)screenheight);
//    glViewport(0, 0, screenwidth, screenheight);
//}
//
//void mydisplay(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0f, 0.0f, 0.0f);
//
//    for (int i = 0; i < numdinosaurs; i++) {
//        glPushMatrix();
//        // calculate the angle for each dinosaur in the circle
//        float angle = (360.0 / numdinosaurs) * i;
//        // translate to the position on the circle
//        glTranslatef(screenwidth / 2.0 + circleradius * cos(angle * 3.14159265 / 180.0),
//            screenheight / 2.0 + circleradius * sin(angle * 3.14159265 / 180.0), 0);
//        // scale down the size of the dinosaur
//        glScalef(0.1, 0.1, 0.1);  // adjust the scaling factor as needed
//        // rotate the dinosaur to point its feet towards the origin
//        glRotatef(angle - 90, 0, 0, 1);
//        drawdinosaur("dino.txt");
//        glPopMatrix();
//    }
//
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(screenwidth, screenheight);
//    glutInitWindowPosition(10, 10);
//    glutCreateWindow("dinosaur circle");
//
//    glutDisplayFunc(mydisplay);
//    myinit();
//    glutMainLoop();
//    return 1;
//}
#include<iostream>
#include<fstream> // provides input output operations
#include<string>
#include<GL/glut.h>

using namespace std;

void Displaying(void) {
    glClear(GL_COLOR_BUFFER_BIT); // clear color buffer, preparing it for rendering
    glClearColor(0.9f, 0.9f, 0.9f, 0.5); // set clear buffer color to light grey
    glColor3f(0.5, 0.2, 0.3); // set current drawing color
    glFlush(); //  Forces any incomplete rendering commands to be processed.

}

int screenWidth = 440; // width of window
int screenHeight = 380; // height of window

int main(int argc, char** argv) {
    glutInit(&argc, argv); // initialize the toolkit of GLUT and command line arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode, GLUT Depth for 3D rendering, GLUT DOUBLE for animations
    // GLUT SINGLE means single buffer
    glutInitWindowSize(screenWidth, screenHeight); // set window size, either var or values
    glutInitWindowPosition(30, 30); // set window position on screen
    glutCreateWindow("LAB 1"); // open the screen window with this label 
    glutDisplayFunc(Displaying); // register the redraw function
    glutMainLoop(); // enter the unending main loop

    return 0;
}
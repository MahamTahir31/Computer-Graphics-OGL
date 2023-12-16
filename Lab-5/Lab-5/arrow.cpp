/*#include <GL/glut.h>

float f, h, t, w;

void drawArrow() {
    float ht = 2 * h;

    glBegin(GL_LINES);
    glVertex2f(0, 0);      // starting point
    glVertex2f(0, ht);     // arrow shaft
    glVertex2f(-w, ht - t); // arrowhead left
    glVertex2f(0, ht);     // arrowhead top
    glVertex2f(w, ht - t);  // arrowhead right
    glVertex2f(0, ht);     // arrowhead top
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glLineWidth(2.0); // Line width

    drawArrow();

    glFlush();
}

int main(int argc, char** argv) {
    f = 0.0;  // Distance from starting point to arrowhead
    h = 50.0; // Height of the arrow shaft
    t = 10.0; // Height of the arrowhead
    w = 15.0; // Half-width of the arrowhead

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Arrow Example");
    gluOrtho2D(-100, 100, -100, 100);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}*/
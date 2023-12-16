//#include <GL/glut.h>
//#include <cmath>
//
//const int WINDOW_WIDTH = 600;
//const int WINDOW_HEIGHT = 600;
//const float SCALE_FACTOR = 13.0;
//
//void drawFlakeMotif() {
//    glBegin(GL_LINE_STRIP);
//    glVertex2f(3 * SCALE_FACTOR, 3 * SCALE_FACTOR);
//    glVertex2f(0 * SCALE_FACTOR, 8 * SCALE_FACTOR);
//    glVertex2f(-3 * SCALE_FACTOR, 0 * SCALE_FACTOR);
//    glVertex2f(-2 * SCALE_FACTOR, -1 * SCALE_FACTOR);
//    glVertex2f(0 * SCALE_FACTOR, 5 * SCALE_FACTOR);
//    glVertex2f(2 * SCALE_FACTOR, 3 * SCALE_FACTOR);
//    glVertex2f(3 * SCALE_FACTOR, 3 * SCALE_FACTOR);
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0); // Set color to white
//
//    glPushMatrix(); // Save the current matrix
//    glTranslatef(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0, 0.0); // Center the snowflake
//    for (int count = 0; count < 5; count++) {
//        drawFlakeMotif();
//        glRotatef(72.2, 0.0, 0.0, 1.0); // Rotate for the next spoke
//    }
//    glPopMatrix(); // Restore the original matrix
//
//    glFlush();
//}
//
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Star");
//
//    init();
//
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}
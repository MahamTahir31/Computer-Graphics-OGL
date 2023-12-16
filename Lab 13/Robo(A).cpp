//#include <GL/glut.h>
//#include <GL/gl.h>
//#include <cstdlib>
//
//
//float rotationAngle = 0.0;  // Initial rotation angle
//void drawHead() {
//    glPushMatrix();
//    glTranslatef(0.0, 0.5, 0.0);
//    glColor3f(0.3, 0.3, 0.3);  // Gray color for the head
//    glutSolidSphere(0.2, 20, 20);
//    glPopMatrix();
//}
//
//void drawArm() {
//    glColor3f(0.4, 0.4, 0.4);  // Gray color for the arms
//    glScalef(0.4, 1.0, 0.2);
//    glutSolidCube(0.5);
//}
//
//void drawLeg() {
//    glColor3f(0.3, 0.3, 0.3);  // Gray color for the legs
//    glScalef(0.4, 1.0, 0.2);
//    glutSolidCube(0.5);
//}
//
//void drawRobot() {
//    glPushMatrix();
//
//    drawHead();
//
//    glPushMatrix();
//    glTranslatef(-0.3, 0.1, 0.0);
//    drawArm();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0.3, 0.1, 0.0);
//    drawArm();
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3f(0.6, 0.6, 0.6);  // Light gray color for the body
//    glScalef(1.0, 1.5, 0.5);
//    glutSolidCube(0.5);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-0.15, -0.6, 0.0);
//    drawLeg();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0.15, -0.6, 0.0);
//    drawLeg();
//    glPopMatrix();
//
//    glPopMatrix();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    glTranslatef(0.0, -1.0, -3.0);
//
//    // Apply rotation based on the rotationAngle
//    glRotatef(rotationAngle, 0.0, 1.0, 0.0);
//
//    glRotatef(30, 1.0, 0.0, 0.0);
//    glTranslatef(0.0, 0.7, 0.0);
//    drawRobot();
//    glutSwapBuffers();
//}
//
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//    case 'r':
//        rotationAngle += 5.0;  // Rotate right (increase the angle)
//        break;
//    case 'l':
//        rotationAngle -= 5.0;  // Rotate left (decrease the angle)
//        break;
//    case 27:  // ESC key
//        exit(0);
//        break;
//    }
//    glutPostRedisplay();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Hierarchical Robot");
//    glEnable(GL_DEPTH_TEST);
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutKeyboardFunc(keyboard);  // Register the keyboard function
//    glutMainLoop();
//    return 0;
//}
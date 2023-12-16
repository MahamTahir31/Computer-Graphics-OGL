#include <gl/glut.h>
#include <cstdlib>
#define PI 3.141592

void display(void);
void drawWind(void);
void drawwindmill(void);
void drawplane();
void drawlandscape();
void Timer(int value);
void keyboard(unsigned char key, int x, int y);
void init(void);
void reshape(GLsizei w, GLsizei h);

// Define variables for windmill blade rotation and plane animation
float fanRotation = 0.0;
float planeX = 245.0;
float planeY = 230.0;
bool planeCrashed = false;
float fanRotationSpeed = 2.0;
float planeSpeed = 1.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // clearing buffer

    drawlandscape(); // drawing grass and mountains
    drawplane(); // drawing plane
    drawwindmill(); // drawing windmill 

    glutSwapBuffers(); // swaps the front and back buffers, this func used in double buffer rendering
}

void drawWind() // drawing wings 
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(15.0, 30.0);
    glVertex2f(-15.0, 30.0);
    glEnd();
}
void drawlandscape()
{
    /* Draw a box of grass */
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(250.0, 0.0); // go 250 right 
    glColor3f(0.0, 0.9, 0.0); 
    glVertex2f(250.0, 50.0); // go 50 up and 250 right
    glColor3f(0.0, 0.8, 0.0);
    glVertex2f(0.0, 50.0); // go 50 up
    glColor3f(0.0, 0.7, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    /* snow covered mountains */

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.6);
    glVertex2f(250.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(200.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(150.0, 50.0);

    //glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(200.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(150.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);

    glColor3f(0.0, 0.0, 0.7);
    glVertex2f(150.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(100.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(50.0, 50.0);

    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(50.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(0.0, 50.0);

    glEnd();

}

void drawwindmill()
{
    // Draw the windmill structure
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.0, 0.0); // Red color


    // Top part
    glVertex2f(110.0, 50.0);
    glVertex2f(140.0, 50.0);
    glVertex2f(125.0, 110.0);
    glVertex2f(125.0, 110.0);

    glEnd();

    // Draw the four fans
    for (int i = 0; i < 4; i++) {
        glPushMatrix(); // saves the current matrix state onto the matrix stack
        glTranslatef(125.0, 110.0, 0.0); // pivot point for rotating fan blades
        glRotatef(i * 90.0 + fanRotation, 0.0, 0.0, 1.0); /*performs a rotation and rotates the
                                                           coordinate system around the z-axis*/
        drawWind(); // func to draw wings 
        glPopMatrix(); // restores the previous matrix state that was saved using glPushMatrix()
    }
}

void Timer(int value)
{
    // Update fan rotation
    fanRotation += fanRotationSpeed;
    if (fanRotation > 360.0) {
        fanRotation -= 360.0;
    }

    // Update plane position (if not crashed)
    if (!planeCrashed) {
        // Translate the plane horizontally and vertically
        planeX -= planeSpeed;
        planeY -= 0.8;

        // Check if the plane has crashed
        if (planeY <= 50.0) {
            planeY = 50.0;       // Set the plane's position on the ground
            planeSpeed = 0.0;   // Stop the plane from moving further
            planeCrashed = true;
        }
    }

    // Redraw the scene
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 1);
}

void drawplane()
{
    glBegin(GL_TRIANGLES);

    if (!planeCrashed) {
        glColor3f(1.0, 1.0, 1.0); // white color
    }
    else {
        glColor3f(0.0, 0.0, 0.0); // Black color for crashed plane
    }
    // drawing shape of plane
    glVertex2f(planeX, planeY);
    glVertex2f(planeX, planeY + 10.0);
    glVertex2f(planeX - 30.0, planeY);

    if (!planeCrashed) {
        glColor3f(0.2, 0.2, 0.2); // Tail color
    }
    else {
        glColor3f(0.0, 0.0, 0.0); // Black color for crashed plane
    }
    // drawing shape of tail
    glVertex2f(planeX - 1.0, planeY - 2.0);
    glVertex2f(planeX - 1.0, planeY + 5.0);
    glVertex2f(planeX - 17.0, planeY + 5.0);

    glEnd();
}

void init()
{
    glClearColor(0.8f, 0.8f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h); // sets the viewport
    glMatrixMode(GL_PROJECTION); // sets the current matrix mode to the projection matrix
    // projection matrix is responsible for transforming 3D coordinates into 2D coordinates for display on the screen
    glLoadIdentity(); // This function resets the current matrix to identity matrix. This ensures clean matrix state without any previous transformations
    gluOrtho2D(0.0, 250.0, 0.0, 250.0); // specifies the coordinates of the left, right, bottom, and top of the viewing volume
    glMatrixMode(GL_MODELVIEW); // transforming the model's vertices in the scene
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // initialize glut toolkit and command line arguments
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); /*We used Glut double mode coz 
                                                we are using animations in our drawing */
    glutInitWindowPosition(50, 50); // set position of window
    glutInitWindowSize(600, 600); // set position of window size
    glutCreateWindow("WindMill"); // creating window using label name WindMill
    init(); // set current matrix mode to projection matrix and again to model view matrix 
    glutDisplayFunc(display); // register a display function (Redrawing a function)
    glutReshapeFunc(reshape); // register a reshape function (Redrawing a window, adjust viewport & projection matrix)
    glutKeyboardFunc(keyboard); // register a keyboard function
    glutTimerFunc(30, Timer, 1); // register a timer function
    glutMainLoop(); // enter in unending loop
    return 0;
}
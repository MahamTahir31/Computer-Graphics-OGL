

#include "Canvas.h"

#include <GL/glut.h>

#include <cmath>

Canvas::Canvas(int width, int height, const char* windowTitle)
{
    char* argv[1];  // dummy argument list for glutInit()
    char dummyString[8];
    argv[0] = dummyString;  // hook up the pointer
    int argc = 1;  // to satisfy glutInit()

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(20, 20);
    glutCreateWindow(windowTitle);  // open the screen window
    setWindow(0, (float)width, 0, (float)height);  // default world window
    setViewport(0, width, 0, height);  // default viewport
    CP.set(0.0f, 0.0f);  // initialize the CP to (0, 0)
}

void Canvas::setBackgroundColor(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
}// end setBackgroundColor

void Canvas::setColor(float r, float g, float b)
{
    glColor3f(r, g, b);
}//edn setColor

void Canvas::moveTo(float x, float y)
{
    CP.set(x, y);
}

void Canvas::moveTo(Point2 p) {
    CP.set(p.getX(), p.getY());
}

void Canvas::lineTo(float x, float y)
{
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.x, (GLfloat)CP.y);
    glVertex2f((GLfloat)x, (GLfloat)y);  // draw the line
    glEnd();
    CP.set(x, y);  // update the CP
    glFlush();
}

void Canvas::lineTo(Point2 p)
{
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
    glVertex2f((GLfloat)p.getX(), (GLfloat)p.getY());
    glEnd();
    CP.set(p.getX(), p.getY());
    glFlush();
}

void Canvas::setWindow(float l, float r, float b, float t)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
    window.set(l, r, b, t);
}

void Canvas::setViewport(int left, int right, int bottom, int top)
{
    // See page 87.
    const auto x = static_cast<GLint>(left);
    const auto y = static_cast<GLint>(bottom);
    const auto width = static_cast<GLint>(right - left);
    const auto height = static_cast<GLint>(top - bottom);
    glViewport(x, y, width, height);
}

IntRect Canvas::getViewport()
{
    return viewport;
}

RealRect Canvas::getWindow()
{
    return window;
}

float Canvas::getWindowAspectRatio()
{
    const auto width = window.getWidth();
    const auto height = window.getHeight();
    return width / height;
}

void Canvas::clearScreen()
{
    // TODO: check correctness of this implementation.
    glClear(GL_COLOR_BUFFER_BIT);
}

void Canvas::moveRel(float dx, float dy)
{
    CP.set(CP.x + dx, CP.y + dy);
}

void Canvas::lineRel(float dx, float dy)
{
    float x = CP.x + dx;
    float y = CP.y + dy;
    lineTo(x, y);
    CP.set(x, y);
}

void Canvas::turnTo(float angle) { CD = angle; }

void Canvas::initCT()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Canvas::scale2D(double sx, double sy)
{
    glMatrixMode(GL_MODELVIEW);
    glScaled(sx, sy, 1.0);
}

void Canvas::translate2D(double dx, double dy)
{
    glMatrixMode(GL_MODELVIEW);
    glTranslated(dx, dy, 0);
}

void Canvas::rotate2D(double angle)
{
    glMatrixMode(GL_MODELVIEW);
    glRotated(angle, 0.0, 0.0, 1.0);
}

void Canvas::pushCT()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
}

void Canvas::popCT()
{   // this mode is used for setting up the model and view transformations
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix(); // restore previously saved matrix state from the matrix stack
}

void Canvas::turn(float angle) { CD += angle; }

void Canvas::forward(float dist, int isVisible)
{
    const float RadPerDeg = 0.017453393;  // radians per degree
    float x = CP.x + dist * std::cos(RadPerDeg * CD);
    float y = CP.y + dist * std::sin(RadPerDeg * CD);
    if (isVisible)
        lineTo(x, y);
    else
        moveTo(x, y);
}
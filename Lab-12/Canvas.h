
#include <GL/glut.h>

class Point2
{
public:
    Point2() { x = y = 0.0f; } // constructor 1
    Point2(float xx, float yy) { x = xx; y = yy; } // constructor 2
    void set(float xx, float yy) { x = xx; y = yy; }
    float getX() { return x; }
    float getY() { return y; }
    void draw(void)
    {
        glBegin(GL_POINTS); // draw this point
        glVertex2f((GLfloat)x, (GLfloat)y);
        glEnd();
    }// end draw
public:
    float x, y;
}; // end class Point2

class IntRect
{
public:
    IntRect() { l = 0; r = 100; b = 0; t = 100; } // constructors
    IntRect(int left, int right, int bottom, int top)
    {
        l = left; r = right; b = bottom; t = top;
    } // constructors
    void set(int left, int right, int bottom, int top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    int getl() { return l; }
    int getr() { return r; }
    int getb() { return b; }
    int gett() { return t; }
    void draw(void); // draw this rectangle using OpenGL
private:
    int l, r, b, t;
}; //end class IntRect:


class RealRect
{
public:
    RealRect() { l = 0; r = 100; b = 0; t = 100; } // constructors
    RealRect(float left, float right, float bottom, float top)
    {
        l = left; r = right; b = bottom; t = top;
    } // constructors
    void set(float left, float right, float bottom, float top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    float getl() { return l; }
    float getr() { return r; }
    float getb() { return b; }
    float gett() { return t; }
    float getWidth() { return r - l; }
    float getHeight() { return t - b; }
    void draw(void); // draw this rectangle using OpenGL
private:
    float l, r, b, t;
}; //end class RealRect:


class Canvas {
public:
    Canvas(int width, int height, const char* windowTitle);
    void setWindow(float l, float r, float b, float t);
    void setViewport(int l, int r, int b, int t);
    IntRect getViewport();
    RealRect getWindow();
    float getWindowAspectRatio();
    void clearScreen();
    void setBackgroundColor(float r, float g, float b);
    void setColor(float r, float g, float b);
    void lineTo(float x, float y);
    void lineTo(Point2 p);
    void moveTo(float x, float y);
    void moveTo(Point2 p);
    void moveRel(float dx, float dy);
    void lineRel(float dx, float dy);

    // Turtle movement.
    void turnTo(float angle);
    void turn(float angle);
    void forward(float dist, int isVisible);

    void initCT();
    void scale2D(double sx, double sy);
    void translate2D(double dx, double dy);
    void rotate2D(double angle);

    void pushCT();
    void popCT();

private:
    Point2 CP;  // current position in the world
    float CD;  // current direction
    IntRect viewport;
    RealRect window;
    // others later
};
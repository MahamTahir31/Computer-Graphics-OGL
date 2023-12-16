#include <iostream>
#include <cmath>
#include <GL/glut.h>

class Canvas {
public:
    int window[4];
    int viewport[4];
    float color[3];
    float cp[2];
    float cd;


    Canvas(int width, int height, const char* window_title) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(width, height);
        glutInitWindowPosition(0, 0);
        glutCreateWindow(window_title);

        window[0] = 0;
        window[1] = width;
        window[2] = 0;
        window[3] = height;

        viewport[0] = 0;
        viewport[1] = width;
        viewport[2] = 0;
        viewport[3] = height;

        color[0] = color[1] = color[2] = 0.0f;

        cp[0] = cp[1] = 0.0f;
        cd = 0.0f;

        set_window(0, width, 0, height);
        set_viewport(0, width, 0, height);
    }

    float window_aspect() {
        return static_cast<float>(window[1] - window[0]) / (window[3] - window[2]);
    }

    static void swap() {
        glutSwapBuffers();
    }

    static void clear_screen() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    static void set_bc(float r, float g, float b) {
        glClearColor(r, g, b, 0.0f);
    }

    static void thick(float t) {
        glLineWidth(t);
    }

    void set_color(float r, float g, float b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
        glColor3f(r, g, b);
    }

    void set_window(int l, int r, int b, int t) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(l, r, b, t);
        window[0] = l;
        window[1] = r;
        window[2] = b;
        window[3] = t;
    }

    void set_viewport(int left, int right, int bottom, int top) {
        glViewport(left, bottom, right - left, top - bottom);
        viewport[0] = left;
        viewport[1] = right;
        viewport[2] = bottom;
        viewport[3] = top;
    }

    void line_to(float x, float y) {
        glBegin(GL_LINES);
        glVertex2f(cp[0], cp[1]);
        glVertex2f(x, y);
        glEnd();
        glFlush();
        cp[0] = x;
        cp[1] = y;
    }

    void line_rel(float dx, float dy) {
        line_to(cp[0] + dx, cp[1] + dy);
    }

    void turn(float ang) {
        cd += ang;
    }

    void forward(float dist, bool isVisible = true) {
        float rad_per_deg = 0.017453393f;
        float x = cp[0] + (dist * cos(rad_per_deg * cd));
        float y = cp[1] + (dist * sin(rad_per_deg * cd));
        if (isVisible) {
            line_to(x, y);
        }
        else {
            cp[0] = x;
            cp[1] = y;
        }
    }

    void polyspiral(float length, float angle, float incr, int num) {
        for (int i = 0; i < num; ++i) {
            forward(length, true);
            turn(angle);
            length += incr;
        }
    }
};







int main(int argc, char** argv) {
    glutInit(&argc, argv);
    Canvas spiral_cvs(640, 480, "Implementing Polyspiral");
    spiral_cvs.set_bc(1.0f, 1.0f, 1.0f);
    spiral_cvs.clear_screen();
    spiral_cvs.set_color(1.0f, 0.0f, 0.0f);
    spiral_cvs.cp[0] = 170;
    spiral_cvs.cp[1] = 350;
    spiral_cvs.cd = 0;
    spiral_cvs.polyspiral(1, 60, 1, 120);
    spiral_cvs.cp[0] = 480;
    spiral_cvs.cp[1] = 360;
    spiral_cvs.cd = 5;
    spiral_cvs.set_color(0.0f, 0.0f, 1.0f);
    spiral_cvs.polyspiral(1, 89.5, 1, 190);
    spiral_cvs.cp[0] = 150;
    spiral_cvs.cp[1] = 100;
    spiral_cvs.cd = 0;
    spiral_cvs.set_color(1.0f, 1.0f, 0.0f);
    spiral_cvs.polyspiral(1, -144, 1, 170);
    spiral_cvs.cp[0] = 480;
    spiral_cvs.cp[1] = 130;
    spiral_cvs.cd = 0;
    spiral_cvs.set_color(0.0f, 0.0f, 0.0f);
    spiral_cvs.polyspiral(1, 170, 1, 250);
    spiral_cvs.swap();
    spiral_cvs.set_bc(1.0f, 1.0f, 1.0f);
    glutMainLoop();

    return 0;
}
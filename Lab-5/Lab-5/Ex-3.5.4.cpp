//#include <GL/glut.h>
//#include <cmath>
//
//class Canvas {
//public:
//    Canvas(int width, int height, const char* windowTitle) {
//        glutInitWindowSize(width, height);
//        glutInitWindowPosition(0, 0);
//        glutCreateWindow(windowTitle);
//        window[0] = 0;
//        window[1] = width;
//        window[2] = 0;
//        window[3] = height;
//        viewport[0] = 0;
//        viewport[1] = width;
//        viewport[2] = 0;
//        viewport[3] = height;
//        color[0] = 0.0f;
//        color[1] = 0.0f;
//        color[2] = 0.0f;
//        cp[0] = 0.0f;
//        cp[1] = 0.0f;
//        cd = 0.0;
//        set_window(0, width, 0, height);
//        set_viewport(0, width, 0, height);
//    }
//
//    double window_aspect() {
//        return (window[1] - window[0]) / (window[3] - window[2]);
//    }
//
//    static void swap() {
//        glutSwapBuffers();
//    }
//
//    static void clear_screen() {
//        glClear(GL_COLOR_BUFFER_BIT);
//    }
//
//    static void set_bc(double r, double g, double b) {
//        glClearColor(r, g, b, 0.0);
//    }
//    void thick(float t) {
//        glLineWidth(t);
//    }
//
//    void set_color(double r, double g, double b) {
//        color[0] = r;
//        color[1] = g;
//        color[2] = b;
//        glColor3f(r, g, b);
//    }
//
//    void set_window(double l, double r, double b, double t) {
//        glMatrixMode(GL_PROJECTION);
//        glLoadIdentity();
//        gluOrtho2D(l, r, b, t);
//        window[0] = l;
//        window[1] = r;
//        window[2] = b;
//        window[3] = t;
//    }
//
//    void set_viewport(int left, int right, int bottom, int top) {
//        glViewport(left, bottom, right - left, top - bottom);
//        viewport[0] = left;
//        viewport[1] = right;
//        viewport[2] = bottom;
//        viewport[3] = top;
//    }
//
//    void line_to(double x, double y) {
//        glBegin(GL_LINES);
//        glVertex2f(cp[0], cp[1]);
//        glVertex2f(x, y);
//        glEnd();
//        glFlush();
//        cp[0] = x;
//        cp[1] = y;
//    }
//
//    void line_rel(double dx, double dy) {
//        line_to(cp[0] + dx, cp[1] + dy);
//    }
//
//    void turn(double ang) {
//        cd += ang;
//    }
//
//    void forward(double dist, bool isVisible = true) {
//        double rad_per_deg = 0.017453393;
//        double x = cp[0] + (dist * cos(rad_per_deg * cd));
//        double y = cp[1] + (dist * sin(rad_per_deg * cd));
//        if (isVisible) {
//            line_to(x, y);
//        }
//        else {
//            cp[0] = x;
//            cp[1] = y;
//        }
//    }
//
//    void meander(double length, double angle, double space, int num, float thick) {
//        glLineWidth(thick);
//        for (int i = 0; i < num; ++i) {
//            forward(length, true);
//            turn(angle);
//            forward(4 * space, true);
//            turn(angle);
//            forward(4 * space, true);
//            turn(angle);
//            forward(2 * space, true);
//            turn(-angle);
//            forward(4 * space, true);
//            turn(-angle);
//            forward(4 * space, true);
//            turn(-angle);
//            forward(length, true);
//            turn(-angle);
//            forward(length - (4 * space), true);
//            turn(angle);
//        }
//    }
//
//
//
//    double window[4];
//    double viewport[4];
//    double color[3];
//    double cp[2];
//    double cd;
//};
//
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    Canvas cvs(640, 480, "Drawing meanders");
//
//    cvs.set_bc(1.0, 1.0, 1.0);
//    cvs.clear_screen();
//    cvs.set_color(0, 0, 0);
//    cvs.cp[0] = 50;
//    cvs.cp[1] = 300;
//    cvs.cd = 0;
//    cvs.meander(20, 90, 2, 20, 2.0f);
//    cvs.swap();
//
//    cvs.set_window(0, 640, 0, 480);
//    cvs.set_viewport(0, 640, 0, 480);
//
//    glutMainLoop();
//    return 0;
//}
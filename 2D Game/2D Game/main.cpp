#include <windows.h>
#include <GL/glut.h>
//#include "bits/stdc++.h"
#include "testlib.h" //Download this header file from https://raw.githubusercontent.com/MikeMirzayanov/testlib/master/testlib.h
using namespace std;

string Title = "CLASH OF CARS";

bool collide;
bool game_over;
long long score;

const double EPS = 1e-6;

const double Ortho_left = -24;
const double Ortho_right = 24;
const double Ortho_top = 32;
const double Ortho_bottom = 0;

const double Road_left = -12;
const double Road_right = 13;
const double Road_top = 32;
const double Road_bottom = 0;

class Point {
public:
    double x, y, z;
    Point() { x = y = z = 0; }
    Point(double _x, double _y) { x = _x, y = _y, z = 0; }
    Point(double _x, double _y, double _z) { x = _x, y = _y, z = _z; }
};


class Color {
public:
    double r, g, b;
    Color() { update(); }
    Color(double _r, double _g, double _b) { r = _r, g = _g, b = _b; }
    void update() { r = rnd.next(1.0), g = rnd.next(1.0), b = rnd.next(1.0); }
};

vector<int> Lanes({ -11, -7, -3, 1, 5, 9 });
class Car {
public:
    Color color, tolor;
    double height = 4.5, width = 3, speed, x, y; bool forward;
    Car() { renovate(); }
    Car(int _x, int _y, double s) {
        x = _x, y = _y; speed = s;
        color = { 1,0,0 }; tolor = { 0,0,0 }; forward = 1;
    }

    void go_left() { x = max(x - 4, Road_left + 1); }
    void go_right() { x = min(x + 4, Road_right - width - 1); }
    void go_down() {
        if (y < 0 - height) renovate(), score++;
        else  y -= speed;
    }
    void go_down(int f) { { y = max(y - 1, Road_bottom);  } }
    void go_up() { y = min(y + 1, Road_top - width); }

    void renovate() {
        x = rnd.any(Lanes), y = Road_top;
        speed = rnd.next(0.1, .2);
        color.update(), tolor.update();
    }

    void update() {
        glPushMatrix();
        glColor3f(tolor.r, tolor.g, tolor.b);
        if (!forward) {
            glRectd(x + 0, y + 2, x + 3, y + 5);

            glColor3f(color.r, color.g, color.b);
            glRectd(.75 + x, 2.75 + y, 2.25 + x, 4.25 + y);

            glBegin(GL_LINES);
            glVertex2d(x + 0, y + 2);
            glVertex2d(x + 1, y + 3);
            glVertex2d(x + 0, y + 5);
            glVertex2d(x + 1, y + 4);
            glVertex2d(x + 2, y + 4);
            glVertex2d(x + 3, y + 5);
            glVertex2d(x + 2, y + 3);
            glVertex2d(x + 3, y + 2);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2d(x + 0.25, y + 5.5);
            glVertex2d(x + 2.75, y + 5.5);
            glVertex2d(x + 3, y + 5);
            glVertex2d(x + 0, y + 5);
            glVertex2d(x + 0, y + 2);
            glVertex2d(x + 3, y + 2);
            glVertex2d(x + 2.6, y);
            glVertex2d(x + 0.4, y);
            glEnd();

            glPointSize(10);
            glBegin(GL_POINTS);
            glVertex2d(2.75 + x, y + 1);
            glVertex2d(0.25 + x, y + 1);
            glEnd();
            glPopMatrix();
            return;
        }
        glRectd(x + 0, y + .5, x + 3, y + 3.5);

        glColor3f(color.r, color.g, color.b);
        glRectd(.75 + x, 1.25 + y, 2.25 + x, 2.75 + y);

        glBegin(GL_LINES);
        glVertex2d(x + 0, y + .5);
        glVertex2d(x + 1, y + 1.5);
        glVertex2d(x + 0, y + 3.5);
        glVertex2d(x + 1, y + 2.5);
        glVertex2d(x + 2, y + 2.5);
        glVertex2d(x + 3, y + 3.5);
        glVertex2d(x + 2, y + 1.5);
        glVertex2d(x + 3, y + .5);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2d(x + 0.25, y);
        glVertex2d(x + 2.75, y);
        glVertex2d(x + 3, y + 0.5);
        glVertex2d(x + 0, y + 0.5);
        glVertex2d(x + 0, y + 3.5);
        glVertex2d(x + 3, y + 3.5);
        glVertex2d(x + 2.6, y + 5.5);
        glVertex2d(x + 0.4, y + 5.5);
        glEnd();

        glPointSize(10);
        glBegin(GL_POINTS);
        glVertex2d(2.75 + x, y + 4.5);
        glVertex2d(0.25 + x, y + 4.5);
        glEnd();
        glPopMatrix();
    }
}PlayerCar(1, 0.897, 0.1);

vector<Car>Cars(5);

void drawstring(double x, double y, double z, string s) {
    glRasterPos3f(x, y, z);
    for (auto c : s)glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}

class Road { // FOR ROAD
public:
    vector<double> Dash;
    Road() { for (int i = 0; i <= Road_top + 4; i += 4) Dash.push_back(i); }
    void update() {
        glColor3d(.25, .25, .25);
        glRectd(Road_left, Road_bottom, Road_right, Road_top);

        glColor3d(1, 1, 0.25);
        glRectd(Road_left + 0.5, Road_bottom, Road_left + 1, Road_top);
        glRectd(Road_left + 8, Road_bottom, Road_left + 8.5, Road_top);
        glRectd(Road_left + 16, Road_bottom, Road_left + 16.5, Road_top);
        glRectd(Road_left + 24, Road_bottom, Road_left + 24.5, Road_top);

        glColor3d(0.925, 0.925, 0.925); // RGB values for a light grayish-white color like snow

        for (auto& d : Dash) {
            d -= PlayerCar.speed; if (d < 0)d = Road_top + 4;
            glRectd(Road_left + 4, d, Road_left + 4.5, d - 2);
            glRectd(Road_left + 12, d, Road_left + 12.5, d - 2);
            glRectd(Road_left + 20, d, Road_left + 20.5, d - 2);
        }
    }
}Roads;


class Tree {  // TO DRAW TREE
public:
    double x, y;
    Tree() { renovate(); }
    void renovate() {
        x = (rnd.next(2) ? rnd.next(Ortho_left, Road_left) : rnd.next(Road_right, Ortho_right));
        y = rnd.next(Ortho_top, Ortho_top * 2);
    }
    void update() {
        y -= PlayerCar.speed;
        if (y <= -6)renovate();

        glColor3d(0.44, 0.33, 0.23);
        glRectd(-0.5 + x, 0 + y, 0.5 + x, 4 + y);

        glColor3d(.13, 1, .13);
        glBegin(GL_TRIANGLES);
        glVertex2d(0 + x, 5 + y);
        glVertex2d(-1 + x, 4 + y);
        glVertex2d(1 + x, 4 + y);
        glVertex2d(0 + x, 4.4 + y);
        glVertex2d(-2 + x, 3 + y);
        glVertex2d(2 + x, 3 + y);
        glVertex2d(0 + x, 3.8 + y);
        glVertex2d(-2.5 + x, 2 + y);
        glVertex2d(2.5 + x, 2 + y);
        glEnd();
    }
}; vector<Tree>Trees(30);

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    Roads.update();
    PlayerCar.update();
    for (auto& car : Cars) { if (!collide)car.go_down(); car.update(); }
    sort(Trees.begin(), Trees.end(), [](auto& a, auto& b) {return a.y > b.y; });
    for (auto& tree : Trees)tree.update();
    if (game_over) {
        glColor3d(.7, .7, .7); glRectd(-8.3, 17, 13.5, 22);
        glColor3d(0, 0, 1), drawstring(-4, 21, 0, "OOPS! GAME OVER");
        glColor3d(0, 0, 1), drawstring(-3, 19.5, 0, "Score: " + toString(score));
        glColor3d(1, 0, 0), drawstring(-7, 18, 0, "Press R to Play Again and E to exit");
    }
    else {
        glColor3d(.7, .7, .7); glRectd(Ortho_left, Ortho_top - 1, Ortho_left + 10, Ortho_top - 3);
        glColor3d(0, 0, 1), drawstring(Ortho_left + 2, Ortho_top - 2, 0, "Score: " + toString(score));
    }
    glutSwapBuffers();
}

boolean rectRect(double r1x, double r1y, double r2x, double r2y) {
    double r1w = 3, r1h = 5.5, r2w = 3, r2h = 5.5;
    if (r1x + r1w >= r2x + EPS && r1x + EPS <= r2x + r2w && r1y + r1h >= r2y + EPS && r1y + EPS <= r2y + r2h)return true;
    return false;
}

bool collision() {
    for (auto c : Cars)if (rectRect(c.x, c.y, PlayerCar.x, PlayerCar.y))return true;
    return false;
}

void timer(int v) { // SET SPEED OF CAR
    if (collision()) {
        game_over = 1;
        collide = 1;
        glutPostRedisplay();
        glutSpecialFunc(NULL);
        return;
    }
    glutPostRedisplay();
    glutTimerFunc(15, timer, v);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case  GLUT_KEY_LEFT:
        PlayerCar.go_left();
        break;
    case  GLUT_KEY_RIGHT:
        PlayerCar.go_right();
        break;
    case  GLUT_KEY_UP:
        PlayerCar.go_up();
        break;
    case  GLUT_KEY_DOWN:
        PlayerCar.go_down(1);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void Keys(unsigned char key, int x, int y) { // RESTART THE GAME OR EXIT THE GAME
    if ('r' == key or 'R' == key) {
        for (auto& car : Cars)car.renovate();
        score = game_over = collide = 0;
        glutSpecialFunc(specialKeys);
        glutPostRedisplay();
        glutTimerFunc(10, timer, 0);
    }
    else if (key == 'e' or key == 'E')exit(0);
}

void reshape(GLsizei width, GLsizei height) {
    glClearColor(0.925, 0.925, 0.925, 1.0); // RGB values for a light grayish-white color like snow
    // Reshape Window
    glViewport(0, 0, width, height);
    glLoadIdentity();

    GLdouble aspect = (GLdouble)width / (GLdouble)max(height, 1);
    if (width >= height) glOrtho(Ortho_left * aspect, Ortho_right * aspect, Ortho_bottom, Ortho_top, 0, Ortho_right);
    else glOrtho(Ortho_left, Ortho_right, Ortho_bottom / aspect, Ortho_top / aspect, 0, Ortho_right);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(400, 20);
    glutCreateWindow(Title.c_str());
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(Keys);
    glutReshapeFunc(reshape);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();

    return 0;
}

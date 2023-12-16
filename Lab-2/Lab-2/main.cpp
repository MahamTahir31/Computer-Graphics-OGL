#include <iostream>
#include <GL/glut.h>
#include <cmath>
void drawSky() {
    glBegin(GL_QUADS); // used as a pair with glEnd(), it encloses a set of vertices that define the shape to be rendered.
    glColor3f(0.6f, 0.8f, 1.0f); // Light Blue Color (daytime sky)
    glVertex2f(-1.0f, 1.0f);     // Top-left
    glVertex2f(1.0f, 1.0f);      // Top-right
    glVertex2f(1.0f, 0.0f);      // Bottom-right
    glVertex2f(-1.0f, 0.0f);     // Bottom-left
    glEnd();
}
void drawSun() {
    glBegin(GL_TRIANGLE_FAN); // initiates the definition of a sequence of vertices that form a triangle fan
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow Color (sun)
    float xCenter = -0.7f; // Move the sun to the left side of the screen
    float yCenter = 0.7f;  // Move the sun to the upward 
    float radius = 0.15f; // set radius of circle
    int numSegments = 100;
    glVertex2f(xCenter, yCenter);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = xCenter + radius * cos(angle);
        float y = yCenter + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawGrass() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.0f); // Dark Green Color
    glVertex2f(-1.0f, 0.0f);    // Bottom-left
    glVertex2f(1.0f, 0.0f);     // Bottom-right
    glVertex2f(1.0f, -1.0f);    // Top-right
    glVertex2f(-1.0f, -1.0f);   // Top-left
    glEnd();
}

void drawHouse() {
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.6f, 0.4f); // Light Brown Color (main walls)
    glVertex2f(-0.4f, -0.7f);    // Lower the position of the house
    glVertex2f(0.4f, -0.7f);     // Lower the position of the house
    glVertex2f(0.4f, -0.2f);     // Lower the position of the house
    glVertex2f(-0.4f, -0.2f);    // Lower the position of the house
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.2f, 0.1f); // Dark Red Color (roof)
    glVertex2f(-0.5f, -0.2f);    // Lower the position of the house
    glVertex2f(0.5f, -0.2f);     // Lower the position of the house
    glVertex2f(0.0f, 0.2f);      // Lower the position of the house
    glEnd();

    // Draw the stylish door of the house
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.2f, 0.1f); // Dark Brown Color
    glVertex2f(-0.05f, -0.7f);   // Lower the position of the house
    glVertex2f(0.05f, -0.7f);    // Lower the position of the house
    glVertex2f(0.05f, -0.45f);   // Lower the position of the house
    glVertex2f(-0.05f, -0.45f);  // Lower the position of the house
    glEnd();


    // Draw details on the walls
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3f(0.6f, 0.6f, 0.6f); // Light Gray Color
    glVertex2f(-0.25f, -0.2f);   // Vertical line left
    glVertex2f(-0.25f, -0.7f);
    glVertex2f(0.25f, -0.2f);    // Vertical line right
    glVertex2f(0.25f, -0.7f);
    glVertex2f(-0.4f, -0.45f);   // Horizontal line top
    glVertex2f(0.4f, -0.45f);
    glEnd();
}

void drawCloud(float x, float y) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f); // White Color (cloud)
    float radius = 0.08f;
    int numSegments = 100;
    glVertex2f(x, y);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(numSegments);
        float xCloud = x + radius * cos(angle);
        float yCloud = y + radius * sin(angle);
        glVertex2f(xCloud, yCloud);
    }
    glEnd();
}

void drawCar() {
    // Car body
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.2f, 0.2f); // Red Color (car body)
    glVertex2f(0.6f, -0.7f);    // Bottom-left
    glVertex2f(0.9f, -0.7f);    // Bottom-right
    glVertex2f(0.85f, -0.5f);   // Top-right
    glVertex2f(0.65f, -0.5f);   // Top-left
    glEnd();

    // Car roof
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f); // Gray Color (car roof)
    glVertex2f(0.65f, -0.5f);   // Bottom-left
    glVertex2f(0.85f, -0.5f);   // Bottom-right
    glVertex2f(0.82f, -0.4f);   // Top-right
    glVertex2f(0.68f, -0.4f);   // Top-left
    glEnd();

    // Car windows
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f); // Black Color (car windows)
    glVertex2f(0.67f, -0.5f);   // Bottom-left window
    glVertex2f(0.83f, -0.5f);   // Bottom-right window
    glVertex2f(0.80f, -0.42f);  // Top-right window
    glVertex2f(0.70f, -0.42f);  // Top-left window
    glEnd();

    // Car wheels
    glColor3f(0.2f, 0.2f, 0.2f); // Black Color (car wheels)
    float wheelRadius = 0.08f; // wheel radius
    int numSegments = 100; 
    float wheel1_x = 0.68f;
    float wheel2_x = 0.82f;
    float wheel_y = -0.7f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(wheel1_x, wheel_y);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = wheel1_x + wheelRadius * cos(angle);
        float y = wheel_y + wheelRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(wheel2_x, wheel_y);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = wheel2_x + wheelRadius * cos(angle);
        float y = wheel_y + wheelRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6f, 0.8f, 1.0f, 0.0f); // Light Blue Color (daytime sky)

    drawSky(); // user defined function for drawing sky
    drawSun(); // user defined function for drawing sun 
    drawGrass(); // user defined function for drawing grass

    drawHouse(); // user defined function for drawing house

    // user defined function for drawing 3 clouds
    drawCloud(-0.7f, 0.8f); 
    drawCloud(-0.6f, 0.85f);
    drawCloud(-0.55f, 0.8f);

    drawCar(); // user defined function for drawing car

    glFlush(); // Forces any incomplete rendering commands to be processed.

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Daytime Scenery with a Luxurious House and a Tree");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 800
#define WINDOW_TITLE "OpenGL Application"
#define TIMER_MS 25

void cleanup()
{
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '\r': // Enter key
        break;
    case 27: // Escape key
        cleanup();
        exit(0);
    }
}

void handleKeypressReleased(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '\r': // Enter key
        break;
    case 27: // Escape key
        cleanup();
        exit(0);
    }
}

void handleSpecialKeypress(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        break;
    case GLUT_KEY_RIGHT:
        break;
    }
}

void handleSpecialKeyReleased(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        break;
    case GLUT_KEY_RIGHT:
        break;
    }
}

void initRendering()
{
    // Background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // OpenGL hints
    glEnable(GL_DEPTH_TEST);                           // Enable 3D layering
    glEnable(GL_COLOR_MATERIAL);                       // Enable Better coloring
    glEnable(GL_LIGHTING);                             // Enable Lighting
    glEnable(GL_NORMALIZE);                            // Enable Normalizing
    glEnable(GL_CULL_FACE);                            // Enable Cull face effect
    glShadeModel(GL_SMOOTH);                           // Set Shading model to (Smooth)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set the blend function
}

void handleResize(int new_screen_width, int new_screen_height)
{
    glViewport(0, 0, new_screen_width, new_screen_height);               // Tell OpenGL how to convert from coordinates to pixel values
    glMatrixMode(GL_PROJECTION);                                         // Switch to setting the camera perspective
    glLoadIdentity();                                                    // Reset the camera
    gluPerspective(45.0,                                                 // The camera angle
                   (double)new_screen_width / (double)new_screen_height, // The width-to-height ratio
                   1.0,                                                  // The near z clipping coordinate
                   1000.0);                                              // The far z clipping coordinate
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear information from last draw
    glMatrixMode(GL_MODELVIEW);                         // Switch to the drawing perspective
    glLoadIdentity();                                   // Reset the drawing perspective

    // Code here
    glTranslated(0, 0, -5);

    glBegin(GL_TRIANGLES);
    glColor3d(0.5, 0.8, 0.2);
    glVertex2d(-0.5, -0.5);
    glVertex2d(0.5, -0.5);
    glVertex2d(0.0, 0.5);
    glEnd();

    glEnd();

    glutSwapBuffers();
}

void update(int value)
{
    // Code here

    glutPostRedisplay();
    glutTimerFunc(TIMER_MS, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

    glutCreateWindow(WINDOW_TITLE);
    initRendering();

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeypressReleased);
    glutSpecialFunc(handleSpecialKeypress);
    glutSpecialUpFunc(handleSpecialKeyReleased);
    glutReshapeFunc(handleResize);
    glutTimerFunc(TIMER_MS, update, 0);

    glutMainLoop();
    return 0;
}

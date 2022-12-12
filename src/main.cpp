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

#define SIMPLEBMP_OPENGL
#include "simplebmp.h"

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

GLuint textureId;
void initRendering()
{
    // Background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // OpenGL hints
    glEnable(GL_DEPTH_TEST);                           // Enable 3D layering
    glEnable(GL_COLOR_MATERIAL);                       // Enable Better coloring
    glEnable(GL_LIGHTING);                             // Enable Lighting
    glEnable(GL_LIGHT0);                               // Enable the first light
    glEnable(GL_NORMALIZE);                            // Enable Normalizing
    glEnable(GL_CULL_FACE);                            // Enable Cull face effect
    glEnable(GL_TEXTURE_2D);                           // Enable textures
    glShadeModel(GL_SMOOTH);                           // Set Shading model to (Smooth)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set the blend function

    SimpleBMP bmp;
    int err = bmp.load("./assets/vtr.bmp");
    if (err)
        std::cout << "ERR" << std::endl;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    bmp.glTexImage2D();
    bmp.destroy();
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

    GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    GLfloat directedLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat directedLightPos[] = {-10.0f, 15.0f, 20.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
    glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);

    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);


    glBegin(GL_TRIANGLES);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.5f, -2.5f, -8.5f);
    glTexCoord2f(10.0f, 0.0f);
    glVertex3f(2.5f, -2.5f, -8.5f);
    glTexCoord2f(5.0f, 5.0f);
    glVertex3f(0.0f, 2.5f, -8.5f);
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
    glutReshapeFunc(handleResize);
    glutTimerFunc(TIMER_MS, update, 0);

    glutMainLoop();
    return 0;
}

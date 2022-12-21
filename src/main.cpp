#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 800
#define WINDOW_TITLE "OpenGL Application"
#define TIMER_MS 1000.0f / 60.0f

#include "Game.h"

// camera cam;
Camera cam;

Skybox skybox;

Train train;

void cleanup()
{
}

void handleKeypress(unsigned char key, int xx, int yy)
{
    GLfloat speed = 1.0f, rotate_speed = 1.0f;

    switch (key)
    {
    case 'A':
    case 'a':
        cam.MoveLeft(speed);
        break;
    case 'D':
    case 'd':
        cam.MoveRight(speed);
        break;
    case 'W':
    case 'w':
        cam.MoveForward(speed);
        break;
    case 'S':
    case 's':
        cam.MoveBackward(speed);
        break;
    case 'Q':
    case 'q':
        cam.RotateY(rotate_speed);
        break;
    case 'E':
    case 'e':
        cam.RotateY(-rotate_speed);
        break;
    case '1':
        cam.RotateX(-rotate_speed);
        break;
    case '3':
        cam.RotateX(rotate_speed);
        break;
    case '2':
        cam.MoveUpward(speed);
        break;
    case '4':
        cam.MoveDownward(speed);
        break;
    case 'O':
    case 'o':
        train.open_front_door();
        break;
    case 'P':
    case 'p':
        train.close_front_door();
        break;
    case 'N':
    case 'n':
        train.open_back_door();
        break;
    case 'M':
    case 'm':
        train.close_back_door();
        break;
    case 27: // Escape key
        cleanup();
        exit(0);
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
    glShadeModel(GL_SMOOTH);                           // Set Shading model to (Smooth)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set the blend function
    glutSetCursor(GLUT_CURSOR_NONE);                   // Hide the cursor

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    cam = Camera();
    skybox = Skybox();
    train = Train();

    skybox.load_resources();
    train.load_resources();
}

void handleResize(int new_screen_width, int new_screen_height)
{
    glViewport(0, 0, new_screen_width, new_screen_height);               // Tell OpenGL how to convert from coordinates to pixel values
    glMatrixMode(GL_PROJECTION);                                         // Switch to setting the camera perspective
    glLoadIdentity();                                                    // Reset the camera
    gluPerspective(45.0,                                                 // The camera angle
                   (double)new_screen_width / (double)new_screen_height, // The width-to-height ratio
                   1.0,                                                  // The near z clipping coordinate
                   20000.0);                                             // The far z clipping coordinate
    glutPostRedisplay();
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear information from last draw
    glMatrixMode(GL_MODELVIEW);                         // Switch to the drawing perspective
    glLoadIdentity();                                   // Reset the drawing perspective

    GLfloat ambientLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    cam.render();
    glEnable(GL_CULL_FACE);
    skybox.render();
    glDisable(GL_CULL_FACE);
    train.render();
    glColor3d(1, 1, 0);
    // glTranslated(0, 0, -88);
    // glRotated(180, 0, 1, 0);
    // train.render();

    // // Ball
    // glutSolidSphere(5, 100, 100);

    // // Cube
    // glutSolidCube(3);

    // // Cube with textures
    // // same as skybox code

    // // Torus
    // glutSolidTorus(3, 7, 100, 100);

    // // Teapot
    // glutSolidTeapot(5);

    // // Cone
    // glutSolidCone(3, 5, 100, 100);

    // Table

    // Chair

    // Drawing

    // Pyramid

    // Toy Car

    // Pencil

    // Color Pencil

    // Swing

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
    glutFullScreen();
    glutReshapeFunc(handleResize);
    glutTimerFunc(TIMER_MS, update, 0);

    glutMainLoop();
    return 0;
}

#include "Cabin.h"

Cabin::Cabin(/* args */)
{
}

Cabin::~Cabin()
{
}

void Cabin::load_resources()
{
    for (GLuint i = 0; i < PIECES_COUNT; i++)
    {
        SimpleBMP bmp;
        int err = bmp.load(textures_file_paths[i]);
        if (err)
        {
            Log("load error");
            exit(err);
        }
        glGenTextures(1, &textures_ids[i]);
        glBindTexture(GL_TEXTURE_2D, textures_ids[i]);
        bmp.glTexImage2D();
        bmp.destroy();
    }
}

void Cabin::bind_texture(GLuint face)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, textures_ids[face]);
}

void Cabin::unbind_texture()
{
    glDisable(GL_TEXTURE_2D);
    glColor3d(1, 1, 1);
}

void Cabin::square()
{
    bind_texture(WP);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-8, -8, 0);
    glTexCoord2d(1, 0);
    glVertex3d(8, -8, 0);
    glTexCoord2d(1, 1);
    glVertex3d(8, 8, 0);
    glTexCoord2d(0, 1);
    glVertex3d(-8, 8, 0);
    glEnd();
    unbind_texture();
}

void Cabin::door()
{
    bind_texture(DOOR);
    glBegin(GL_QUADS);

    glTexCoord2d(1, 0);
    glVertex3d(2, -2, 0);
    glTexCoord2d(0, 0);
    glVertex3d(-2, -2, 0);
    glTexCoord2d(0, 1);
    glVertex3d(-2, 2, 0);
    glTexCoord2d(1, 1);
    glVertex3d(2, 2, 0);
    glEnd();
    unbind_texture();
}

void Cabin::roof()
{
    bind_texture(ROOF);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-8, -8, 0);
    glTexCoord2d(1, 0);
    glVertex3d(8, -8, 0);
    glTexCoord2d(1, 1);
    glVertex3d(8, 8, 0);
    glTexCoord2d(0, 1);
    glVertex3d(-8, 8, 0);
    glEnd();
    unbind_texture();
}

void Cabin::open_front_door()
{
    if (d1 < 10)
        d1 += 0.5;
}

void Cabin::close_front_door()
{
    if (d1 > 4)
        d1 -= 0.5;
}

void Cabin::open_back_door()
{
    if (d2 < 10)
        d2 += 0.5;
}

void Cabin::close_back_door()
{
    if (d2 > 4)
        d2 -= 0.5;
}

void Cabin::table()
{
    glPushMatrix();
    glColor3d(45 / 255.0, 45 / 255.0, 43 / 255.0);

    glPushMatrix();
    glScalef(2, 0.1, 2);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.95, -0.5, -0.95);
    glScalef(0.1, 1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.95, -0.5, 0.95);
    glScalef(0.1, 1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.95, -0.5, -0.95);
    glScalef(0.1, 1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.95, -0.5, 0.95);
    glScalef(0.1, 1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
}

void Cabin::chair()
{
    glPushMatrix();
    glColor3d(45 / 255.0, 45 / 255.0, 43 / 255.0);

    glBegin(GL_QUADS);

    // Front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(2.0f, -0.2f, 2.0f);
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);

    // Right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(2.0f, -0.2f, 2.0f);

    // Back
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);

    // Left
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);

    // top
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);

    // bottom
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);

    // table front leg
    //  front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.8f, -0.2f, 1.6f);
    glVertex3f(1.4f, -0.2f, 1.6f);
    glVertex3f(1.4f, -3.0f, 1.6f);
    glVertex3f(1.8f, -3.0f, 1.6f);

    // back
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(1.8f, -0.2f, 1.2f);
    glVertex3f(1.4f, -0.2f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.2f);

    // right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.8f, -0.2f, 1.6f);
    glVertex3f(1.8f, -0.2f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.6f);

    // left
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(1.4f, -0.2f, 1.6f);
    glVertex3f(1.4f, -0.2f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.6f);

    // back leg back
    //  front
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(1.8f, -0.2f, -1.2f);
    glVertex3f(1.4f, -0.2f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.2f);

    // back
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(1.8f, -0.2f, -1.6f);
    glVertex3f(1.4f, -0.2f, -1.6f);
    glVertex3f(1.4f, -3.0f, -1.6f);
    glVertex3f(1.8f, -3.0f, -1.6f);

    // right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.8f, -0.2f, -1.6f);
    glVertex3f(1.8f, -0.2f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.6f);

    // left
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.4f, -0.2f, -1.6f);
    glVertex3f(1.4f, -0.2f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.6f);

    // leg left front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.8f, -0.2f, 1.6f);
    glVertex3f(-1.4f, -0.2f, 1.6f);
    glVertex3f(-1.4f, -3.0f, 1.6f);
    glVertex3f(-1.8f, -3.0f, 1.6f);

    // back
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-1.8f, -0.2f, 1.2f);
    glVertex3f(-1.4f, -0.2f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.2f);

    // right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, -0.2f, 1.6f);
    glVertex3f(-1.8f, -0.2f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.6f);

    // left
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.4f, -0.2f, 1.6f);
    glVertex3f(-1.4f, -0.2f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.6f);

    // left leg back front

    // front
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-1.8f, -0.2f, -1.2f);
    glVertex3f(-1.4f, -0.2f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.2f);

    // back
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-1.8f, -0.2f, -1.6f);
    glVertex3f(-1.4f, -0.2f, -1.6f);
    glVertex3f(-1.4f, -3.0f, -1.6f);
    glVertex3f(-1.8f, -3.0f, -1.6f);

    // right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, -0.2f, -1.6f);
    glVertex3f(-1.8f, -0.2f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.6f);

    // left
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.4f, -0.2f, -1.6f);
    glVertex3f(-1.4f, -0.2f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.6f);

    // chair back
    //  front
    glColor3d(124 / 255.0, 90 / 255.0, 4 / 255.0);

    // glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -1.8f);
    glVertex3f(1.8f, 0.2f, -1.8f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(-1.8f, 3.5f, -1.8f);

    // back
    //  glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -2.0f);

    //  glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -1.8f);
    glVertex3f(-1.8f, 0.2f, -1.8f);

    glVertex3f(1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 3.5f, -2.0f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 0.2f, -1.8f);
    glVertex3f(-1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 3.5f, -2.0f);
    glEnd();
    glPopMatrix();
}

void Cabin::table_with_chairs()
{
    // Table
    glPushMatrix();
    glScaled(3, 3, 3);
    table();
    glPopMatrix();
    // Chairs
    // First chair
    glPushMatrix();
    glTranslated(-0, -0.85, -3);
    glScaled(0.5, 0.7, 0.4);
    chair();
    glPopMatrix();
    // Second chair
    glPushMatrix();
    glTranslated(-0, -0.85, 3);
    glScaled(0.5, 0.7, 0.4);
    glRotated(180, 0, 1, 0);
    chair();
    glPopMatrix();
    // Third chair
    glPushMatrix();
    glTranslated(2.8, -0.85, -1);
    glScaled(0.5, 0.7, 0.4);
    glRotated(-90, 0, 1, 0);
    chair();
    glPopMatrix();
    // Fourth chair
    glPushMatrix();
    glTranslated(2.8, -0.85, 1);
    glScaled(0.5, 0.7, 0.4);
    glRotated(-90, 0, 1, 0);
    chair();
    glPopMatrix();
}

void Cabin::kid_drawing()
{
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-0.5, -1, 0);
    glTexCoord2d(1, 0);
    glVertex3d(0.5, -1, 0);
    glTexCoord2d(1, 1);
    glVertex3d(0.5, 1, 0);
    glTexCoord2d(0, 1);
    glVertex3d(-0.5, 1, 0);
    glEnd();
}

void Cabin::swing()
{
    glColor3d(255.0 / 255, 0, 0);
    // Left bars
    glPushMatrix();
    glTranslated(0, 0, 0);
    glRotated(-20, 0, 0, 1);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.17, 0, 0);
    glRotated(20, 0, 0, 1);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // Right bars
    glPushMatrix();
    glTranslated(0, 0, -0.75);
    glRotated(-20, 0, 0, 1);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.17, 0, -0.75);
    glRotated(20, 0, 0, 1);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // Top rod
    glPushMatrix();
    glTranslated(0.09, 0.23, -0.375);
    glScaled(0.01, 0.01, 0.5);
    glutSolidCube(1.5);
    glPopMatrix();

    // Chains
    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(0.09, 0.05, -0.1);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(0.75);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(0.09, 0.05, -0.25);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(0.75);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(0.09, 0.05, -0.5);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(0.75);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(0.09, 0.05, -0.65);
    glScaled(0.01, 0.5, 0.01);
    glutSolidCube(0.75);
    glPopMatrix();

    // Seats
    glColor3d(255.0 / 255.0, 255.0 / 255.0, 17.0 / 255.0);
    glPushMatrix();
    glTranslated(0.09, -0.14, -0.575);
    glScaled(0.25, 0.01, 0.33);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3d(255.0 / 255.0, 255.0 / 255.0, 17.0 / 255.0);
    glPushMatrix();
    glTranslated(0.09, -0.14, -0.175);
    glScaled(0.25, 0.01, 0.33);
    glutSolidCube(0.5);
    glPopMatrix();
}

void Cabin::slide()
{
    double inclination = 45.0;

    /**
     * Base
     */
    // right edge
    glColor3d(255.0 / 255, 0, 0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glRotatef(inclination, 0, 0, 1);
    glScaled(1, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // right base edge
    glColor3d(255.0 / 255, 0, 0);
    glPushMatrix();
    glTranslated(-0.707 + 0.246, -0.351, 0);
    glScaled(0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // right top edge
    glColor3d(255.0 / 255, 0, 0);
    glPushMatrix();
    glTranslated(0.46, 0.35, 0);
    glScaled(-0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // slide part
    glColor3d(5.0 / 255, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(0, 0, -0.1);
    glRotatef(inclination, 0, 0, 1);
    glScaled(1, 0.001, -0.2);
    glutSolidCube(1);
    glPopMatrix();

    // slide base part
    glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(-0.707 + 0.246, -0.351, -0.1);
    glScaled(0.23, 0.001, -0.2);
    glutSolidCube(1);
    glPopMatrix();

    // slide top part
    glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(0.46, 0.35, -0.1);
    glScaled(0.23, 0.001, -0.2);
    glutSolidCube(1);
    glPopMatrix();

    // left edge
    glColor3d(255 / 255.0, 0, 0);
    glPushMatrix();
    glTranslated(0, 0, -0.2);
    glRotatef(inclination, 0, 0, 1);
    glScaled(1, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // left base edge
    glColor3d(255 / 255.0, 0, 0);
    glPushMatrix();
    glTranslated(-0.707 + 0.246, -0.351, -0.2);
    glScaled(0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // left top edge
    glColor3d(255.0 / 255, 0, 0);
    glPushMatrix();
    glTranslated(0.46, 0.35, -0.2);
    glScaled(-0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    /**
     * Stairs
     */
    // right stairs edge
    glColor3d(255.0 / 255, 0, 0);
    glPushMatrix();
    glTranslated(0.56, -0.01, 0);
    glScaled(0.03, 0.71, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // left stairs edge
    glColor3d(255.0 / 255, 0, 0);
    glPushMatrix();
    glTranslated(0.56, -0.01, -0.2);
    glScaled(0.03, 0.71, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    /**
     * Bars
     */
    // bar 1
    glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(0.56, 0.18, -0.1);
    glScaled(0.03, 0.03, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    // bar 2
    glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(0.56, 0.03, -0.1);
    glScaled(0.03, 0.03, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    // bar 3
    glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(0.56, -0.12, -0.1);
    glScaled(0.03, 0.03, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    // bar 4
    glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(0.56, -0.27, -0.1);
    glScaled(0.03, 0.03, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    /**
     * Frame
     */
    // frame right side
    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.36, 0.464, 0);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.41, 0.464, 0);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.46, 0.464, 0);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.51, 0.464, 0);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.56, 0.464, 0);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // frame left side
    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.36, 0.464, -0.2);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.41, 0.464, -0.2);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.46, 0.464, -0.2);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.51, 0.464, -0.2);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.56, 0.464, -0.2);
    glScaled(-0.015, 0.2, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // frame top
    // frame top right
    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.46, 0.55, 0);
    glScaled(-0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // frame top left
    // frame top right
    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    glPushMatrix();
    glTranslated(0.46, 0.55, -0.2);
    glScaled(-0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();
}

void Cabin::monkey_bar()
{
    /**
     * Frame
     */
    // frame right edge
    glColor3d(9 / 255.0, 71 / 255.0, 42 / 255.0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(1.01, 0.0301, 0.0501);
    glutSolidCube(1);
    glPopMatrix();

    // frame left edge
    glColor3d(9 / 255.0, 71 / 255.0, 42 / 255.0);
    glPushMatrix();
    glTranslated(0, 0, -0.35);
    glScaled(1.01, 0.0301, 0.0501);
    glutSolidCube(1);
    glPopMatrix();

    // frame right legs
    glColor3d(9 / 255.0, 71 / 255.0, 42 / 255.0);
    glPushMatrix();
    glTranslated(-0.485, -0.287, 0);
    glScaled(0.03, 0.6, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(9 / 255.0, 71 / 255.0, 42 / 255.0);
    glPushMatrix();
    glTranslated(0.485, -0.287, 0);
    glScaled(0.03, 0.6, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    // frame left legs
    glColor3d(9 / 255.0, 71 / 255.0, 42 / 255.0);
    glPushMatrix();
    glTranslated(-0.485, -0.287, -0.35);
    glScaled(0.03, 0.6, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(9 / 255.0, 71 / 255.0, 42 / 255.0);
    glPushMatrix();
    glTranslated(0.485, -0.287, -0.35);
    glScaled(0.03, 0.6, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    /**
     * Bars
     */
    glColor3d(53 / 255.0, 64 / 255.0, 86 / 255.0);
    glPushMatrix();
    glTranslated(0, 0, -0.2);
    glScaled(0.03, 0.03, -0.35);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(53 / 255.0, 64 / 255.0, 86 / 255.0);
    glPushMatrix();
    glTranslated(0.15, 0, -0.2);
    glScaled(0.03, 0.03, -0.35);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(53 / 255.0, 64 / 255.0, 86 / 255.0);
    glPushMatrix();
    glTranslated(-0.15, 0, -0.2);
    glScaled(0.03, 0.03, -0.35);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(53 / 255.0, 64 / 255.0, 86 / 255.0);
    glPushMatrix();
    glTranslated(0.3, 0, -0.2);
    glScaled(0.03, 0.03, -0.35);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(53 / 255.0, 64 / 255.0, 86 / 255.0);
    glPushMatrix();
    glTranslated(-0.3, 0, -0.2);
    glScaled(0.03, 0.03, -0.35);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(53 / 255.0, 64 / 255.0, 86 / 255.0);
    glPushMatrix();
    glTranslated(-0.45, 0, -0.2);
    glScaled(0.03, 0.03, -0.35);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(53 / 255.0, 64 / 255.0, 86 / 255.0);
    glPushMatrix();
    glTranslated(0.45, 0, -0.2);
    glScaled(0.03, 0.03, -0.35);
    glutSolidCube(1);
    glPopMatrix();
}

void Cabin::bench()
{
    // base right legs
    glColor3d(45 / 255.0, 45 / 255.0, 43 / 255.0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(0.05, 0.3, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(45 / 255.0, 45 / 255.0, 43 / 255.0);
    glPushMatrix();
    glTranslated(0.5, 0, 0);
    glScaled(0.05, 0.3, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    // right joiner
    glColor3d(45 / 255.0, 45 / 255.0, 43 / 255.0);
    glPushMatrix();
    glTranslated(0.25, 0.175, 0);
    glScaled(0.55, 0.05, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    // base left legs
    glColor3d(45 / 255.0, 45 / 255.0, 43 / 255.0);
    glPushMatrix();
    glTranslated(0, 0, -1);
    glScaled(0.05, 0.3, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(45 / 255.0, 45 / 255.0, 43 / 255.0);
    glPushMatrix();
    glTranslated(0.5, 0, -1);
    glScaled(0.05, 0.3, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    // left joiner
    glColor3d(45 / 255.0, 45 / 255.0, 43 / 255.0);
    glPushMatrix();
    glTranslated(0.25, 0.175, -1);
    glScaled(0.55, 0.05, 0.05);
    glutSolidCube(1);
    glPopMatrix();

    // seat
    glColor3d(124 / 255.0, 90 / 255.0, 4 / 255.0);
    glPushMatrix();
    glTranslated(0.05, 0.225, -0.5);
    glScaled(0.05, 0.05, -1.3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.12, 0.225, -0.5);
    glScaled(0.05, 0.05, -1.3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.19, 0.225, -0.5);
    glScaled(0.05, 0.05, -1.3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.26, 0.225, -0.5);
    glScaled(0.05, 0.05, -1.3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.33, 0.225, -0.5);
    glScaled(0.05, 0.05, -1.3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.4, 0.225, -0.5);
    glScaled(0.05, 0.05, -1.3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.47, 0.225, -0.5);
    glScaled(0.05, 0.05, -1.3);
    glutSolidCube(1);
    glPopMatrix();
}

void Cabin::play_cabin_content()
{
    /**
     * Tables
     */
    glPushMatrix();
    glTranslated(-10, -5, 0);
    /**
     * First Table
     */
    glPushMatrix();
    glTranslated(0, 0, -34);
    table_with_chairs();
    /**
     * Drawings
     */
    glTranslated(0, 0.153, 0);
    // First drawing
    glPushMatrix();
    bind_texture(DRAWING_1);
    glTranslated(0, 0, 1.9);
    glRotated(-90, 1, 0, 0);
    kid_drawing();
    unbind_texture();
    glPopMatrix();
    // Second drawing
    glPushMatrix();
    bind_texture(DRAWING_2);
    glTranslated(0, 0, -1.9);
    glRotated(-90, 1, 0, 0);
    glRotated(180, 0, 0, 1);
    kid_drawing();
    unbind_texture();
    glPopMatrix();
    // Third drawing
    glPushMatrix();
    bind_texture(DRAWING_3);
    glTranslated(1.9, 0, 0);
    glRotated(-90, 1, 0, 0);
    glRotated(90, 0, 0, 1);
    kid_drawing();
    unbind_texture();
    glPopMatrix();

    glPopMatrix(); // first table

    /**
     * Second Table
     */
    glPushMatrix();
    glTranslated(0, 0, -20);
    table_with_chairs();
    /**
     * Drawings
     */
    glTranslated(0, 0.153, 0);
    // First drawing
    glPushMatrix();
    bind_texture(DRAWING_3);
    glTranslated(0, 0, 1.9);
    glRotated(-90, 1, 0, 0);
    kid_drawing();
    unbind_texture();
    glPopMatrix();
    // Second drawing
    glPushMatrix();
    bind_texture(DRAWING_4);
    glTranslated(0, 0, -1.9);
    glRotated(-90, 1, 0, 0);
    glRotated(180, 0, 0, 1);
    kid_drawing();
    unbind_texture();
    glPopMatrix();
    // Third drawing
    glPushMatrix();
    bind_texture(DRAWING_5);
    glTranslated(1.9, 0, 0);
    glRotated(-90, 1, 0, 0);
    glRotated(90, 0, 0, 1);
    kid_drawing();
    unbind_texture();
    glPopMatrix();

    glPopMatrix(); // second table

    /**
     * Benches
     */
    glPushMatrix();
    glTranslated(-3, -2.2, -1);
    glScaled(7, 5, 10);
    bench();

    glPopMatrix(); // benches

    glPopMatrix();

    /**
     * Toys
     */
    glPushMatrix();
    glTranslated(10, -3.3, 0);

    /**
     * Swing
     */
    glPushMatrix();
    glTranslated(0, 0, -30);
    glScaled(15, 20, 15);
    swing();
    glPopMatrix();
    /**
     * Slide
     */
    glPushMatrix();
    glTranslated(3, 0.1, -20);
    glRotated(90, 0, 1, 0);
    glScaled(13, 13, 13);
    slide();
    glPopMatrix();
    /**
     * Monkey Bar
     */
    glPushMatrix();
    glTranslated(4, 1.2, -5);
    glRotated(90, 0, 1, 0);
    glScaled(13, 10, 13);
    monkey_bar();
    glPopMatrix();

    glPopMatrix();
}

void Cabin::render()
{
    glPushMatrix();
    glColor3d(1, 1, 1);
    // roof
    glPushMatrix();
    // right
    glPushMatrix();
    glTranslated(15, 8.3, -4);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(118, 1, 0, 0);
    roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15, 8.3, -20);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(118, 1, 0, 0);
    roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15, 8.3, -36);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(118, 1, 0, 0);
    roof();
    glPopMatrix();
    // up
    glPushMatrix();
    glTranslated(0, 12, -4);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 12, -20);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 12, -36);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    roof();
    glPopMatrix();
    // left
    glPushMatrix();
    glTranslated(-15, 8.3, -4);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(62, 1, 0, 0);
    roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-15, 8.3, -20);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(62, 1, 0, 0);
    roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-15, 8.3, -36);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(62, 1, 0, 0);
    roof();
    glPopMatrix();
    // back&front
    glPushMatrix();
    glTranslated(0, 5, -2);
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_POLYGON);
    glVertex3d(-15.7, 0, 6);
    glVertex3d(-15.6, 3, 6);
    glVertex3d(-8, 7, 6);
    glVertex3d(8, 7, 6);
    glVertex3d(15.7, 3, 6);
    glVertex3d(15.67, 0, 6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 5, -2.4);
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_POLYGON);
    glVertex3d(-15.7, 0, 6);
    glVertex3d(-15.6, 3, 6);
    glVertex3d(-8, 7, 6);
    glVertex3d(8, 7, 6);
    glVertex3d(15.7, 3, 6);
    glVertex3d(15.67, 0, 6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 5, -49);
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_POLYGON);
    glVertex3d(-15.7, 0, 6);
    glVertex3d(-15.6, 3, 6);
    glVertex3d(-8, 7, 6);
    glVertex3d(8, 7, 6);
    glVertex3d(15.7, 3, 6);
    glVertex3d(15.67, 0, 6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 5, -50.2);
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_POLYGON);
    glVertex3d(-15.7, 0, 6);
    glVertex3d(-15.6, 3, 6);
    glVertex3d(-8, 7, 6);
    glVertex3d(8, 7, 6);
    glVertex3d(15.7, 3, 6);
    glVertex3d(15.67, 0, 6);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    // front side

    // 2
    glPushMatrix();
    glTranslated(11.1, -0.8, 3.9);
    glScaled(0.6, 0.9, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    // 3
    glPushMatrix();
    glTranslated(-11.1, -0.8, 3.9);
    glScaled(0.6, 0.9, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();

    // door
    // 1
    glPushMatrix();
    glTranslated(d1, -1, 3.7);
    glScaled(2, 3.5, 0);
    glRotated(180, 0, 1, 0);
    door();
    glPopMatrix();
    // 2
    glPushMatrix();
    glTranslated(-d1, -1, 3.7);
    glScaled(2, 3.5, 0);
    door();
    glPopMatrix();

    // back side

    // 2
    glPushMatrix();
    glTranslated(11.1, -0.8, -43.9);
    glScaled(0.6, 0.9, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    // 3
    glPushMatrix();
    glTranslated(-11.1, -0.8, -43.9);
    glScaled(0.6, 0.9, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();

    // door
    // 1
    glPushMatrix();
    glTranslated(d2, -1, -43.7);
    glScaled(2, 3.5, 0);
    glRotated(180, 0, 1, 0);
    door();
    glPopMatrix();
    // 2
    glPushMatrix();
    glTranslated(-d2, -1, -43.7);
    glScaled(2, 3.5, 0);
    door();
    glPopMatrix();

    // rigt side
    glPushMatrix();
    glScaled(1, 0.4, 1);
    glTranslated(0, -12, 0);
    glPushMatrix();
    glTranslated(16, 0, -4);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(16, 0, -20);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(16, 0, -36);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPopMatrix();
    // colm
    glPushMatrix();
    glTranslated(15.7, 6.1, -20);
    glScaled(1, 0.2, 3);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15.6, 0, -42.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15.6, 0, -20.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15.6, 0, 2.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    // left side
    glPushMatrix();
    glScaled(1, 0.4, 1);
    glTranslated(0, -12, 0);
    glPushMatrix();
    glTranslated(-16, 0, -4);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-16, 0, -20);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-16, 0, -36);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    glPopMatrix();
    // colm
    glPushMatrix();
    glTranslated(-15.7, 6.1, -20);
    glScaled(1, 0.2, 3);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15.6, 0, -42.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15.6, 0, -20.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15.6, 0, 2.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    square();
    glPopMatrix();
    // down side
    glPushMatrix();
    glScaled(2, 1, 1);
    //
    glPushMatrix();
    glTranslated(0, -8, -4);
    glRotated(90, 1, 0, 0);
    glColor3f(0.5, 0.5, 0.5);
    unbind_texture();
    bind_texture(FLOOR);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-8, -8, 0);
    glTexCoord2d(4, 0);
    glVertex3d(8, -8, 0);
    glTexCoord2d(4, 4);
    glVertex3d(8, 8, 0);
    glTexCoord2d(0, 4);
    glVertex3d(-8, 8, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, -8, -20);
    glRotated(90, 1, 0, 0);
    glColor3f(0.5, 0.5, 0.5);
    unbind_texture();
    bind_texture(FLOOR);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-8, -8, 0);
    glTexCoord2d(4, 0);
    glVertex3d(8, -8, 0);
    glTexCoord2d(4, 4);
    glVertex3d(8, 8, 0);
    glTexCoord2d(0, 4);
    glVertex3d(-8, 8, 0);
    glEnd();
    glPopMatrix();

    glTranslated(0, -8, -36);
    glRotated(90, 1, 0, 0);
    glColor3f(0.5, 0.5, 0.5);
    unbind_texture();
    bind_texture(FLOOR);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-8, -8, 0);
    glTexCoord2d(4, 0);
    glVertex3d(8, -8, 0);
    glTexCoord2d(4, 4);
    glVertex3d(8, 8, 0);
    glTexCoord2d(0, 4);
    glVertex3d(-8, 8, 0);
    glEnd();
    glPopMatrix();
    unbind_texture();
    glPopMatrix();

    play_cabin_content();
    glPopMatrix();
}
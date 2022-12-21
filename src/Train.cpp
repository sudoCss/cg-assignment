#include "Train.h"

Train::Train(/* args */)
{
}

Train::~Train()
{
}

void Train::load_resources()
{
    for (GLuint i = 0; i < FACES_COUNT; i++)
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

void Train::bind_texture(GLuint face)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, textures_ids[face]);
}

void Train::unbind_texture()
{
    glDisable(GL_TEXTURE_2D);
}

void Train::make_square()
{
    // glBindTexture(GL_TEXTURE_2D, textures_ids[WP]);
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

void Train::make_door()
{
    // glBindTexture(GL_TEXTURE_2D, textures_ids[DOOR]);
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

void Train::make_roof()
{
    // glBindTexture(GL_TEXTURE_2D, textures_ids[ROOF]);
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

void Train::open_front_door()
{
    if (d1 < 10)
        d1 += 0.5;
}

void Train::close_front_door()
{
    if (d1 > 4)
        d1 -= 0.5;
}

void Train::open_back_door()
{
    if (d2 < 10)
        d2 += 0.5;
}

void Train::close_back_door()
{
    if (d2 > 4)
        d2 -= 0.5;
}

void Train::render()
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
    make_roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15, 8.3, -20);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(118, 1, 0, 0);
    make_roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15, 8.3, -36);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(118, 1, 0, 0);
    make_roof();
    glPopMatrix();
    // up
    glPushMatrix();
    glTranslated(0, 12, -4);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    make_roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 12, -20);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    make_roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 12, -36);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(90, 1, 0, 0);
    make_roof();
    glPopMatrix();
    // left
    glPushMatrix();
    glTranslated(-15, 8.3, -4);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(62, 1, 0, 0);
    make_roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-15, 8.3, -20);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(62, 1, 0, 0);
    make_roof();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-15, 8.3, -36);
    glColor3f(0.5, 0.5, 0.5);
    glRotated(90, 0, 1, 0);
    glRotated(62, 1, 0, 0);
    make_roof();
    glPopMatrix();
    // back&front
    glPushMatrix();
    glTranslated(0, 5, -2);
    glColor3f(0.5, 0.5, 0.5);
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
    glColor3f(0.5, 0.5, 0.5);
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
    glColor3f(0.5, 0.5, 0.5);
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
    glColor3f(0.5, 0.5, 0.5);
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
    make_square();
    glPopMatrix();
    // 3
    glPushMatrix();
    glTranslated(-11.1, -0.8, 3.9);
    glScaled(0.6, 0.9, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();

    // door
    // 1
    glPushMatrix();
    glTranslated(d1, -1, 3.7);
    glScaled(2, 3.5, 0);
    glRotated(180, 0, 1, 0);
    make_door();
    glPopMatrix();
    // 2
    glPushMatrix();
    glTranslated(-d1, -1, 3.7);
    glScaled(2, 3.5, 0);
    make_door();
    glPopMatrix();

    // back side

    // 2
    glPushMatrix();
    glTranslated(11.1, -0.8, -43.9);
    glScaled(0.6, 0.9, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    // 3
    glPushMatrix();
    glTranslated(-11.1, -0.8, -43.9);
    glScaled(0.6, 0.9, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();

    // door
    // 1
    glPushMatrix();
    glTranslated(d2, -1, -43.7);
    glScaled(2, 3.5, 0);
    glRotated(180, 0, 1, 0);
    make_door();
    glPopMatrix();
    // 2
    glPushMatrix();
    glTranslated(-d2, -1, -43.7);
    glScaled(2, 3.5, 0);
    make_door();
    glPopMatrix();

    // rigt side
    glPushMatrix();
    glScaled(1, 0.4, 1);
    glTranslated(0, -12, 0);
    glPushMatrix();
    glTranslated(16, 0, -4);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(16, 0, -20);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(16, 0, -36);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPopMatrix();
    // colm
    glPushMatrix();
    glTranslated(15.7, 6.1, -20);
    glScaled(1, 0.2, 3);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15.6, 0, -42.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15.6, 0, -20.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(15.6, 0, 2.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    // left side
    glPushMatrix();
    glScaled(1, 0.4, 1);
    glTranslated(0, -12, 0);
    glPushMatrix();
    glTranslated(-16, 0, -4);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-16, 0, -20);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-16, 0, -36);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    glPopMatrix();
    // colm
    glPushMatrix();
    glTranslated(-15.7, 6.1, -20);
    glScaled(1, 0.2, 3);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15.6, 0, -42.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15.6, 0, -20.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15.6, 0, 2.2);
    glScaled(1, 1, 0.2);
    glRotated(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
    make_square();
    glPopMatrix();
    // down side
    glPushMatrix();
    glScaled(2, 1, 1);
    //
    glPushMatrix();
    glTranslated(0, -8, -4);
    glRotated(90, 1, 0, 0);
    glColor3f(0.5, 0.5, 0.5);
    // glBindTexture(GL_TEXTURE_2D, textures_ids[FLOOR]);
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
    // glBindTexture(GL_TEXTURE_2D, textures_ids[FLOOR]);
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
    // glBindTexture(GL_TEXTURE_2D, textures_ids[FLOOR]);
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
    glPopMatrix();
    glPopMatrix();
}
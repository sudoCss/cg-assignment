#include "Skybox.h"

Skybox::Skybox(/* args */)
{
}

Skybox::~Skybox()
{
}

void Skybox::load_resources()
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

void Skybox::bind_texture(GLuint face)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, textures_ids[face]);
}

void Skybox::unbind_texture()
{
    glDisable(GL_TEXTURE_2D);
}

void Skybox::render()
{
    glPushMatrix();
    for (GLuint i = 0; i < FACES_COUNT; i++)
    {
        bind_texture(i);
        glBegin(GL_QUADS);
        {
            glTexCoord2d(coordinates[i][0][3], coordinates[i][0][4]);
            glVertex3f(coordinates[i][0][0], coordinates[i][0][1], coordinates[i][0][2]);

            glTexCoord2d(coordinates[i][1][3], coordinates[i][1][4]);
            glVertex3f(coordinates[i][1][0], coordinates[i][1][1], coordinates[i][1][2]);

            glTexCoord2d(coordinates[i][2][3], coordinates[i][2][4]);
            glVertex3f(coordinates[i][2][0], coordinates[i][2][1], coordinates[i][2][2]);

            glTexCoord2d(coordinates[i][3][3], coordinates[i][3][4]);
            glVertex3f(coordinates[i][3][0], coordinates[i][3][1], coordinates[i][3][2]);
        }
        glEnd();
        unbind_texture();
    }
    glPopMatrix();
}

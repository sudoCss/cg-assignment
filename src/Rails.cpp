#include "Rails.h"

Rails::Rails(/* args */)
{
}

Rails::~Rails()
{
}

void Rails::load_resources()
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

void Rails::bind_texture(GLuint face)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, textures_ids[face]);
}

void Rails::unbind_texture()
{
    glDisable(GL_TEXTURE_2D);
}

void Rails::render()
{
    glPushMatrix();
    bind_texture(RAILS);
    glBegin(GL_QUADS);
    glTexCoord2d(coordinates[0][0][3], coordinates[0][0][4]);
    glVertex3d(coordinates[0][0][0], coordinates[0][0][1], coordinates[0][0][2]);

    glTexCoord2d(coordinates[0][1][3], coordinates[0][1][4]);
    glVertex3d(coordinates[0][1][0], coordinates[0][1][1], coordinates[0][1][2]);

    glTexCoord2d(coordinates[0][2][3], coordinates[0][2][4]);
    glVertex3d(coordinates[0][2][0], coordinates[0][2][1], coordinates[0][2][2]);

    glTexCoord2d(coordinates[0][3][3], coordinates[0][3][4]);
    glVertex3d(coordinates[0][3][0], coordinates[0][3][1], coordinates[0][3][2]);
    glEnd();
    unbind_texture();
    glPopMatrix();
}

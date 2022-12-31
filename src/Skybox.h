#ifndef _SKYBOX_H
#define _SKYBOX_H

#include "Includes.h"

class Skybox
{
private:
    const char *textures_file_paths[6] = {
        "assets/skybox/front.bmp",
        "assets/skybox/back.bmp",
        "assets/skybox/left.bmp",
        "assets/skybox/right.bmp",
        "assets/skybox/up.bmp",
        "assets/skybox/down.bmp",
    };
    GLuint textures_ids[6] = {0};
    GLfloat d = 500;
    static const GLuint FACES_COUNT = 6;
    enum
    {
        FRONT_FACE = 0,
        BACK_FACE,
        LEFT_FACE,
        RIGHT_FACE,
        UP_FACE,
        DOWN_FACE,
    };
    GLfloat coordinates[FACES_COUNT][4][5] = {
        // front
        {
            {-d, -0.1, -d, 0, 0},
            {d, -0.1, -d, 1, 0},
            {d, d, -d, 1, 1},
            {-d, d, -d, 0, 1},
        },
        //  back
        {
            {-d, -0.1, d, 0, 0},
            {-d, d, d, 0, 1},
            {d, d, d, 1, 1},
            {d, -0.1, d, 1, 0},
        },
        //  left
        {
            {-d, -0.1, d, 1, 0},
            {-d, -0.1, -d, 0, 0},
            {-d, d, -d, 0, 1},
            {-d, d, d, 1, 1},
        },
        //  right
        {
            {d, -0.1, d, 1, 0},
            {d, d, d, 1, 1},
            {d, d, -d, 0, 1},
            {d, -0.1, -d, 0, 0},
        },
        //  up
        {
            {-d, d, -d, 0, 0},
            {d, d, -d, 0, 1},
            {d, d, d, 1, 1},
            {-d, d, d, 1, 0},
        },
        //  down
        {
            {-d, -0.1, -d, 0, 0},
            {-d, -0.1, d, 0, 1},
            {d, -0.1, d, 1, 1},
            {d, -0.1, -d, 1, 0},
        },
    };

    void bind_texture(GLuint face);

    void unbind_texture();

public:
    Skybox(/* args */);
    ~Skybox();

    void load_resources();

    void render();
};

#endif
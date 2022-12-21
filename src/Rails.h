#ifndef _RAILS_H
#define _RAILS_H

#include "Includes.h"

class Rails
{
private:
    static const GLuint PIECES_COUNT = 1;

    const char *textures_file_paths[PIECES_COUNT] = {
        "assets/rails.bmp",
    };

    GLuint textures_ids[PIECES_COUNT] = {0};

    enum
    {
        RAILS = 0,
    };

    GLfloat coordinates[PIECES_COUNT][4][5] = {
        // front
        {
            {-20, 0, 500, 0, 0},
            {-20, 0, -500, 70, 0},
            {20, 0, -500, 70, 1},
            {20, 0, 500, 0, 1},
        },

    };

    void bind_texture(GLuint face);

    void unbind_texture();

public:
    Rails(/* args */);
    ~Rails();

    void load_resources();

    void render();
};

#endif

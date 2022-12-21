#ifndef _TRAIN_H
#define _TRAIN_H

#include "Includes.h"

class Train
{
private:
    float angle = 0;
    float d1 = 4;
    float d2 = 4;

    static const GLuint PIECES_COUNT = 11;

    const char *textures_file_paths[6] = {
        "assets/train/door.bmp",
        "assets/train/floor.bmp",
        "assets/train/roof.bmp",
        "assets/train/wp.bmp",
    };
    static const GLuint FACES_COUNT = 4;

    GLuint textures_ids[FACES_COUNT] = {0};

    enum
    {
        DOOR = 0,
        FLOOR,
        ROOF,
        WP,
    };

    void bind_texture(GLuint face);

    void unbind_texture();

    void make_square();

    void make_door();

    void make_roof();

public:
    Train(/* args */);
    ~Train();

    void load_resources();

    void open_front_door();

    void close_front_door();

    void open_back_door();

    void close_back_door();

    void render();
};

#endif
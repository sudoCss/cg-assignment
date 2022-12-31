#ifndef _CABIN_H
#define _CABIN_H

#include "Includes.h"

class Cabin
{
private:
    float angle = 0;
    float d1 = 4;
    float d2 = 4;

    static const GLuint PIECES_COUNT = 9;

    const char *textures_file_paths[PIECES_COUNT] = {
        "assets/cabin/door.bmp",
        "assets/cabin/floor.bmp",
        "assets/cabin/roof.bmp",
        "assets/cabin/wp.bmp",
        "assets/drawings/drawing1.bmp",
        "assets/drawings/drawing2.bmp",
        "assets/drawings/drawing3.bmp",
        "assets/drawings/drawing4.bmp",
        "assets/drawings/drawing5.bmp",
    };

    GLuint textures_ids[PIECES_COUNT] = {0};

    enum
    {
        DOOR = 0,
        FLOOR,
        ROOF,
        WP,
        DRAWING_1,
        DRAWING_2,
        DRAWING_3,
        DRAWING_4,
        DRAWING_5,
    };

    void bind_texture(GLuint face);

    void unbind_texture();

    void square();

    void door();

    void roof();

    void play_cabin_content();

    void table();

    void chair();

    void table_with_chairs();

    void kid_drawing();

    void swing();

    void slide();

    void monkey_bar();

    void bench();

public:
    Cabin(/* args */);
    ~Cabin();

    void load_resources();

    void open_front_door();

    void close_front_door();

    void open_back_door();

    void close_back_door();

    void render();
};

#endif
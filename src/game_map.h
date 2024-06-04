#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "malloc.h"

class Game_map{

public:

    Game_map(int width, int height);
    ~Game_map();

    int get_map_index(int i, int j) {return map[i][j];}
    int get_height() {return height;}
    int get_width() {return width;}
    void print_map();

private:

    int** map;
    int height;
    int width;
};


#endif

#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "cell.h"
#include <vector>
#include <cstdlib> 
#include <ctime> 

class Game_map{

public:

    Game_map(int width, int height);
    ~Game_map();

    Cell get_map_index(int i, int j) {return map[i][j];}
    void init_map(int x,int y);
    inline int get_height() {return height;}
    inline int get_width() {return width;}
    void print_map();
    void set_map_index(int x,int y,int newNum);
    void printMap2();


private:

    std::vector<std::vector<Cell>> map;
    int height;
    int width;
};


#endif

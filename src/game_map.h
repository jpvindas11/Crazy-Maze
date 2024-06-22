#ifndef GAME_MAP_H
#define GAME_MAP_H

#define EXTRA_EDGE_PROB 0.3 //con 30 % para que se hagan mas caminos

#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include "cell.h"
#include "math.h"

class Game_map{

public:

    Game_map(int width, int height);
    ~Game_map();

    Cell& get_map_index(int x, int y);
    void set_map_index(int x,int y,int newNum);
    void init_map(int x,int y);
    inline int get_height() {return height;}
    inline int get_width() {return width;}
    void add_treasure(int width, int height);
    

    void add_extra_edges(int x, int y);
    bool bool_add_extra_edge();

    //void set_treasure(int x1, int y1, int x2, int y2);

    void print_map();
    void print_map_state() const;
private:

    std::vector<std::vector<Cell>> map;
    int height;
    int width;
};


#endif

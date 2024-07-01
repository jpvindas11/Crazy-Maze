#ifndef GAME_MAP_H
#define GAME_MAP_H

#define EXTRA_EDGE_PROB 0.3 //con 30 % para que se hagan mas caminos

#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include "cell.h"
#include "player.h"

class Cell;  
class Game_map{

public:

    Game_map(int width, int height);
    ~Game_map();
    void clear_map();
    Cell& get_map_index(int x, int y);
    void set_map_index(int x,int y,int newNum);
    void init_map(int x,int y);
    inline int get_height() {return height;}
    inline int get_width() {return width;}
    void fill_east_side();
    void reset_map();
    void start_generation(int width, int height);

    void add_extra_edges(int x, int y);
    bool bool_add_extra_edge();
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> portal_list;

    
private:

    std::vector<std::vector<Cell>> map;
    int height;
    int width;
};


#endif

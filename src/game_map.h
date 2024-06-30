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
class Player;
class Game_map{

public:

    Game_map(int width, int height);
    ~Game_map();

    Cell& get_map_index(int x, int y);
    void set_map_index(int x,int y,int newNum);
    void init_map(int x,int y);
    inline int get_height() {return height;}
    inline int get_width() {return width;}
    void fill_east_side();
    void set_treasure_at(Player& player1, Player& player2);

    void add_extra_edges(int x, int y);
    bool bool_add_extra_edge();

    
private:

    std::vector<std::vector<Cell>> map;
    int height;
    int width;
    std::vector<std::pair<int, int>> treasure_positions; 
};


#endif

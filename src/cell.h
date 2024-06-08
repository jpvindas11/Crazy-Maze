#ifndef CELL_H
#define CELL_H

struct Cell{

    bool top_wall;
    bool bottom_wall;
    bool right_wall;
    bool left_wall;
    bool visited;
    Cell () :top_wall(true), bottom_wall(true), right_wall(true),
     left_wall(true), visited(false){}

};


#endif
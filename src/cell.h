#ifndef CELL_H
#define CELL_H

#define PORTAL_SPAWN_RATE 0.02
#define POWER_SPAWN_RATE 0.06

#include<iostream>

class Cell {

public:
    
    Cell() 
        : top_wall(true), bottom_wall(true), right_wall(true), left_wall(true), visited(false),has_Portal(false),has_double_Play(false),has_control_Enemy(false),has_jump_wall(false) {}

    bool hasTopWall() const { return top_wall; }
    bool hasBottomWall() const { return bottom_wall; }
    bool hasRightWall() const  { return right_wall; }
    bool hasLeftWall() const { return left_wall; }
    inline bool isVisited() const { return visited; }
    inline bool getPortal() const {return this->has_Portal;}
    inline bool get_double_play()const {return this->has_double_Play;}
    inline bool getControlEnemy() const { return has_control_Enemy; }
    inline bool getJumpWall() const { return has_jump_wall; }

   
    inline void setTopWall(bool value) { this->top_wall = value; }
    inline void setBottomWall(bool value) { this->bottom_wall = value; }
    inline void setRightWall(bool value) { this->right_wall = value; }
    inline void setLeftWall(bool value) { this->left_wall = value; }
    inline void setVisited(bool value) { this->visited = value; }
    inline void setPortal(bool value) {this->has_Portal=value;}



    void update_Powers(int height,int width);
    void clean_cell();

    bool isPortal(int height,int width); 
    bool double_play();
    bool control_Enemy();
    bool jump_Wall();




private:
    bool top_wall;
    bool bottom_wall;
    bool right_wall;
    bool left_wall;
    bool visited;
    bool has_Portal;
    bool has_double_Play;
    bool has_control_Enemy;
    bool has_jump_wall;

};

#endif
#ifndef CELL_H
#define CELL_H

#define PORTAL_SPAWN_RATE 0.08
#define DOUBLE_SPAWN_RATE 0.1
#define CONTROL_SPAWN_RATE 0.1
#define JUMP_SPAWN_RATE 0.1
#include "player.h"
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
    inline bool get_treasure() const {return has_treasure;}
   
    inline void setTopWall(bool value) { this->top_wall = value; }
    inline void setBottomWall(bool value) { this->bottom_wall = value; }
    inline void setRightWall(bool value) { this->right_wall = value; }
    inline void setLeftWall(bool value) { this->left_wall = value; }
    inline void setVisited(bool value) { this->visited = value; }
    
    inline void setPortal(bool value) {this->has_Portal=value;}
    inline void set_double_play(bool value) {this->has_double_Play=value;}
    inline void set_control_enemy(bool value) {this->has_control_Enemy=value;}
    inline void set_jump_wall(bool value){this-> has_jump_wall=value;}
    inline void set_treasure(bool value){this-> has_treasure=value; }
    void update_Powers(int height,int width);
    void clean_cell();

    bool isPortal(int height,int width); 
    bool double_play();
    bool control_Enemy();
    bool jump_Wall();
    


    bool isEmpty() const {
        return !has_Portal && !has_double_Play && !has_control_Enemy && !has_jump_wall && !has_treasure;
    }

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
    bool has_treasure;

};

#endif
#ifndef CELL_H
#define CELL_H

#define PORTAL_SPAWN_RATE 0.10

class Cell {

public:
    
    Cell() 
        : top_wall(true), bottom_wall(true), right_wall(true), left_wall(true), visited(false) {}

    inline bool hasTopWall() const { return top_wall; }
    inline bool hasBottomWall() const { return bottom_wall; }
    inline bool hasRightWall() const { return right_wall; }
    inline bool hasLeftWall() const { return left_wall; }
    inline bool isVisited() const { return visited; }

   
    inline void setTopWall(bool value) { this->top_wall = value; }
    inline void setBottomWall(bool value) { this->bottom_wall = value; }
    inline void setRightWall(bool value) { this->right_wall = value; }
    inline void setLeftWall(bool value) { this->left_wall = value; }
    inline void setVisited(bool value) { this->visited = value; }


    bool isPortal(); 



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
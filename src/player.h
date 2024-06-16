#ifndef PLAYER_H
#define PLAYER_H
#include "game_map.h" 
#include "cell.h"    


class Player {
public:
    Player(int x_start, int y_start);
    bool can_update_pos(Game_map& map);
    void update_pos(Game_map& game_map);
    void handleMovement(char direction,Game_map& game_map);
    void takeTurn(Game_map& game_map, char move_direction);
    bool get_if_moved () { return has_moved;}

    void set_has_moved(bool value) { has_moved = value;}

    int get_x() const { 
        return x; 
    }
    int get_y() const {
        return y;
    }
    void set_x(int new_x) {
        x = new_x;
    }
    void set_y(int new_y) {
        y = new_y;
    }
    int getJumpWallPower() const {
        return jumpWallPower;
    }
    void useDoublePlay() { 
        doublePlayPower = false; // when the player use power so now is false
    } 
    bool hasDoublePlay() const {
        return doublePlayPower;
    }
    bool hasControlEnemy() const {
        return controlEnemyPower;
    }
    void useControlEnemy() { 
        controlEnemyPower = false; 
    }
private:
    
    int x;
    int y;
    int new_x = 0;
    int new_y = 0;
    bool doublePlayPower;
    bool has_moved;
    int jumpWallPower;
    bool controlEnemyPower;
    bool canMove(int new_X, int new_Y, Game_map& map);
    void teleport(Game_map& map);
    void collectPowers(const Cell& cell);
    bool canJumpWall(int new_X, int new_Y, int &target_X, int &target_Y, Game_map& map);
    Game_map* map;
};


#endif
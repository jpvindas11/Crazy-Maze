#ifndef PLAYER_H
#define PLAYER_H
#include "game_map.h" 
#include "cell.h"    


class Player {
public:
    Player(int x_start, int y_start);
    bool boolUpdate(int new_X, int new_Y, Game_map& map);
    void update(int new_X, int new_Y);
    void handleMovement(char direction, Game_map& map);
    void takeTurn(Game_map& game_map);

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
    bool doublePlayPower;
    int jumpWallPower;
    bool controlEnemyPower;
    bool canMove(int new_X, int new_Y, Game_map& map);
    void teleport(Game_map& map);
    void collectPowers(const Cell& cell);
    bool canJumpWall(int new_X, int new_Y, int &target_X, int &target_Y, Game_map& map);
    Game_map* map;
};


#endif
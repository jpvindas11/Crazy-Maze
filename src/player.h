#ifndef PLAYER_H
#define PLAYER_H
#include "game_map.h" 
#include "cell.h"    


class Player {
public:

    Player(int x_length, int y_length);

    void handle_movement(char direction,Game_map& game_map);
    bool get_if_moved () { return has_moved; }

    void set_has_moved(bool value) { has_moved = value;}

    void update();

    int get_x() const { 
        return x; 
    }
    int get_y() const {
        return y;
    }
    int get_jump_wall_power() const {
        return jump_wall_power;
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
    bool get_jumped () {return has_jumped;}
    bool get_teleported() {return has_teleported;}

    void print_current_cell_info(Game_map& game_map);
private:
    
    int x;
    int y;
    bool doublePlayPower;
    bool has_moved;
    int jump_wall_power;
    bool controlEnemyPower;
    bool has_teleported;
    bool has_jumped;


private:

    void collect_cell(Game_map& map);
    void teleport(Game_map& map);
    void collect_powers(const Cell& cell);
    bool can_jump_wall(Game_map& map, char direction);
    bool can_move(Game_map& map, char direction);

};


#endif
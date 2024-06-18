#include "player.h"
#include <iostream>
Player::Player(int x_start, int y_start) : x(x_start), y(y_start), jump_wall_power(0), has_moved(false) {}

void Player::handle_movement(char direction, Game_map& game_map) {

    if (can_move(game_map, direction)){
        switch(direction){
            case 'w': y--; break;
            case 's': y++; break;
            case 'a': x--; break;
            case 'd': x++; break;
        }

        collect_cell(game_map); //Esto no sirve :c
        has_moved = true;
    } else {has_moved = false;}
}

bool Player::can_move(Game_map& game_map, char direction) {

    bool moved = true;
    bool wall = false;

    switch(direction){
    case 'w': if(game_map.get_map_index(y, x).hasTopWall()){wall = true;} break;
    case 's': if(game_map.get_map_index(y, x).hasBottomWall()){wall = true;} break;
    case 'a': if(game_map.get_map_index(y, x).hasLeftWall()){wall = true;} break;
    case 'd': if(game_map.get_map_index(y, x).hasRightWall()){wall = true;} break;
    case 'n': return false; break;
    }

    if (wall){
        if (jump_wall_power > 0){
            if (can_jump_wall(game_map, direction)){
                jump_wall_power--;
            } else {moved = false;}
        } else {moved = false;}
    }
    return moved;
}

void Player::collect_cell(Game_map& game_map){
    collect_powers(game_map.get_map_index(y, x));
    if (game_map.get_map_index(y, x).getPortal()) {
        teleport(game_map);
    }
    game_map.get_map_index(y, x).clean_cell();
}


bool Player::can_jump_wall(Game_map& game_map, char direction) {
    switch(direction){
        case 'w': if (y == 0) {return false;} break;
        case 's': if (y == game_map.get_height()-1) {return false;} break;
        case 'a': if (x == 0) {return false;} break;
        case 'd': if (x == game_map.get_width()-1) {return false;} break;
    }
    return true;
}

void Player::teleport(Game_map& game_map) {
    for (int i = 0; i < game_map.get_height(); ++i) {
        for (int j = 0; j < game_map.get_width(); ++j) {
            if (game_map.get_map_index(i, j).getPortal() && (i != y || j != x)) {
                y = i;
                x = j;
                std::cout << "Teletransportado a: (" << i << ", " << j << ")" << std::endl;
                game_map.get_map_index(i, j).clean_cell();
                return;
            }
        }
    }
}

void Player::collect_powers(const Cell& cell) {
    if (cell.getJumpWall()) {
        jump_wall_power++;
        std::cout << "Poder de salto acumulado: " << jump_wall_power << std::endl;
    }
    if (cell.get_double_play()) {
        doublePlayPower = true;
        std::cout << "Poder de doble turno obtenido." << std::endl;
    }
    if (cell.getControlEnemy()) {
        controlEnemyPower = true;
        std::cout << "Poder de controlar enemigo obtenido." << std::endl;
    }
}
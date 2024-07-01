#include "player.h"
#include <iostream>

Player::Player(int x_length, int y_length) : jump_wall_power(0), has_moved(false) {
   reset_position(x_length, y_length);
}
void Player::reset_position(int x_length, int y_length){
    x = int(std::rand()%x_length);
    y = int(std::rand()%y_length);
    has_treasure = false;
    has_teleported = true;
    jump_wall_power = 0;
    has_moved = false;
}
void Player::handle_movement(char direction, Game_map& game_map) {

    if (can_move(game_map, direction)) {
        switch(direction) {
            case 'w': y--; break;
            case 's': y++; break;
            case 'a': x--; break;
            case 'd': x++; break;
        }

        Cell& cell = game_map.get_map_index(y, x);
        collect_cell(game_map);

        has_moved = true;
    } else {
        has_moved = false;
    }
}

bool Player::can_move(Game_map& game_map, char direction) {
    bool moved = true;
    bool wall = false;

    switch(direction) {
        case 'w': if (game_map.get_map_index(y, x).hasTopWall()) wall = true; break;
        case 's': if (game_map.get_map_index(y, x).hasBottomWall()) wall = true; break;
        case 'a': if (game_map.get_map_index(y, x).hasLeftWall()) wall = true; break;
        case 'd': if (game_map.get_map_index(y, x).hasRightWall()) wall = true; break;
        case 'n': return false; break;
    }

    if (wall) {
        if (jump_wall_power > 0) {
            if (can_jump_wall(game_map, direction)) {
                jump_wall_power--;
                has_jumped = true;
            } else {
                moved = false;
            }
        } else {
            moved = false;
        }
    }
    return moved;
}

void Player::collect_cell(Game_map& game_map) {
    Cell& cell = game_map.get_map_index(y, x);
    collect_powers(cell);
    if (cell.getPortal()) {
        cell.clean_cell();
        teleport(game_map);
    } else {
        cell.clean_cell();
    }
}

bool Player::can_jump_wall(Game_map& game_map, char direction) {
    switch(direction) {
        case 'w': return y > 0;
        case 's': return y < game_map.get_height() - 1;
        case 'a': return x > 0;
        case 'd': return x < game_map.get_width() - 1;
    }
    return false;
}

void Player::teleport(Game_map& game_map) {
    for (const auto& portal_pair : game_map.portal_list) {
        if (portal_pair.first == std::make_pair(y, x)) {
            y = portal_pair.second.first;
            x = portal_pair.second.second;
            game_map.get_map_index(y, x).clean_cell();
            has_teleported = true;
            return;
        } else if (portal_pair.second == std::make_pair(y, x)) {
            y = portal_pair.first.first;
            x = portal_pair.first.second;
            game_map.get_map_index(y, x).clean_cell();
            has_teleported = true;
            return;
        }
    }
    // if there arent a portal pair
}
void Player::collect_powers(const Cell& cell) {
    if(cell.get_treasure()){
        has_treasure=true;
    }
    if (cell.getJumpWall()) {
        jump_wall_power++;
        jump_wall_grab = true;
    }
    if (cell.get_double_play()) {
        doublePlayPower = true;
    }
    if (cell.getControlEnemy()) {
        controlEnemyPower = true;
    }
}


void Player::update(){
    has_jumped = false;
    has_teleported = false;
    jump_wall_grab = false;
}
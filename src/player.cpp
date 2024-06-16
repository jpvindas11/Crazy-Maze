#include "player.h"
#include <iostream>
Player::Player(int x_start, int y_start) : x(x_start), y(y_start), map(nullptr), jumpWallPower(0) {}

void Player::handleMovement(char direction, Game_map& game_map) {

    switch (direction) {
        case 'd': // Derecha
            new_x += 1;
            break;
        case 'a': // Izquierda
            new_x -= 1;
            break;
        case 'w': // Arriba
            new_y -= 1;
            break;
        case 's': // Abajo
            new_y += 1;
            break;
    }

    update_pos(game_map);
}

bool Player::canMove(int new_X, int new_Y, Game_map& game_map) {
    if (new_X < 0 || new_X >= game_map.get_height() || new_Y < 0 || new_Y >= game_map.get_width()) {
        return false; // out of the map (juanpa hagale el colchon)
    }

    if (new_X < x && game_map.get_map_index(x, y).hasTopWall()) { // up
        if (jumpWallPower > 0) {
            int target_X, target_Y;
            if (canJumpWall(new_X, new_Y, target_X, target_Y, game_map)) {
                new_X = target_X;
                new_Y = target_Y;
                jumpWallPower--;
                return true;
            }
        }
        return false;
    }
    if (new_X > x && game_map.get_map_index(x, y).hasBottomWall()) { // down
        if (jumpWallPower > 0) {
            int target_X, target_Y;
            if (canJumpWall(new_X, new_Y, target_X, target_Y,game_map)) {
                new_X = target_X;
                new_Y = target_Y;
                jumpWallPower--;
                return true;
            }
        }
        return false;
    }
    if (new_Y < y && game_map.get_map_index(x, y).hasLeftWall()) { // left
        if (jumpWallPower > 0) {
            int target_X, target_Y;
            if (canJumpWall(new_X, new_Y, target_X, target_Y, game_map)) {
                new_X = target_X;
                new_Y = target_Y;
                jumpWallPower--;
                return true;
            }
        }
        return false;
    }
    if (new_Y > y && game_map.get_map_index(x, y).hasRightWall()) { // right
        if (jumpWallPower > 0) {
            int target_X, target_Y;
            if (canJumpWall(new_X, new_Y, target_X, target_Y,game_map)) {
                new_X = target_X;
                new_Y = target_Y;
                jumpWallPower--;
                return true;
            }
        }
        return false;
    }

    return true;
}

bool Player::canJumpWall(int new_X, int new_Y, int &target_X, int &target_Y, Game_map& game_map) {
    // left jump
    if (new_Y < y && game_map.get_map_index(x, y).hasLeftWall()) {
        target_X = x;
        target_Y = new_Y - 1;
    }
    // Saltar hacia la derecha
    if (new_Y > y && game_map.get_map_index(x, y).hasRightWall()) {
        target_X = x;
        target_Y = new_Y + 1;
    }
    // Saltar hacia arriba
    if (new_X < x && game_map.get_map_index(x, y).hasTopWall()) {
        target_X = new_X - 1;
        target_Y = y;
    }
    // Saltar hacia abajo
    if (new_X > x && game_map.get_map_index(x, y).hasBottomWall()) {
        target_X = new_X + 1;
        target_Y = y;
    }

    if (target_X >= 0 && target_X < game_map.get_height() && target_Y >= 0 && target_Y < game_map.get_width() &&
        !game_map.get_map_index(target_X, target_Y).hasTopWall() &&
        !game_map.get_map_index(target_X, target_Y).hasBottomWall() &&
        !game_map.get_map_index(target_X, target_Y).hasLeftWall() &&
        !game_map.get_map_index(target_X, target_Y).hasRightWall()) {
        return true;
    }

    return false;
}

void Player::teleport(Game_map& game_map) {
    for (int i = 0; i < game_map.get_height(); ++i) {
        for (int j = 0; j < game_map.get_width(); ++j) {
            if (game_map.get_map_index(i, j).getPortal() && (i != x || j != y)) {
                set_x(i);
                set_y(j);
                std::cout << "Teletransportado a: (" << i << ", " << j << ")" << std::endl;
                game_map.get_map_index(i, j).clean_cell();
                return;
            }
        }
    }
}

void Player::collectPowers(const Cell& cell) {
    if (cell.getJumpWall()) {
        jumpWallPower++;
        std::cout << "Poder de salto acumulado: " << jumpWallPower << std::endl;
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

bool Player::can_update_pos(Game_map& game_map) {
    if (canMove(new_x, new_y, game_map)) {
        set_x(new_x);
        set_y(new_y);
        collectPowers(game_map.get_map_index(new_x, new_y));
        game_map.get_map_index(new_x, new_y).clean_cell();
        if (game_map.get_map_index(new_x, new_y).getPortal()) {
            teleport(game_map);
        }
        return true; 
    }
    return false;
}

void Player::update_pos(Game_map& game_map) {
    if (can_update_pos(game_map)) { 
        set_x(new_x);
        set_y(new_y);
        has_moved = true;
    }
    new_x = 0; new_y = 0;
}
/*void Player::takeTurn(Game_map& game_map, char move_direction) { 
    handleMovement(move_direction);
}*/
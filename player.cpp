#include "player.h"


Player::Player(int x_start, int y_start) : x(x_start), y(y_start),  map(nullptr){
   
}
void Player::handleMovement(char direction, Game_map& game_map) {
    //map = &game_map;
    int new_X = x;
    int new_Y = y;

    switch (direction) {
        case 'd': // Derecha
            new_Y += 1;
            break;
        case 'a': // Izquierda
            new_Y -= 1;
            break;
        case 'w': // Arriba
            new_X -= 1;
            break;
        case 's': // Abajo
            new_X += 1;
            break;
    }

    update(new_X, new_Y);
}
bool Player::canMove(int new_X, int new_Y, Game_map& map){
    if (new_X < 0 || new_X >= map.get_height() || new_Y < 0 || new_Y >= map.get_width()) {
        return false; // out of the map (juanpa hagale el colchon)
    }

   
    if (new_X < x && map.get_map_index(x, y).hasTopWall()) { // up
        return false;
    }
    if (new_X > x && map.get_map_index(x, y).hasBottomWall()) { // down
        return false;
    }
    if (new_Y < y && map.get_map_index(x, y).hasLeftWall()) { // left
        return false;
    }
    if (new_Y > y && map.get_map_index(x, y).hasRightWall()) { //right
        return false;
    }

    return true;
}
bool Player::canJumpWall(int new_X, int new_Y, int &target_X, int &target_Y, Game_map& map) {
    // left jump
    if (new_Y < y && map.get_map_index(x, y).hasLeftWall()) {
        target_X = x;
        target_Y = new_Y - 1;
    }
    // Saltar hacia la derecha
    if (new_Y > y && map.get_map_index(x, y).hasRightWall()) {
        target_X = x;
        target_Y = new_Y + 1;
    }
    // Saltar hacia arriba
    if (new_X < x && map.get_map_index(x, y).hasTopWall()) {
        target_X = new_X - 1;
        target_Y = y;
    }
    // Saltar hacia abajo
    if (new_X > x && map.get_map_index(x, y).hasBottomWall()) {
        target_X = new_X + 1;
        target_Y = y;
    }

    if (target_X >= 0 && target_X < map.get_height() && target_Y >= 0 && target_Y < map.get_width() &&
        !map.get_map_index(target_X, target_Y).hasTopWall() &&
        !map.get_map_index(target_X, target_Y).hasBottomWall() &&
        !map.get_map_index(target_X, target_Y).hasLeftWall() &&
        !map.get_map_index(target_X, target_Y).hasRightWall()) {
        return true;
    }

    return false;
}
void Player::teleport(Game_map& map) {
    for (int i = 0; i < map.get_height(); ++i) {
        for (int j = 0; j < map.get_width(); ++j) {
            if (map.get_map_index(i, j).getPortal() && (i != x || j != y)) {
                set_x(i);
                set_y(j);
                std::cout << "Teletransportado a: (" << i << ", " << j << ")" << std::endl;
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
}
bool Player::boolUpdate(int new_X, int new_Y, Game_map& map) {
    if (canMove(new_X, new_Y, map)) {
        set_x(new_X);
        set_y(new_Y);
        collectPowers(map.get_map_index(new_X, new_Y));
        if (map.get_map_index(new_X, new_Y).getPortal()) {
            teleport(map);
        }
        return true; 
    }
    return false;
}

void Player::update(int new_X, int new_Y) {
    if (boolUpdate(new_X, new_Y, *map)) { 
        set_x(new_X);
        set_y(new_Y);
    }
}

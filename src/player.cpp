#include "player.h"

Player::Player(int x_start, int y_start) : x(x_start), y(y_start){}

void Player::update(int new_X,int new_Y){
    
    this->set_x(new_X);
    this->set_y(new_Y);
    
}



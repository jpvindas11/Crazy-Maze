#include "player.h"

void Player::init(int x_start, int y_start, int img_speed_start){
    x = x_start; 
    y = y_start; 
    image_speed = img_speed_start;
}

void Player::update(){
    
}

void Player::animation(){

	image_index++;

	if (image_index > image_speed) {
		
		if (image_frame >= image_length-1) {
			image_frame = 0;
		}
		else { image_frame++; }

		image_index = 0;
	}

}
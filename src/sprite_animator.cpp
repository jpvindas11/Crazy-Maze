#include "sprite_animator.h"

void animation(int& image_frame, int& image_index, int& image_speed, int& image_length){

	if (image_speed != 0){
		image_index++;

		if (image_index > image_speed) {
			
			if (image_frame >= image_length-1) {
				image_frame = 0;
			}
			else { image_frame++; }

			image_index = 0;
		}
	} else {image_frame = 0;}
}
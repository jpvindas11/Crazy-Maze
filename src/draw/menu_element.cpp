#include "menu_element.h"
#include "iostream"

void Menu_element::init(const char* sprite, SDL_Renderer* ren, 
    int img_speed, int img_length, int x_start, int y_start, int x_hide, int y_hide, 
    int width, int height, int state, int screen_width, int screen_height){

    tex = load_texture(sprite,ren);

    width_mult =  1;//int(screen_width/BASE_SCREEN_WIDTH);
    height_mult = 1;//int(screen_height/BASE_SCREEN_HEIGHT);

    set_rect(rect, x_start, y_start, width, height);
    set_rect(spr, 0, 0, width, height);

    x = base_x = x_start;
    y = base_y = y_start;
    base_state = state;

    base_width = width;
    base_height = height;

    hide_x = x_hide; 
    hide_y = y_hide;

    state_index = 0;
    image_speed = img_speed;
    image_length = img_length;
    image_frame = image_index = 0;

}

void Menu_element::update(int game_state){
    if (game_state == base_state){
        move(base_x, base_y);
    }
    else {move(hide_x, hide_y);}
    set_rect(spr, base_width*image_frame, 0, base_width*width_mult, base_height*height_mult);
}

void Menu_element::move(int next_x, int next_y){
    if (x > next_x*width_mult) {x-=SPEED;}
    else if (x < next_x*width_mult) {x+=SPEED;}
    else if (next_x*width_mult-SPEED < x < next_x*width_mult+SPEED) {x = next_x*width_mult;}


    if (y > next_y*height_mult) {y-=SPEED;}
    else if (y < next_y*height_mult) {y+=SPEED;}
    else if (next_y*height_mult-SPEED < y < next_y*height_mult+SPEED) {y = next_y*height_mult;}

    set_rect(rect, int(x), int(y), base_width*width_mult, base_height*height_mult);
}

void Menu_element::set_frame(int frame){
    image_frame = frame;
}
void Menu_element::render(SDL_Renderer* ren){
    SDL_RenderCopy(ren, tex, &spr, &rect);
}
#include "item_draw.h"

void Item_draw::init(const char* texture, SDL_Renderer* renderer, int tile, int img_speed, int img_length){

    tile_size = tile;

    frame_width = 16; frame_height = 16;
    width = tile; height = tile;
    

    pw_texture = load_texture(texture,renderer);
    set_rect(rect, 0, 0, width, height);
    set_rect(spr, 0, 0, frame_width, frame_height);

    image_frame = 0;
    image_speed = img_speed;
    image_length = img_length;
    image_index = 0;

}

void Item_draw::update(int new_x, int new_y){
    rect.x = new_x; rect.y = new_y;
}

void Item_draw::render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, pw_texture, &spr, &rect);
}

void Item_draw::play_animation(){
    animation(image_frame, image_index, image_speed, image_length);
    spr.x = image_frame*frame_width;
}
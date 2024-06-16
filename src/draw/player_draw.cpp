#include "player_draw.h"


void Player_draw::init(const char* texture, SDL_Renderer* renderer, int tile, int x_off, int y_off){

    player_tex = load_texture(texture,renderer);

    tile_size = tile;
    p_offset = (4)*(tile_size/16);

    width = tile;
    height = tile+p_offset;

    frame_width = P_FRAME_WIDTH;
    frame_height = P_FRAME_HEIGHT;

    x_offset = x_off; y_offset = y_off;

    set_rect(player_rect, 0, 0, width, height);
    set_rect(player_spr, 0, 0, frame_width, frame_height);

    image_frame = 0;
    image_speed = 0;
    image_length = 4;
    image_index = 0;
    action_index = 0;
}

void Player_draw::update(int next_x, int next_y){
    player_rect.x = (next_x+x_offset)*tile_size;
    player_rect.y = ((next_y+y_offset)*tile_size)-p_offset;
}

void Player_draw::render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, player_tex, &player_spr, &player_rect);
}

void Player_draw::jump(){
    
}

void Player_draw::set_skin(const char* texture , SDL_Renderer* renderer){
    player_tex = load_texture(texture,renderer);
}
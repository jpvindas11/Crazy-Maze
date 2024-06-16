#include "background.h"

void Background::init(int TILE_SIZE, int SCREEN_W, int SCREEN_H){
    tile_size = TILE_SIZE;
    screen_width = SCREEN_W;
    screen_height = SCREEN_H;

    bg_rect.w = tile_size; bg_rect.h = tile_size;
    bg_rect.x = 0; bg_rect.y = 0;
}


void Background::load_bg(const char* new_bg, SDL_Renderer* ren){
    background = load_texture(new_bg,ren);
}

void Background::draw(SDL_Renderer* ren){
    for (int i = 0; i < screen_height/tile_size + 1; ++i){
        for (int j = 0; j < screen_width/tile_size + 1; ++j){

            bg_rect.x = j*tile_size; bg_rect.y = i*tile_size;
            SDL_RenderCopy(ren, background, NULL, &bg_rect);
        }
    }
}
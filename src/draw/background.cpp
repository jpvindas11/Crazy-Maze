#include "background.h"

void Background::init(std::vector<SDL_Texture*> backgrounds, int TILE_SIZE, int SCREEN_W, int SCREEN_H){

    background = backgrounds[0];
    tile_size = TILE_SIZE;
    screen_width = SCREEN_W;
    screen_height = SCREEN_H;

    bg_rect.w = tile_size; bg_rect.h = tile_size;
    bg_rect.x = 0; bg_rect.y = 0;
    x = 0;
}


void Background::load_bg(std::vector<SDL_Texture*> backgrounds, int index){
    background = backgrounds[index];
}

void Background::move(bool can_move){
    if (can_move){
        if (x <= tile_size){
            if (x!=tile_size){++x;}
            else {x = 0;}
        }
    } else {x=0;}
}

void Background::draw(SDL_Renderer* ren){
    for (int i = -2; i < screen_height/tile_size + 1; ++i){
        for (int j = -2; j < screen_width/tile_size + 1; ++j){

            bg_rect.x = j*tile_size+x; bg_rect.y = i*tile_size;
            SDL_RenderCopy(ren, background, NULL, &bg_rect);
        }
    }
}

Background::~Background(){};
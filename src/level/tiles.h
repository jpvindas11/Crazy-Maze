#ifndef TILES_H
#define TILES_H

#include "sdl/SDL.h"
#include "sdl/SDL_image.h"
#include "../texture_loader.h"
#include "../game_map.h"

class Tiles{

public:
    Tiles(){}
    ~Tiles(){}

    void init(int TILE_SIZE, int SCREEN_W, int SCREEN_H, int MAP_W, int MAP_H);
    void load_tile_set(const char* new_tile_set, SDL_Renderer* ren);
    void draw(SDL_Renderer* ren, Game_map& game_map);
    
private:

    SDL_Texture * tile_tex;
    SDL_Rect tile_rect;
    SDL_Rect tile_spr;


private:
    int x_offset, y_offset;
    int tile_size;
    int screen_width, screen_height;
};


#endif
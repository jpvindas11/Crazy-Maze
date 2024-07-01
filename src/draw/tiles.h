#ifndef TILES_H
#define TILES_H

#define BOTTOM_W 16
#define TOP_W 32
#define RIGHT_W 48
#define LEFT_W 64

#define ORB_ELEVATION 24

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../texture_loader.h"
#include "../game_map.h"
#include "item_draw.h"
#include "vector"

class Tiles{

public:
    Tiles(){}
    ~Tiles(){}

    void init(std::vector<SDL_Texture*> grounds, int TILE_SIZE, int SCREEN_W, int SCREEN_H, int MAP_W, int MAP_H);
    void load_power_ups(SDL_Renderer* ren);
    void set_tile_set(std::vector<SDL_Texture*> grounds, int index);
    void draw(SDL_Renderer* ren, Game_map& game_map);
    
private:

    SDL_Texture * tile_tex;
    SDL_Rect tile_rect;
    SDL_Rect tile_spr;

    Item_draw jump_wall;
    Item_draw control_enemy;
    Item_draw double_move;
    Item_draw portal;

    Item_draw orb;


private:
    int x_offset, y_offset;
    int tile_size;
    int screen_width, screen_height;
    int orb_x, orb_y;
    bool orb_gotten;
};


#endif
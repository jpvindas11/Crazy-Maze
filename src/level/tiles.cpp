#include "tiles.h"
#include "iostream"

void Tiles::init(int TILE_SIZE, int SCREEN_W, int SCREEN_H, int X_OFF, int Y_OFF){
    tile_size = TILE_SIZE;
    screen_width = SCREEN_W;
    screen_height = SCREEN_H;

    x_offset = X_OFF;
    y_offset = Y_OFF;

    tile_rect.x = 0; tile_rect.y = 0;
    tile_rect.w = tile_size; tile_rect.h = tile_size;

    tile_spr.x = 0; tile_spr.y = 0;
    tile_spr.w = tile_size; tile_spr.h = tile_size;

}

void Tiles::load_tile_set(const char* new_tile_set, SDL_Renderer* ren){
    tile_tex = load_texture(new_tile_set,ren);
}

void Tiles::draw(SDL_Renderer* ren, Game_map& game_map){

    for (int i = 0; i < game_map.get_height(); ++i){
        for (int j = 0; j < game_map.get_width(); ++j){

            //Position tile
            tile_rect.x = (j+x_offset)*tile_size; 
            tile_rect.y = (i+y_offset)*tile_size;

            //Select tile
            tile_spr.x = (game_map.get_map_index(i,j)*16);
            //Draw tile
            SDL_RenderCopy(ren, tile_tex, &tile_spr, &tile_rect);
        }
    }
}
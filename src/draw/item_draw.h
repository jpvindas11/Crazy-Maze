#ifndef ITEM_DRAW_H
#define ITEM_DRAW_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../sprite_animator.h"
#include "../texture_loader.h"


class Item_draw{
    
public:

    Item_draw(){};
    ~Item_draw(){};

    void init(const char* texture, SDL_Renderer* renderer, int tile, int image_speed, int image_length);
    void update(int new_x, int new_y);
    void play_animation();
    void render(SDL_Renderer* renderer);

private:

    SDL_Texture* pw_texture;
    SDL_Rect rect;
    SDL_Rect spr;

    int x , y;
    int width, height;
    int frame_width, frame_height;
    int tile_size;

    int image_frame;
    int image_index;
    int image_speed;
    int image_length;
};


#endif
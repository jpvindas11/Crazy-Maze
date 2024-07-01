#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../texture_loader.h"
#include "vector"

class Background{

public:
    Background(){}
    ~Background();

    void init(std::vector<SDL_Texture*> backgrounds, int TILE_SIZE, int SCREEN_W, int SCREEN_H);
    void load_bg(std::vector<SDL_Texture*> backgrounds, int index);
    void draw(SDL_Renderer* ren);
    void move(bool can_move);
    
private:
    int tile_size;
    int screen_width, screen_height;
    int x;

    SDL_Texture * background;
    SDL_Rect bg_rect;
};


#endif
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "sdl/SDL.h"
#include "sdl/SDL_image.h"
#include "../texture_loader.h"

class Background{

public:
    Background(){}
    ~Background(){}

    void init(int TILE_SIZE, int SCREEN_W, int SCREEN_H);
    void load_bg(const char* new_bg, SDL_Renderer* ren);
    void draw(SDL_Renderer* ren);
    
private:
    int tile_size;
    int screen_width, screen_height;
    const char* current_background;

    SDL_Texture * background;
    SDL_Rect bg_rect;
};


#endif
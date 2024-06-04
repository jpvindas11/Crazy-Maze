#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include "sdl/SDL.h"
#include "sdl/SDL_image.h"

SDL_Texture* load_texture(const char* file, SDL_Renderer* renderer);
    
#endif
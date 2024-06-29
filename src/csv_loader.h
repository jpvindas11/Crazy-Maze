#ifndef CSV_LOADER_H
#define CSV_LOADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture_loader.h"


void load_textures_from_csv(const char* filename, SDL_Renderer* renderer, std::vector<SDL_Texture*>& textures);
int count_lines_from_csv(const char* filename);
#endif
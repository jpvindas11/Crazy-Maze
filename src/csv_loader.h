#ifndef CSV_LOADER_H
#define CSV_LOADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "texture_loader.h"


void load_textures_from_csv(const char* filename, SDL_Renderer* renderer, std::vector<SDL_Texture*>& textures);
void load_sounds_from_csv(const char* filename, std::vector<Mix_Chunk*>& sounds);
void load_music_from_csv(const char* filename, std::vector<Mix_Music*>& music);
int count_lines_from_csv(const char* filename);

#endif
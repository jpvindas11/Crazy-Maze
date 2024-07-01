#include "csv_loader.h"

void load_textures_from_csv(const char* filename, SDL_Renderer* renderer, std::vector<SDL_Texture*>& textures) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        const char* texture_path = line.c_str();
        SDL_Texture* texture = load_texture(texture_path, renderer);
        textures.push_back(texture);
    }

    file.close();
}

void load_sounds_from_csv(const char* filename, std::vector<Mix_Chunk*>& sounds) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        const char* sound_path = line.c_str();
        Mix_Chunk* sound = Mix_LoadWAV(sound_path);
        sounds.push_back(sound);
    }

    file.close();
}

void load_music_from_csv(const char* filename, std::vector<Mix_Music*>& music) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        const char* track_path = line.c_str();
        Mix_Music* track = Mix_LoadMUS(track_path);
        music.push_back(track);
    }
    file.close();
}

int count_lines_from_csv(const char* filename){
    int count = 0;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        ++count;
    }

    file.close();
    return count;
}
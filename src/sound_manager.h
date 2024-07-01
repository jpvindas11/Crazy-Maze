#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#define JUMP_SFX 0
#define CONTROL_SFX 1
#define POWER_SFX 2
#define MENU_MOVE_SFX 3
#define MENU_SELECT_SFX 4
#define WARP_SFX 5

#define MENU_MUS 0
#define DEFAULT_MUS 1
#define POISON_MUS 2
#define DESERT_MUS 3
#define CAVE_MUS 4
#define VICTORY_INTRO_MUS 5
#define VICTORY_MUS 6

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "vector"
#include "csv_loader.h"
#include "player.h"
#include "controls.h"

class Sound_manager{

public:
    void init();
    void play_player(Player& player);
    void play_menu(Controls& controls);

    void play_sound(int id);
    void play_music(int id, int map, bool win);
    void quit();

private:
    
    int current_music;
    int playing_music;

    std::vector<Mix_Chunk*> sounds;
    std::vector<Mix_Music*> music;

};
#endif
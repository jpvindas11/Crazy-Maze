#include "sound_manager.h"

void Sound_manager::init(){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    load_sounds_from_csv("assets/sounds/sounds.csv", sounds);
    load_music_from_csv("assets/music/music.csv", music);

    current_music = -100; playing_music = -99;
}

void Sound_manager::play_player(Player& player){
    if (player.get_jumped() == true){
        play_sound(JUMP_SFX);
    }
    if (player.hasControlEnemy() == true){
        play_sound(CONTROL_SFX);
    }
    if (player.hasDoublePlay() == true || player.get_jump_wall_grab() == true ){
        play_sound(POWER_SFX);
    }
    if (player.get_teleported() == true){
        play_sound(WARP_SFX);
    }
}

void Sound_manager::play_menu(Controls& controls){
    if(controls.get_menu_input() != 'n' || controls.get_space() == true){
        play_sound(MENU_MOVE_SFX);
    }
    if(controls.get_enter() == true){
        play_sound(MENU_SELECT_SFX);
    }
}

void Sound_manager::play_sound(int index){
    Mix_PlayChannel(index, sounds[index], 0);
}

void Sound_manager::play_music(int index, int map, bool win){

    if (index == 0 || index == 1){
        current_music = MENU_MUS;
    }
    else if (index == 2) {
        if (!win){
            if (map == 0) {current_music = DEFAULT_MUS;}
            else if (map == 1) {current_music = POISON_MUS;}
            else if (map == 2) {current_music = DESERT_MUS;}
            else if (map == 3) {current_music = CAVE_MUS;}
        }

        else {
            current_music = VICTORY_INTRO_MUS;
        }
    }
    else if (index == 3) {
        current_music = VICTORY_MUS;
    }

    if (current_music != playing_music){
        playing_music = current_music;
        Mix_PlayMusic(music[current_music], -1);
    }
}

void Sound_manager::quit(){
    for (Mix_Chunk* sound : sounds) {Mix_FreeChunk(sound);}
    sounds.clear();
    for (Mix_Music* track: music) {Mix_FreeMusic(track);}
    sounds.clear();
    Mix_Quit();
}
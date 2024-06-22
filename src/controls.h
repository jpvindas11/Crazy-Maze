#ifndef CONTROLS_H
#define CONTROLS_H

#include "SDL2/SDL.h"

class Controls{

public:
    void input_game(int turn, bool control_enemy);
    void input_menu();
    char get_player_input () {return player_input;}

    bool get_space() {return space;}
    bool get_enter() {return enter;}

private:

    SDL_Event control_event;

    char player_input;
    bool enter;
    bool space;

};


#endif
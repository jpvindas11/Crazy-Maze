#ifndef CONTROLS_H
#define CONTROLS_H

#include "SDL2/SDL.h"

class Controls{

public:
    void input_game(int turn);
    void input_menu();
    char get_player_input () {return player_input;}

private:

    SDL_Event control_event;

    char player_input;

};


#endif
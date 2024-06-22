#ifndef MENU_H
#define MENU_H

#define DONT_SWAP -1
#define MAIN_MENU 0
#define SELECTION_MENU 1
#define GAME_GOING 2
#define GAME_END 3

#define SECOND 60

#define TITLE_WAIT 1*SECOND

#include "controls.h"

class Menu{

public:

    Menu();
    ~Menu(){};

    void title_screen(Controls& controller);
    void selection_screen(Controls& controller);
    void game_end_screen(Controls& controller);
    void update_screen(int& game_state);

private:

    int screen;
    int timer;
};

#endif
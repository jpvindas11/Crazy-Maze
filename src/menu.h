#ifndef MENU_H
#define MENU_H

#define DONT_SWAP -2
#define INTRO -1
#define MAIN_MENU 0
#define SELECTION_MENU 1
#define GAME_GOING 2
#define GAME_END 3

#define SECOND 60

#define TITLE_WAIT 1
#define WIN_WAIT 120

#include "controls.h"
#include "csv_loader.h"

class Menu{

public:

    Menu();
    ~Menu(){};

    void title_screen(Controls& controller);
    void selection_screen(Controls& controller);
    void game_end_screen(Controls& controller);

    void move_selection(Controls& controller);
    void update_skins(int& player_skin_index);
    void update_screen(int& game_state);
    void update_map();
    bool check_win(bool won);

    int get_player1_skin_index ();
    int get_player2_skin_index ();
    int get_current_map ();

private:

    int screen;
    int timer;

    int skin_amount;
    int map_amount;
    int player1_skin_index;
    int player2_skin_index;
    int map_index;

};

#endif
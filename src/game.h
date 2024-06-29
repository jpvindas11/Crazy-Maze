#ifndef GAME_H
#define GAME_H

#define SECOND 60
#define TURN_WAIT 6

#define MAP_WIDTH 36
#define MAP_HEIGTH 20

#include "iostream"
#include "graphics.h"
#include "player.h"
#include "game_map.h"
#include "controls.h"
#include "menu.h"

class Game{

public:

    Game();
    ~Game(){};
    void set_turns(int turn);
    void initialize_game();
    void run_game();
    void run_timer();

private:

    Menu menu;
    Graphics graphics;
    Game_map game_map;
    Controls controller;

    Player player1;
    Player player2;
    Player *p_pointer;
    
    void handle_turns();
    int turn;
    int frame;

    int game_state;
    int timer;

    bool control_enemy;

};

#endif
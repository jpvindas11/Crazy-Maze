#ifndef GAME_H
#define GAME_H

#include "iostream"
#include "graphics.h"
#include "player.h"
#include "game_map.h"
#include "controls.h"

class Game{

public:

    Game();
    ~Game(){};

    void initialize_game();
    void run_game();

private:

    Graphics graphics;
    Game_map game_map;
    Controls controller;

    Player player1;
    Player player2;
    Player *p_pointer;
    
    void handle_turns();
    int turn;
    int frame;

};

#endif
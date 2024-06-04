#ifndef GAME_H
#define GAME_H

#include "iostream"
#include "graphics.h"
#include "player.h"
#include "game_map.h"

class Game{

public:

    Game() : game_map(30,15) {};
    ~Game(){};

    void initialize_game();
    void run_game();
    bool is_running() { return game_running; }

private:

    Graphics graphics;
    Game_map game_map;
    Player player1;
    Player player2;

    bool game_running = graphics.running();

};

#endif
#ifndef GAME_H
#define GAME_H

#include "iostream"
#include "graphics.h"
#include "player.h"
#include "game_map.h"

class Game{

public:

    Game();
    ~Game(){};

    void initialize_game();
    void run_game();
    bool is_running() { return game_running; }

private:

    Graphics graphics;
    Game_map game_map;
    Player player1;
    Player player2;
    void handleTurn(Player& player, const std::string& playerName); 
    bool game_running = graphics.running();

};

#endif
#ifndef GAME_H
#define GAME_H

#include "iostream"
#include "graphics.h"
#include "player.h"
#include "game_map.h"
#include <unistd.h>
#include <termios.h>

class Game{

public:

    Game();
    ~Game(){};

    void initialize_game();
    void run_game();
    inline bool is_running() { return game_running; }
    void movePlayer();
    void reset_terminal_mode();
    void set_terminal_mode();

private:

    Graphics graphics;
    Game_map game_map;
    Player player1;
    Player player2;

    bool game_running = graphics.running();

};

#endif
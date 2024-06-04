#include "game.h"

void Game::initialize_game(){

    player1.init(0,0,6);
    player2.init(0,0,8);
    graphics.init(player1,player2,game_map);

}

void Game::run_game(){

    while (graphics.running()){
        graphics.update(player1,player2,game_map);
    }
    graphics.clean();

}
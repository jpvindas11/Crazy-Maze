#include "game.h"

Game::Game() : game_map(30,15), player1(0,0), player2(2,2) {
    initialize_game();
};

void Game::initialize_game(){

    graphics.init(player1,player2,game_map);

}

void Game::run_game(){

    while (graphics.running()){
        graphics.update(player1,player2,game_map);
    }
    graphics.clean();

}
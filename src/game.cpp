#include "game.h"

Game::Game() : game_map(36,20), player1(0,0), player2(2,2) {
    initialize_game();
};

void Game::initialize_game(){

    graphics.init(player1,player2,game_map);

    turn = 1;
    frame = 0;

    p_pointer = &player1;

}

void Game::run_game() {

    while (graphics.running() == true) {

        frame++;

        handle_turns();

        graphics.update(player1, player2, game_map);
    }
}

void Game::handle_turns() {

    controller.input_game(turn);

    if (turn == 1) {p_pointer = &player1;}
    else if (turn == 2) {p_pointer = &player2;}

    if (p_pointer->get_if_moved() == false){
        p_pointer->handle_movement(controller.get_player_input(),game_map);
    } else {
        if (turn == 1) {turn = 2;}
        else {turn = 1;}
        p_pointer->set_has_moved(false);
    }
}
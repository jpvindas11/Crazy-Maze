#include "game.h"

Game::Game() : game_map(35,20), player1(0,0), player2(2,2) {
    initialize_game();
};

void Game::initialize_game(){

    graphics.init(player1,player2,game_map);

    turn = 1;
    frame = 0;

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

    if (frame%60 == 0){printf("(%i , %i)    ", p_pointer->get_x(), p_pointer->get_y());}

    if (p_pointer->get_if_moved() == false){
        p_pointer->handleMovement(controller.get_player_input(),game_map);
    } else {
        if (turn == 1) {turn = 1;}
        else {turn = 1;}
        p_pointer->set_has_moved(false);
    }
    

    /* Comentado porque hay que acomodarlo para que actué en ciclo
    player.takeTurn(game_map, controller);

    if (player.hasDoublePlay()) {
        player.useDoublePlay(); //once the power is used this funtion set that power in false
        player.takeTurn(game_map, controller);
    }
    // we have to see how to change controls, this code is like sergio said "the patito" code for the moment
     if (player.hasControlEnemy()) {
        player.useControlEnemy();
        if (playerName == "Player 1") {
            player2.takeTurn(game_map, controller);
        } else {
            player1.takeTurn(game_map, controller);
        }
    }
    */
}


/*
    while (graphics.running()){
        graphics.update(player1,player2,g
            newX=x+1;ame_map);
    }
    graphics.clean();*/



//para mover jugador desde la terminal
//juanpa ni lo vea
/*
void Game::movePlayer()
{
    
    set_terminal_mode();
    
    char ch;
    int x=player1.get_x();
    int y=player1.get_y();
    
    while (true) {
        ch = getchar();
                
        if (ch == '\033') {
            getchar(); // Saltar el '['
            switch(getchar()) {
                case 'A': // Flecha arriba
                    if (x > 0) --x;
                    break;
                case 'B': // Flecha abajo
                    if (x < 4) ++x;
                    break;
                case 'C': // Flecha derecha
                    if (y < 4) ++y;
                    break;
                case 'D': // Flecha izquierda
                    if (y > 0) --y;
                    break;
            }
        }
        player1.update(x,y);
        printf("p1: %d,%d\n",player1.get_x(), player1.get_y());

    }

    reset_terminal_mode();
}

void Game::reset_terminal_mode() {
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &new_termios);
    new_termios.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void Game::set_terminal_mode() {
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &new_termios);
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}*/

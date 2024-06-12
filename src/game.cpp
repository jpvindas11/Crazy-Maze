#include "game.h"

Game::Game() : game_map(5,5), player1(0,0), player2(2,2) {
    initialize_game();
};

void Game::initialize_game(){

    graphics.init(player1,player2,game_map);

}

void Game::handleTurn(Player& player, const std::string& playerName) {
    std::cout << playerName << "turn" << std::endl;
    player.takeTurn(game_map);
    if (player.hasDoublePlay()) {
        std::cout << playerName << " has a double play. Taking another turn" << std::endl;
        player.useDoublePlay(); //once the power is used this funtion set that power in false
        player.takeTurn(game_map);
    }
    // we have to see how to change controls, this code is like sergio said "the patito" code for the moment
     if (player.hasControlEnemy()) {
        std::cout << playerName << " got control enemy power. Controlling the opponent" << std::endl;
        player.useControlEnemy();
        if (playerName == "Player 1") {
            player2.takeTurn(game_map);
        } else {
            player1.takeTurn(game_map);
        }
    }
}

void Game::run_game() {
    bool player1_turn = true; // Player 1 starts

    while (true) {
        game_map.print_map();
        printf("p1: %d,%d\n", player1.get_x(), player1.get_y());
        printf("p2: %d,%d\n", player2.get_x(), player2.get_y());

        if (player1_turn) {
            handleTurn(player1, "Player 1");
        } else {
            handleTurn(player2, "Player 2");
        }

        player1_turn = !player1_turn; // Switch turns
    }
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

#include "game.h"

Game::Game() : game_map(5,5), player1(0,0), player2(2,2) {
    initialize_game();
};

void Game::initialize_game(){

    graphics.init(player1,player2,game_map);

}

void Game::run_game(){


    //game_map.printMap2();
    printf("p1: %d,%d\n",player1.get_x(), player1.get_y());

    //movePlayer();



/*
    while (graphics.running()){
        graphics.update(player1,player2,g
            newX=x+1;ame_map);
    }
    graphics.clean();*/

}

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

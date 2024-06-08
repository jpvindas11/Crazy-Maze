#include "game.h"

Game::Game() : game_map(5,5), player1(0,0), player2(2,2) {
    initialize_game();
};

void Game::initialize_game(){

    graphics.init(player1,player2,game_map);

}

void Game::run_game(){


    game_map.printMap2();

    //movePlayer();



/*
    while (graphics.running()){
        graphics.update(player1,player2,game_map);
    }
    graphics.clean();*/

}

/*
void Game::movePlayer()
{
    
   set_terminal_mode();
    
    game_map.print_map();

    
    char ch;
    int x=player1.get_x();
    int y=player1.get_y();
    
    while (true) {
        ch = getchar();
        
        game_map.setMap(x,y,0);
        
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
        game_map.setMap(x,y,5);
        game_map.print_map();
    }

    reset_terminal_mode();
}*/

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
}

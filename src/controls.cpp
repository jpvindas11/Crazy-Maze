#include "controls.h"
#include "iostream"

void Controls::input_game(int turn){

    player_input = 'n';

    if (SDL_PollEvent( &control_event )){

        if (control_event.type == SDL_KEYDOWN){

            if (turn == 1){
                //Player 1
                if (control_event.key.keysym.sym == SDLK_d){
                    player_input = 'd';
                    printf("%c",player_input);
                }
                if (control_event.key.keysym.sym == SDLK_a){
                    player_input = 'a';
                    printf("%c",player_input);
                }
                if (control_event.key.keysym.sym == SDLK_w){
                    player_input = 'w';
                    printf("%c",player_input);
                }
                if (control_event.key.keysym.sym == SDLK_s){
                    player_input = 's';
                    printf("%c",player_input);
                }
            }

            else if (turn == 2){
                //Player 2
                if (control_event.key.keysym.sym == SDLK_RIGHT){
                    player_input = 'd';
                }
                if (control_event.key.keysym.sym == SDLK_LEFT){
                    player_input = 'a';
                }
                if (control_event.key.keysym.sym == SDLK_UP){
                    player_input = 'w';
                }
                if (control_event.key.keysym.sym == SDLK_DOWN){
                    player_input = 's';
                }
            }
        }
    }
}  
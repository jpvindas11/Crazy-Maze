#include "controls.h"

void Controls::input_game(int turn, bool control_enemy){

    player_input = 'n';

    if (SDL_PollEvent( &control_event )){

        if (control_event.type == SDL_KEYDOWN){

            if (turn == 1 && !control_enemy || turn == 2 && control_enemy){
                //Player 1
                if (control_event.key.keysym.sym == SDLK_d){
                    player_input = 'd';
                }
                if (control_event.key.keysym.sym == SDLK_a){
                    player_input = 'a';
                }
                if (control_event.key.keysym.sym == SDLK_w){
                    player_input = 'w';
                }
                if (control_event.key.keysym.sym == SDLK_s){
                    player_input = 's';
                }
            }

            if (turn == 2 && !control_enemy || turn == 1 && control_enemy){
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

void Controls::input_menu(){

    enter = false; space = false;

    if (SDL_PollEvent( &control_event )){
        if (control_event.type == SDL_KEYDOWN){
            if (control_event.key.keysym.sym == SDLK_RETURN){
                enter = true;
            }
            if (control_event.key.keysym.sym == SDLK_SPACE){
                space = true;
            }
        }
    }
}
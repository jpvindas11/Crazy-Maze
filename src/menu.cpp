#include "menu.h"

Menu::Menu(): screen(MAIN_MENU) {};

void Menu::title_screen(Controls& controller){
    if (controller.get_enter()){
        screen = SELECTION_MENU;
        timer = TITLE_WAIT;
    }
}

void Menu::selection_screen(Controls& controller){
    if (controller.get_enter()){
        screen = GAME_GOING;
    } 
}

void Menu::game_end_screen(Controls& controller){
    if (controller.get_enter()){
        screen = SELECTION_MENU;
    }
}

void Menu::update_screen(int& game_state){

    if (timer != 0) {timer--;}

    if ((screen != DONT_SWAP) && timer == 0){
        game_state = screen;
        screen = DONT_SWAP;
    }
}
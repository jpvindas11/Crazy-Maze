#include "menu.h"

Menu::Menu(): screen(MAIN_MENU), player1_skin_index(0), player2_skin_index(1), map_index(0) {
    skin_amount = count_lines_from_csv("assets/skins/skins.csv");
    map_amount = count_lines_from_csv("assets/maps/ground.csv");
};

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
    move_selection(controller);
    update_skins(player1_skin_index);
    update_skins(player2_skin_index);
    update_map();
}

void Menu::game_end_screen(Controls& controller){
    if (controller.get_enter()){
        screen = SELECTION_MENU;
    }
}

bool Menu::check_win(bool won){
    if (timer == 0){
        if (won == true){   
            timer = WIN_WAIT;
            screen = GAME_END;
        }
    }
    return won;
}

void Menu::move_selection(Controls& controller){

    if (controller.get_menu_input() == 'a'){
        player1_skin_index --;
    }
    if (controller.get_menu_input() == 'd'){
        player1_skin_index ++;
    }
    if (controller.get_menu_input() == 'l'){
        player2_skin_index --;
    }
    if (controller.get_menu_input() == 'r'){
        player2_skin_index ++;
    }

    if (controller.get_space() == true){
        map_index++;
    }
}

void Menu::update_skins(int& player_skin_index){
    if (player_skin_index < 0){player_skin_index = skin_amount-1;}
    if (player_skin_index > skin_amount-1){player_skin_index = 0;}
}

void Menu::update_map(){
    if (map_index > map_amount-1){map_index = 0;}
}

void Menu::update_screen(int& game_state){

    if (timer != 0) {timer--;}

    if ((screen != DONT_SWAP) && timer == 0){
        game_state = screen;
        screen = DONT_SWAP;
    }
}

int Menu::get_player1_skin_index () {return player1_skin_index;}
int Menu::get_player2_skin_index () {return player2_skin_index;}
int Menu::get_current_map() {return map_index;}
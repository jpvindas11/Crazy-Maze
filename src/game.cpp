#include "game.h"

Game::Game() : game_map(MAP_WIDTH,MAP_HEIGHT), player1(MAP_WIDTH,MAP_HEIGHT), player2(MAP_WIDTH,MAP_HEIGHT), frame(0) {
    
    initialize_game();
};

void Game::initialize_game(){

    graphics.init(player1,player2,game_map);
    sound_manager.init();

    turn = 1;
    timer = 0;
    restarted = false;
    game_state = TITLE;

    p_pointer = &player1;
    control_enemy = false;

}

void Game::run_game() {

    while (graphics.running() == true) {

        frame++;
        run_timer();

        if (game_state == IN_GAME){controller.input_game(turn, control_enemy);}
        else controller.input_menu();

        if (game_state == TITLE){
            menu.title_screen(controller);
        }
        else if (game_state == SELECTION_MENU){
            menu.selection_screen(controller);
            if (restarted){
                game_map.start_generation(MAP_WIDTH,MAP_HEIGHT);
                player1.reset_position(MAP_WIDTH,MAP_HEIGHT);
                player2.reset_position(MAP_WIDTH,MAP_HEIGHT);
                turn = 1;
                restarted = false;
                game_won = false;
            }
        }
        else if (game_state == IN_GAME) {
            player1.update(); player2.update();
            if (!game_won) handle_turns();
        }
        else if (game_state == GAME_END){
            menu.game_end_screen(controller);

            if (!restarted){
                game_map.reset_map();
                restarted = true;
            }
        }
        
        menu.update_screen(game_state);

        if (game_state == IN_GAME) {
            graphics.update_game(player1, player2, game_map, control_enemy, turn);
            sound_manager.play_player(player1);
            sound_manager.play_player(player2);
        }
        else{
            graphics.update_menu(menu,game_state,menu.get_player1_skin_index(),menu.get_player2_skin_index(), menu.get_current_map());
            sound_manager.play_menu(controller);
        }

        sound_manager.play_music(game_state, menu.get_current_map(), game_won);

    }

}
void Game::set_turns(int turn){
    if (turn == 1) {turn = 2;}
    else {turn = 1;}
}
void Game::handle_turns() {

    if (turn == 1) {p_pointer = &player1;}
    else if (turn == 2) {p_pointer = &player2;}

    if (p_pointer->get_if_moved() == false){
        
        p_pointer->handle_movement(controller.get_player_input(),game_map);
        
    } else {

        if (!game_won) {game_won = menu.check_win(p_pointer->get_treasure());}

        if(p_pointer->hasDoublePlay()==true){
            p_pointer->useDoublePlay();
        }
        else {
            if (turn == 1) {turn = 2;}
            else {turn = 1;}
            control_enemy = false;
        }

        if (p_pointer->hasControlEnemy()==true) {
            control_enemy = true;
            p_pointer->useControlEnemy();
        }
        p_pointer->set_has_moved(false);

        timer = 1;
    }
}

void Game::run_timer(){
    if (timer >= 0){timer--;}
    else {timer = 0;}
}

void Game::clean_game(){
    game_map.clear_map();
    sound_manager.quit();
    graphics.clean();
}
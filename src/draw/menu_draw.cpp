#include "menu_draw.h"

Menu_draw::Menu_draw(int width, int height): screen_width(width), screen_height(height){};

void Menu_draw::load_all(SDL_Renderer* ren){

    title.init("assets/menu/title/title.png",ren,0,0,(screen_width/2)-(TITLE_WIDTH/2), (TITLE_HEIGHT/2), 
    (screen_width/2)-(TITLE_WIDTH/2), (-TITLE_HEIGHT*2), TITLE_WIDTH, TITLE_HEIGHT, TITLE_SCREEN,screen_width,screen_height);

    start_menu.init("assets/menu/enter.png",ren,0,0,(screen_width/2)-(START_MENU_WIDTH/2), (screen_height) - (START_MENU_HEIGHT*2), 
    (screen_width/2)-(START_MENU_WIDTH/2), (screen_height+START_MENU_HEIGHT*2), START_MENU_WIDTH, START_MENU_HEIGHT, TITLE_SCREEN,screen_width,screen_height);

    player1_overlay.init("assets/menu/selection/selec_player1.png",ren,0,0,(PLAYER_OVER_WIDTH-PLAYER_OVER_WIDTH/2),(screen_height/2)-(PLAYER_OVER_HEIGHT/2),
    -(PLAYER_OVER_WIDTH*2), (screen_height/2)-(PLAYER_OVER_HEIGHT/2), PLAYER_OVER_WIDTH, PLAYER_OVER_HEIGHT, SELECTION_MENU,screen_width,screen_height);

    player1.init("assets/menu/selection/player_list.png",ren,0,0,(PLAYER_OVER_WIDTH-PLAYER_OVER_WIDTH/2),(screen_height/2)-(PLAYER_OVER_HEIGHT/2),
    -(PLAYER_OVER_WIDTH*2), (screen_height/2)-(PLAYER_OVER_HEIGHT/2), PLAYER_OVER_WIDTH, PLAYER_OVER_HEIGHT, SELECTION_MENU,screen_width,screen_height);

    player2_overlay.init("assets/menu/selection/selec_player2.png",ren,0,0,(screen_width - PLAYER_OVER_WIDTH*1.5),(screen_height/2)-(PLAYER_OVER_HEIGHT/2),
    (screen_width + PLAYER_OVER_WIDTH), (screen_height/2)-(PLAYER_OVER_HEIGHT/2), PLAYER_OVER_WIDTH, PLAYER_OVER_HEIGHT, SELECTION_MENU,screen_width,screen_height);

    player2.init("assets/menu/selection/player_list.png",ren,0,0,(screen_width - PLAYER_OVER_WIDTH*1.5),(screen_height/2)-(PLAYER_OVER_HEIGHT/2),
    (screen_width + PLAYER_OVER_WIDTH), (screen_height/2)-(PLAYER_OVER_HEIGHT/2), PLAYER_OVER_WIDTH, PLAYER_OVER_HEIGHT, SELECTION_MENU,screen_width,screen_height);

    map_overlay.init("assets/menu/selection/selec_map.png",ren,0,0,(screen_width/2)-(MAP_OVER_WIDTH/2),(TITLE_HEIGHT/2),
    (screen_width/2)-(MAP_OVER_WIDTH/2), (-MAP_OVER_HEIGHT*2), MAP_OVER_WIDTH, MAP_OVER_HEIGHT, SELECTION_MENU,screen_width,screen_height);

    map_pic.init("assets/menu/selection/map_list.png",ren,0,0,(screen_width/2)-(MAP_OVER_WIDTH/2),(TITLE_HEIGHT/2),
    (screen_width/2)-(MAP_OVER_WIDTH/2), (-MAP_OVER_HEIGHT*2), MAP_OVER_WIDTH, MAP_OVER_HEIGHT, SELECTION_MENU,screen_width,screen_height);

    start_selec.init("assets/menu/enter.png",ren,0,0,(screen_width/2)-(START_MENU_WIDTH/2), (screen_height) - (START_MENU_HEIGHT*3), 
    (screen_width/2)-(START_MENU_WIDTH/2), (screen_height+START_MENU_HEIGHT*3), START_MENU_WIDTH, START_MENU_HEIGHT, SELECTION_MENU,screen_width,screen_height);

    start_end.init("assets/menu/enter.png",ren,0,0,(screen_width/2)-(START_MENU_WIDTH/2), (screen_height) - (START_MENU_HEIGHT*3), 
    (screen_width/2)-(START_MENU_WIDTH/2), (screen_height+START_MENU_HEIGHT*3), START_MENU_WIDTH, START_MENU_HEIGHT, GAME_END,screen_width,screen_height);

    won_sign.init("assets/menu/end/won_sign.png",ren,0,0,(screen_width/2)-(TITLE_WIDTH/2), (TITLE_HEIGHT/2), 
    (screen_width/2)-(TITLE_WIDTH/2), (-TITLE_HEIGHT*2), TITLE_WIDTH, TITLE_HEIGHT, GAME_END,screen_width,screen_height);

}

void Menu_draw::update(int game_state, int p1_skin, int p2_skin, int map_index, int p1_won, int p2_won){

    title.update(game_state);
    start_menu.update(game_state);

    player1_overlay.update(game_state);
    player2_overlay.update(game_state);

    player1.update(game_state);
    player2.update(game_state);

    map_overlay.update(game_state);
    map_pic.update(game_state);
    start_selec.update(game_state);

    player1.set_frame(p1_skin);
    player2.set_frame(p2_skin);
    map_pic.set_frame(map_index);

    if (p1_won){won_sign.set_frame(0);}
    else {won_sign.set_frame(1);}

    won_sign.update(game_state);
    start_end.update(game_state);
    
}

void Menu_draw::draw(SDL_Renderer* ren){

    title.render(ren);
    start_menu.render(ren);

    player1_overlay.render(ren);
    player2_overlay.render(ren);

    player1.render(ren);
    player2.render(ren);

    map_overlay.render(ren);
    map_pic.render(ren);

    start_selec.render(ren);

    won_sign.render(ren);
    start_end.render(ren);
}

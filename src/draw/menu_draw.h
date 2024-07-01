#ifndef MENU_DRAW_H
#define MENU_DRAW_H

#define INTRO -1
#define TITLE_SCREEN 0
#define SELECTION_SCREEN 1
#define IN_GAME 2
#define END 3

#define TITLE_WIDTH 392
#define TITLE_HEIGHT 196

#define START_MENU_WIDTH 256
#define START_MENU_HEIGHT 64

#define PLAYER_OVER_WIDTH 256
#define PLAYER_OVER_HEIGHT 256

#define MAP_OVER_WIDTH 256
#define MAP_OVER_HEIGHT 224

#include "../menu.h"
#include "menu_element.h"
#include "../sprite_animator.h"
#include "../texture_loader.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "iostream"
#include "../sound_manager.h"

class Menu_draw{

public:

    Menu_draw(int screen_width, int screen_height);
    ~Menu_draw(){};

    void load_all(SDL_Renderer* ren);

    void draw_intro(SDL_Renderer* ren){};
    void draw(SDL_Renderer* ren);
    void update(int game_state, int p1_skin, int p2_skin, int map_index, int p1_won, int p2_won);

private:

    int screen_width, screen_height;

    Menu_element wolf;

    Menu_element title;
    Menu_element start_menu;

    Menu_element map_overlay;
    Menu_element map_pic;
    Menu_element start_selec;

    Menu_element player1;
    Menu_element player1_overlay;

    Menu_element player2;
    Menu_element player2_overlay;

    Menu_element won_sign;
    Menu_element start_end;

};


#endif
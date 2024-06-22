#ifndef MENU_DRAW_H
#define MENU_DRAW_H

#define TITLE_WIDTH 256
#define TITLE_HEIGHT 128

#include "../menu.h"
#include "../sprite_animator.h"
#include "../texture_loader.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Menu_draw{

public:

    Menu_draw(int screen_width, int screen_height);
    ~Menu_draw(){};

    void load_all(SDL_Renderer* ren);

    void draw_intro(SDL_Renderer* ren){};
    void draw_title(SDL_Renderer* ren);
    void draw_selection(SDL_Renderer* ren);
    void draw_gui(SDL_Renderer* ren){};
    void draw_end(SDL_Renderer* ren){};

private:

    int screen_width, screen_height;

    struct Element{

        SDL_Texture* tex;
        SDL_Rect spr;
        SDL_Rect rect;

        int base_x, base_y;

        int image_frame;
        int image_speed;
        int image_index;
        int image_length;

        int state_index;
    };

    Element wolf;

    Element title;
    Element press_start;

    Element map_overlay;
    Element space_button;
    Element player_overlay;
    Element player;
    Element player_button;

    Element won_sign;
    Element trophy;

};


#endif
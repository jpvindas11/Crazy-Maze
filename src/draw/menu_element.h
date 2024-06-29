#ifndef MENU_ELEMENT
#define MENU_ELEMENT

#define SPEED 24

#define BASE_SCREEN_WIDTH 1280
#define BASE_SCREEN_HEIGHT 720

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../texture_loader.h"
#include "../sprite_animator.h"

class Menu_element{

public: 

    Menu_element(){};
    ~Menu_element(){};

    void init(const char* sprite, SDL_Renderer* ren, int img_speed, int img_length, 
    int x_start, int y_start, int x_hide, int y_hide, int width, 
    int height, int state, int screen_width, int screen_height);

    void render(SDL_Renderer* ren);
    //void play_animation();
    void update(int game_state);
    void set_frame (int frame);

private:

    void move(int next_x, int next_y);

private:

    SDL_Texture* tex;
    SDL_Rect spr;
    SDL_Rect rect;

    int x, y;
    int next_x, next_y;

    int base_state;
    int width_mult, height_mult;
    
    int base_x, base_y;
    int hide_x, hide_y;
    int base_width, base_height;

    int image_frame;
    int image_speed;
    int image_index;
    int image_length;

    int state_index;
};

#endif 
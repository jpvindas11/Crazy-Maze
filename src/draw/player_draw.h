#ifndef PLAYER_DRAW_H
#define PLAYER_DRAW_H

#define P_FRAME_WIDTH 16
#define P_FRAME_HEIGHT 20


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../sprite_animator.h"
#include "../texture_loader.h"

class Player_draw{

public:

    Player_draw(){};
    ~Player_draw(){};

    void init(const char* texture, SDL_Renderer* renderer, int tile_size, int x_off, int y_off);
    void update(int next_x, int next_y);
    void render(SDL_Renderer* renderer);

    void jump();
    void set_skin(const char* texture , SDL_Renderer* renderer);

private:
    SDL_Texture* player_tex;
    SDL_Rect player_rect;
    SDL_Rect player_spr;

    int x , y;
    int width, height;
    int frame_width, frame_height;

    int tile_size;
    int x_offset, y_offset;
    int p_offset;

    int image_frame;
    int image_index;
    int image_speed;
    int image_length;
    int action_index;
};


#endif
#ifndef PLAYER_DRAW_H
#define PLAYER_DRAW_H

#define P_FRAME_WIDTH 16
#define P_FRAME_HEIGHT 20
#define P_OFFSET 4

#define P_CONTROL_WIDTH 16
#define P_CONTROL_HEIGHT 8
#define P_CONTROL_ELEVATION 8

#define BASE_MOVEMENT_SPEED 1
#define BASE_TELEPORT_SPEED 16
#define BASE_GRAVITY 0.4
#define BASE_JUMP_HEIGHT 4.0

#define WALKING_IMAGE_SPEED 6
#define IDLE_IMAGE_SPEED 0

#define WALK_DOWN 0
#define WALK_UP 1
#define WALK_RIGHT 2
#define WALK_LEFT 3

#define JUMP_DOWN 4
#define JUMP_UP 5
#define JUMP_RIGHT 6
#define JUMP_LEFT 7

#define GOT_ORB 8
#define CONTROL 9
#define CONTROLLED 10
#define TELEPORT 11

#define WIN 12
#define LOST 13

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../sprite_animator.h"
#include "../texture_loader.h"
#include "vector"
#include "../player.h"
#include "../sound_manager.h"

class Player_draw{

public:

    Player_draw(){};
    ~Player_draw(){};

    void init(std::vector<SDL_Texture*> skins, int skin_ind, int player, int tile, int x_off, int y_off, SDL_Renderer* ren);
    void update(Player& player, bool control_enemy, int turn);
    void render(SDL_Renderer* renderer);

    void jump();
    void vertical_movement();
    void action_manager();
    void set_skin(std::vector<SDL_Texture*> skins, int index);
    void set_control_signs();

    int get_skin() {return skin_index;}
    int get_y() {return y;}
    bool get_won() {return won;}

private:
    SDL_Texture* player_tex;
    SDL_Rect player_rect;
    SDL_Rect player_spr;

    SDL_Texture* player_control;
    SDL_Rect control_rect;
    SDL_Rect control_spr;

    int player_index;
    int skin_index;

    int x , y;
    double z;
    int width, height;
    int frame_width, frame_height;

    int tile_size;
    int x_offset, y_offset;
    int p_offset;
    int move_speed;
    int teleport_speed;
    double jump_height;
    double gravity;
    double downwards_speed;

    int image_frame;
    int image_index;
    int image_speed;
    int image_length;
    int action_index;
    int turn;

    bool is_jumping;
    bool teleport;
    bool is_controlled;
    bool won;


    char facing_direction;
};


#endif
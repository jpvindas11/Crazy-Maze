#include "player_draw.h"

void Player_draw::init(std::vector<SDL_Texture*> skins, int skin_ind, int player, int tile, int x_off, int y_off){

    skin_index = skin_ind;
    set_skin(skins,skin_ind);
    player_index = player;

    tile_size = tile;
    p_offset = P_OFFSET*(tile_size/16);

    move_speed = BASE_MOVEMENT_SPEED*(tile_size/16);
    teleport_speed = BASE_TELEPORT_SPEED*(tile_size/16);
    jump_height = BASE_JUMP_HEIGHT*(tile_size/16);
    gravity = BASE_GRAVITY*(tile_size/16);
    downwards_speed = 0;

    width = tile;
    height = tile+p_offset;

    frame_width = P_FRAME_WIDTH;
    frame_height = P_FRAME_HEIGHT;


    x_offset = x_off; y_offset = y_off;
    x = 0; y = 0, z = 0;
    z = 0;

    set_rect(player_rect, 0, 0, width, height);
    set_rect(player_spr, 0, 0, frame_width, frame_height);

    image_frame = 0;
    image_speed = 8;
    image_length = 4;
    image_index = 0;
    action_index = 0;
    facing_direction = 's';
    is_jumping = false;
    teleport = true;

}

void Player_draw::update(Player& player, bool control_enemy, int turn_p){

    //JUMP
    if (player.get_jumped() == true){jump();}

    //TP
    if (player.get_teleported() == true){
        if (!teleport){
            int fixed_x = (x/tile_size)*tile_size;
            int fixed_y = (y/tile_size)*tile_size;

            x = fixed_x;
            y = fixed_y;

            teleport = true;
        }
    }

    //SPRITES
    if (x > player.get_x()*tile_size) {

        if (!teleport) x-=move_speed;
        else x-=teleport_speed;
        facing_direction = 'l';
    }
    else if (x < player.get_x()*tile_size) {
        if(!teleport) x+=move_speed;
        else x+=teleport_speed;
        facing_direction = 'r';
    }
    else{
        if ((player.get_x()*tile_size)-move_speed < x < (player.get_x()*tile_size)+move_speed && !teleport){
            x = player.get_x()*tile_size;
        }
        else if (((player.get_x()*tile_size)-teleport_speed*1.5) < x < ((player.get_x()*tile_size)+teleport_speed*1.5) && teleport){
            x = player.get_x()*tile_size;
        }
    }

    if (y > player.get_y()*tile_size) {
        if(!teleport) y-=move_speed;
        else y-=teleport_speed;
        facing_direction = 'u';
    }
    else if (y < player.get_y()*tile_size) {
        if(!teleport) y+=move_speed;
        else y+=teleport_speed;
        facing_direction = 'd';
    }
    else{
        if ((player.get_y()*tile_size)-move_speed < y < (player.get_y()*tile_size)+move_speed && !teleport){
            y = player.get_y()*tile_size;
        }
        else if (((player.get_y()*tile_size)-teleport_speed*1.5) < y < ((player.get_y()*tile_size)+teleport_speed*1.5) && teleport){
            y = player.get_y()*tile_size;
        }
    }

    action_manager();

    //ANIMATION SPEEDS
    if (x == player.get_x()*tile_size && y == player.get_y()*tile_size) {
        if (image_frame == 0){
            image_speed = IDLE_IMAGE_SPEED;
        } 
        if (teleport){
            teleport = false;
            jump();
        }
        //CONTROLLED
        is_controlled = control_enemy;
        turn = turn_p;
    }
    else {image_speed = WALKING_IMAGE_SPEED;}
    if (is_controlled) {image_speed = WALKING_IMAGE_SPEED;}

    animation(image_frame, image_index, image_speed, image_length);

    player_rect.x = (x+(x_offset*tile_size));
    player_rect.y = ((y+(y_offset*tile_size))-(2*p_offset))+int(z);

    player_spr.x = image_frame*P_FRAME_WIDTH;
    player_spr.y = action_index*P_FRAME_HEIGHT;

    vertical_movement();

}

void Player_draw::render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, player_tex, &player_spr, &player_rect);
}

void Player_draw::jump(){
    if (z==0) {is_jumping = true;}
}

void Player_draw::vertical_movement(){
    
    if (is_jumping){
        //Up
        z -= jump_height;

        //Fall
        downwards_speed += gravity;
        z += downwards_speed;

        if (z > 0){ //Grounded
            z = 0;
            downwards_speed = 0;
            is_jumping = false;
            
        }
    }
}

void Player_draw::set_skin(std::vector<SDL_Texture*> skins, int index){
    player_tex = skins[index];
    skin_index = index;
}

void Player_draw::action_manager(){
    switch(facing_direction){
    case 'l':
        if (is_jumping == false) {action_index = WALK_LEFT;}
        else {action_index = JUMP_LEFT;}
        break;
    case 'r':
        if (is_jumping == false) {action_index = WALK_RIGHT;}
        else {action_index = JUMP_RIGHT;}
        break;
    case 'u':
        if (is_jumping == false) {action_index = WALK_UP;}
        else {action_index = JUMP_UP;}
        break;
    case 'd':
        if (is_jumping == false) {action_index = WALK_DOWN;}
        else {action_index = JUMP_DOWN;}
        break;
    }
    if (teleport) {action_index = TELEPORT;}

    if (is_controlled){
        if (player_index != turn){
            action_index = CONTROL;
        } else action_index = CONTROLLED;
    }
}
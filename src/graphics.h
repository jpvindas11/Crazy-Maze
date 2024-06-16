#ifndef GRAPHICS_H
#define GRAPHICS_H

#define GAME_NAME "Crazy Maze"

#define FPS 60
#define FPS_GOAL 1000/FPS 

#define TILE 32

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "texture_loader.h"

#include "player.h"
#include "game_map.h"
#include "draw/background.h"
#include "draw/tiles.h"
#include "sprite_animator.h"
#include "draw/player_draw.h"


class Graphics{

public:

    Graphics();
    ~Graphics();

    void init(Player& player1, Player& player2, Game_map& game_map);

    void update(Player& player1, Player& player2, Game_map& game_map);
    void render(Player& player1, Player& player2, Game_map& game_map);
    void event ();

    void clean();
    bool running() { return is_running; }

private:

    Background background;
    Tiles tiles;

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Event window_event;

    Player_draw player1_draw;
    Player_draw player2_draw;

private:

    bool is_running;

    int loop_start;
    int delta;

    int x_draw_offset, y_draw_offset;

    const char* map_index;
};

#endif 
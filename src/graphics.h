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
#include "menu.h"
#include "draw/menu_draw.h"
#include "draw/background.h"
#include "draw/tiles.h"
#include "sprite_animator.h"
#include "draw/player_draw.h"


class Graphics{

public:

    Graphics();
    ~Graphics();

    void init(Player& player1, Player& player2, Game_map& game_map);

    void update_title(Menu& menu);
    void update_game(Player& player1, Player& player2, Game_map& game_map, bool control_enemy, int turn);
    void update_selection(Menu& menu);
    void update_end(Menu& menu);

    void render_title(Menu& menu);
    void render_game(Game_map& game_map);
    void render_selection(Menu& menu);
    void render_end(Menu& menu);
    

    void event ();

    void clean();
    bool running() { return is_running; }

private:

    Menu_draw menu_draw;
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
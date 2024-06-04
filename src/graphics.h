#ifndef GRAPHICS_H
#define GRAPHICS_H

#define GAME_NAME "Crazy Maze"

#define FPS 60
#define FPS_GOAL 1000/FPS 

#define TILE 16

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define PLAYER_WIDTH TILE
#define PLAYER_HEIGHT (TILE + 4*(TILE/16)) //16 IS THE DEFAULT TILE SIZE, +4 BECAUSE PLAYER HEIGHT IS 20 BY DEFAULT

#define P_FRAME_WIDTH 16
#define P_FRAME_HEIGHT 20

#include "sdl/SDL.h"
#include "sdl/SDL_image.h"
#include "texture_loader.h"

#include "player.h"
#include "game_map.h"
#include "level/background.h"
#include "level/tiles.h"


class Graphics{

public:

    Graphics();
    ~Graphics();

    void init(Player& player1, Player& player2, Game_map& game_map);

    void update(Player& player1, Player& player2, Game_map& game_map);
    void render(Player& player1, Player& player2, Game_map& game_map);
    void controls(Player& player1, Player& player2);
    void event ();

    void set_rect(SDL_Rect& rect, int x, int y, int w, int h);
    void clean();
    bool running() { return is_running; }

private:

    struct PlayerDraw{
        SDL_Texture* player_tex;
        SDL_Rect player_rect;
        SDL_Rect player_spr;
    };

    Background background;
    Tiles tiles;

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Event window_event;
    SDL_Event control_event;

    PlayerDraw player1_draw;
    PlayerDraw player2_draw;

private:

    bool is_running;

    int loop_start;
    int delta;

    const char* map_index;
};

#endif 
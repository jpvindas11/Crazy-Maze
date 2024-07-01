#ifndef GUI_H
#define GUI_H

#define GUI_WIDTH 32
#define GUI_HEIGHT 16
#define GUI_ITEM 16
#define NUM_SEPARATION 5

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../texture_loader.h"
#include "../player.h"
#include "vector"

class Gui{

public:

    void init(int tile, int width, SDL_Renderer* renderer);
    void update(Player& player1, Player& player2);
    void reset_powers();
    void render(SDL_Renderer* ren, std::vector<SDL_Texture*> skins, int p1_skin, int p2_skin);

private:

    int tile_size;

    int p1_jumps, p2_jumps;
    bool p1_double, p1_control, p2_double, p2_control;

    SDL_Texture* p1_gui; SDL_Rect p1_rect;
    SDL_Texture* p2_gui; SDL_Rect p2_rect;
    SDL_Rect p1_spr; SDL_Rect p2_spr;

    SDL_Texture* number; SDL_Rect number_rect; SDL_Rect number_spr;
    SDL_Texture* item; SDL_Rect item_rect; SDL_Rect item_spr;

};

#endif
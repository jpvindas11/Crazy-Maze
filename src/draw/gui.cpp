#include "gui.h"

void Gui::init(int tile, int width, SDL_Renderer* renderer){
    tile_size = tile;

    p1_gui = load_texture("assets/gui/player1_gui.png",renderer); 
    set_rect(p1_rect, 0, 0, GUI_WIDTH*(tile_size/16), tile_size);
    set_rect(p1_spr, 0, 0, GUI_WIDTH, GUI_HEIGHT);

    p2_gui = load_texture("assets/gui/player2_gui.png",renderer); 
    set_rect(p2_rect, width-(GUI_WIDTH*(tile_size/16)), 0, GUI_WIDTH*(tile_size/16), tile_size);
    set_rect(p2_spr, 0, 0, GUI_WIDTH, GUI_HEIGHT);

    item = load_texture("assets/gui/item_gui.png",renderer);
    set_rect(item_rect, 0 , 0,  GUI_ITEM*(tile_size/16), tile_size);
    set_rect(item_spr, 0 , 0,  GUI_ITEM, GUI_ITEM);

    number = load_texture("assets/gui/numbers.png",renderer);
    set_rect(number_rect, 0 , 0,  GUI_ITEM*(tile_size/16), tile_size);
    set_rect(number_spr, 0 , 0,  GUI_ITEM, GUI_ITEM);
}
void Gui::update(Player& player1, Player& player2){
    //reset_powers();


    p1_jumps = player1.get_jump_wall_power(); 
    p2_jumps = player2.get_jump_wall_power(); 
}

void Gui::render(SDL_Renderer* renderer, std::vector<SDL_Texture*> skins, int p1_skin, int p2_skin){

    SDL_RenderCopy(renderer, p1_gui, &p1_spr, &p1_rect);
    SDL_RenderCopy(renderer, p2_gui, &p2_spr, &p2_rect);

    for (int i = 0; i < 2; ++i){
        item_spr.x = (i*GUI_ITEM);
        item_rect.x = (p1_rect.x + (i*tile_size));

        if (i == 0){
            SDL_RenderCopy(renderer,skins[p1_skin],&item_spr,&item_rect);
        }
        else{
            if (p1_jumps>0){
                SDL_RenderCopy(renderer,item,&item_spr,&item_rect);

                number_rect.x = item_rect.x;
                number_spr.x = (p1_jumps%10)*GUI_ITEM;
                SDL_RenderCopy(renderer,number,&number_spr,&number_rect);

                number_rect.x = item_rect.x - (NUM_SEPARATION * (tile_size/16));
                number_spr.x = ((p1_jumps/10)%10)*GUI_ITEM;
                SDL_RenderCopy(renderer,number,&number_spr,&number_rect);
            }
        }
        item_rect.x = (p2_rect.x + (i*tile_size));

        if (i == 0){
            SDL_RenderCopy(renderer,skins[p2_skin],&item_spr,&item_rect);
        }
        else{
            if (p2_jumps>0){
                SDL_RenderCopy(renderer,item,&item_spr,&item_rect);

                number_rect.x = item_rect.x;
                number_spr.x = (p2_jumps%10)*GUI_ITEM;
                SDL_RenderCopy(renderer,number,&number_spr,&number_rect);

                number_rect.x = item_rect.x - (NUM_SEPARATION * (tile_size/16));
                number_spr.x = ((p2_jumps/10)%10)*GUI_ITEM;
                SDL_RenderCopy(renderer,number,&number_spr,&number_rect);
            }
        }
    }
}

void Gui::reset_powers(){
    p1_double = false;
    p1_control = false;
    p2_control = false;
    p2_double = false;
}
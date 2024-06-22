#include "menu_draw.h"

Menu_draw::Menu_draw(int width, int height): screen_height(height), screen_width(width){}

void Menu_draw::load_all(SDL_Renderer* ren){
    title.tex = load_texture("assets/menu/title/title.png",ren);
    title.rect.x = title.base_x = (screen_width/2 - TITLE_WIDTH/2);
    title.rect.y = title.base_y = (screen_height/2 - TITLE_HEIGHT/2);
    title.rect.w = TITLE_WIDTH; title.rect.h = TITLE_HEIGHT;


    //press_start.tex = load_texture("assets/menu/enter.png",ren);

}


void Menu_draw::draw_title(SDL_Renderer* ren){
    SDL_RenderCopy(ren, title.tex, NULL, NULL);
}

void Menu_draw::draw_selection(SDL_Renderer* ren){
    
}
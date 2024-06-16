#include "texture_loader.h"

SDL_Texture* load_texture(const char* texture, SDL_Renderer *ren){

    SDL_Surface* temp_surf = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, temp_surf);
    SDL_FreeSurface(temp_surf);

return tex;
}

void set_rect(SDL_Rect& rect, int x, int y, int w, int h){
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}
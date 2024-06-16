#include "graphics.h"

Graphics::Graphics(){}
Graphics::~Graphics(){}

void Graphics::init(Player& player1, Player& player2, Game_map& game_map){
    SDL_Init (SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);

    SDL_Surface * icon = IMG_Load("assets/icon.bmp");
    SDL_SetWindowIcon(window,icon);
    SDL_FreeSurface(icon);

    x_draw_offset = ((SCREEN_WIDTH/2) - (game_map.get_width()/2)*TILE)/TILE;
    y_draw_offset = ((SCREEN_HEIGHT/2) - (game_map.get_height()/2)*TILE)/TILE;


    player1_draw.init("assets/skins/char00.png",renderer,TILE,x_draw_offset,y_draw_offset);
    player2_draw.init("assets/skins/char01.png",renderer,TILE,x_draw_offset,y_draw_offset);

    background.init(TILE, SCREEN_WIDTH, SCREEN_HEIGHT);
    tiles.init(TILE, SCREEN_WIDTH, SCREEN_HEIGHT, x_draw_offset, y_draw_offset);

    map_index = "poison";

    background.load_bg("assets/maps/default/background.png",renderer);
    tiles.load_tile_set("assets/maps/default/ground.png",renderer);

    is_running = true;
}

void Graphics::update(Player& player1, Player& player2, Game_map& game_map){
    
    loop_start = SDL_GetTicks(); //Get ticks at start of this frame

    event();

    player1_draw.update(player1.get_x(), player1.get_y());
    player2_draw.update(player2.get_x(), player2.get_y());


    render(player1,player2,game_map);

}

void Graphics::render(Player& player1, Player& player2, Game_map& game_map){

    SDL_RenderClear(renderer);

    background.draw(renderer);
    tiles.draw(renderer, game_map);

    player1_draw.render(renderer);
    player2_draw.render(renderer);

    SDL_RenderPresent(renderer);
}

void Graphics::event(){

    if (SDL_PollEvent( &window_event )){

        if (SDL_QUIT == window_event.type){
            is_running = false;
        }
    }
}

void Graphics::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
#include "graphics.h"

Graphics::Graphics(){}
Graphics::~Graphics(){}

void Graphics::init(Player& player1, Player& player2, Game_map& game_map){
    SDL_Init (SDL_INIT_EVERYTHING);

    background.init(TILE, SCREEN_WIDTH, SCREEN_HEIGHT);
    tiles.init(TILE, SCREEN_WIDTH, SCREEN_HEIGHT, game_map.get_width(), game_map.get_height());

    window = SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);

    map_index = "poison";

    //PLAYERS
    player1_draw.player_tex = load_texture("assets/char00.png",renderer);
    player1.width = PLAYER_WIDTH;
    player1.height = PLAYER_HEIGHT;

    player2_draw.player_tex = load_texture("assets/char01.png",renderer);
    player2.width = PLAYER_WIDTH;
    player2.height = PLAYER_HEIGHT;

    //BACKGROUND
    background.load_bg("assets/maps/poison/background.png",renderer);
    //GROUND
    tiles.load_tile_set("assets/maps/poison/ground.png",renderer);

    is_running = true;
}

void Graphics::update(Player& player1, Player& player2, Game_map& game_map){
    
    loop_start = SDL_GetTicks(); //Get ticks at start of this frame

    event();
    controls(player1, player2);

    player1.animation();
    player2.animation();

    render(player1,player2,game_map);

}

void Graphics::render(Player& player1, Player& player2, Game_map& game_map){

    SDL_RenderClear(renderer);

    background.draw(renderer);

    tiles.draw(renderer, game_map);

    //DRAW PLAYER 1
    set_rect(player1_draw.player_rect, player1.x*TILE, player1.y*TILE-(4), player1.width, player1.height); 
    set_rect(player1_draw.player_spr, player1.get_frame()*P_FRAME_WIDTH, player1.get_action()*P_FRAME_HEIGHT, P_FRAME_WIDTH, P_FRAME_HEIGHT);
    SDL_RenderCopy(renderer, player1_draw.player_tex, &player1_draw.player_spr, &player1_draw.player_rect);

    //DRAW PLAYER 2
    set_rect(player2_draw.player_rect, player2.x*TILE, player2.y*TILE-(4), player2.width, player2.height); 
    set_rect(player2_draw.player_spr, player2.get_frame()*P_FRAME_WIDTH, player2.get_action()*P_FRAME_HEIGHT, P_FRAME_WIDTH, P_FRAME_HEIGHT);
    SDL_RenderCopy(renderer, player2_draw.player_tex, &player2_draw.player_spr, &player2_draw.player_rect);
    
    SDL_RenderPresent(renderer);
}

void Graphics::event(){

    if (SDL_PollEvent( &window_event )){

        if (SDL_QUIT == window_event.type){
            is_running = false;
        }
    }
}

void Graphics::controls(Player& player1, Player& player2){
    if (window_event.type == SDL_KEYDOWN){
        //PLAYER 1
        if (window_event.key.keysym.sym == SDLK_d){
            player1.x += 1;
            player1.set_action(2);
        }
        if (window_event.key.keysym.sym == SDLK_a){
            player1.x -= 1;
            player1.set_action(3);
        }
        if (window_event.key.keysym.sym == SDLK_w){
            player1.y -= 1;
            player1.set_action(1);
        }
        if (window_event.key.keysym.sym == SDLK_s){
            player1.y += 1;
            player1.set_action(0);
        }
        //PLAYER 2
        if (window_event.key.keysym.sym == SDLK_RIGHT){
            player2.x += 1;
            player2.set_action(2);
        }
        if (window_event.key.keysym.sym == SDLK_LEFT){
            player2.x -= 1;
            player2.set_action(3);
        }
        if (window_event.key.keysym.sym == SDLK_UP){
            player2.y -= 1;
            player2.set_action(1);
        }
        if (window_event.key.keysym.sym == SDLK_DOWN){
            player2.y += 1;
            player2.set_action(0);
        }
    }
}


void Graphics::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Graphics::set_rect(SDL_Rect& rect, int x, int y, int w, int h){
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

#include "graphics.h"

Graphics::Graphics(): menu_draw(SCREEN_WIDTH, SCREEN_HEIGHT){}
Graphics::~Graphics(){}

void Graphics::init(Player& player1, Player& player2, Game_map& game_map){
    SDL_Init (SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);

    SDL_Surface * icon = IMG_Load("assets/icon.bmp");
    SDL_SetWindowIcon(window,icon);
    SDL_FreeSurface(icon);

    std::cout << "I" << std::endl;

    x_draw_offset = ((SCREEN_WIDTH/2) - (game_map.get_width()/2)*TILE)/TILE;
    y_draw_offset = ((SCREEN_HEIGHT/2) - (game_map.get_height()/2)*TILE)/TILE;

    menu_draw.load_all(renderer);
    load_textures_from_csv("assets/skins/skins.csv",renderer,player_skins); std::cout << "s" << std::endl;
    load_textures_from_csv("assets/maps/background.csv",renderer,backgrounds); std::cout << "b" << std::endl;
    load_textures_from_csv("assets/maps/middleground",renderer,middlegrounds); std::cout << "m" << std::endl;
    load_textures_from_csv("assets/maps/ground.csv",renderer,grounds); std::cout << "g" << std::endl;

    player1_draw.init(player_skins,0, 1, TILE,x_draw_offset,y_draw_offset);
    player2_draw.init(player_skins,0, 2, TILE,x_draw_offset,y_draw_offset);

    background.init(backgrounds,TILE, SCREEN_WIDTH, SCREEN_HEIGHT);
    tiles.init(grounds, TILE, SCREEN_WIDTH, SCREEN_HEIGHT, x_draw_offset, y_draw_offset);

    tiles.load_power_ups(renderer);

    std::cout << "BB" << std::endl; background.load_bg(backgrounds,0); 
    std::cout << "TT" << std::endl; tiles.set_tile_set(grounds,0);

    is_running = true;

    std::cout << "lets go" << std::endl;
}

void Graphics::update_menu(Menu& menu, int game_state, int player1, int player2, int map_index){

    event();    

    player1_draw.set_skin(player_skins, player1); player2_draw.set_skin(player_skins, player2);

    background.load_bg(backgrounds,map_index); tiles.set_tile_set(grounds, map_index);

    menu_draw.update(game_state, player1, player2, map_index);

    render_menu(menu);
}

void Graphics::update_selection(Menu& menu){
    event();
    render_selection(menu);
}

void Graphics::update_game(Player& player1, Player& player2, Game_map& game_map, bool control_enemy, int turn){
    
    event();

    player1_draw.update(player1, control_enemy, turn);
    player2_draw.update(player2, control_enemy, turn);

    render_game(game_map);

}

void Graphics::update_end(Menu& menu){
    event();
    render_end(menu);
}

void Graphics::render_menu(Menu& menu){
    SDL_RenderClear(renderer);

    menu_draw.draw(renderer);

    SDL_RenderPresent(renderer);
}

void Graphics::render_selection(Menu& menu){
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
}


void Graphics::render_game(Game_map& game_map){

    SDL_RenderClear(renderer);

    background.draw(renderer);
    tiles.draw(renderer, game_map);

    player1_draw.render(renderer);
    player2_draw.render(renderer);

    SDL_RenderPresent(renderer);
}

void Graphics::render_end(Menu& menu){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}


void Graphics::event(){

    if (SDL_PollEvent( &window_event )){

        if (SDL_QUIT == window_event.type){
            is_running = false;
        }
        else if (window_event.type == SDL_KEYDOWN){
            if (window_event.key.keysym.sym == SDLK_ESCAPE){
                is_running = false;
            }
        }
    }
}

void Graphics::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    for (SDL_Texture* texture : player_skins) {SDL_DestroyTexture(texture);}
    player_skins.clear();
    for (SDL_Texture* background : backgrounds) {SDL_DestroyTexture(background);}
    backgrounds.clear();
    for (SDL_Texture* middleground : middlegrounds) {SDL_DestroyTexture(middleground);}
    middlegrounds.clear();
    for (SDL_Texture* ground : grounds) {SDL_DestroyTexture(ground);}
    grounds.clear();

    IMG_Quit();
    SDL_Quit();
}
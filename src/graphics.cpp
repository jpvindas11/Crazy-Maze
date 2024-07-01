#include "graphics.h"

Graphics::Graphics(): menu_draw(SCREEN_WIDTH, SCREEN_HEIGHT){}
Graphics::~Graphics(){}

void Graphics::init(Player& player1, Player& player2, Game_map& game_map){

    is_running = true;

    try {
        if ((game_map.get_width()*TILE)>SCREEN_WIDTH){
            throw Size_excepcion("Error, map width exceeds the screen limits");
        }
        if ((game_map.get_height()*TILE)>SCREEN_HEIGHT){
            throw Size_excepcion("Error, map width exceeds the screen limits");
        }
        if (TILE<16){
            throw Size_excepcion("Error, tile size is below the minimum of 16 pixels");
        }
    } catch (const Size_excepcion& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        is_running = false;
    }

    if (is_running){

        SDL_Init (SDL_INIT_EVERYTHING);

        window = SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);

        SDL_Surface * icon = IMG_Load("assets/icon.bmp");
        SDL_SetWindowIcon(window,icon);
        SDL_FreeSurface(icon);

        x_draw_offset = ((SCREEN_WIDTH/2) - (game_map.get_width()/2)*TILE)/TILE;
        y_draw_offset = ((SCREEN_HEIGHT/2) - (game_map.get_height()/2)*TILE)/TILE;

        menu_draw.load_all(renderer);
        load_textures_from_csv("assets/skins/skins.csv",renderer,player_skins); 
        load_textures_from_csv("assets/maps/background.csv",renderer,backgrounds); 
        //load_textures_from_csv("assets/maps/middleground.csv",renderer,middlegrounds);
        load_textures_from_csv("assets/maps/ground.csv",renderer,grounds); 

        player1_draw.init(player_skins,0, 1, TILE,x_draw_offset,y_draw_offset,renderer);
        player2_draw.init(player_skins,0, 2, TILE,x_draw_offset,y_draw_offset, renderer);

        background.init(backgrounds,TILE, SCREEN_WIDTH, SCREEN_HEIGHT);
        tiles.init(grounds, TILE, SCREEN_WIDTH, SCREEN_HEIGHT, x_draw_offset, y_draw_offset);

        tiles.load_power_ups(renderer);

        gui.init(TILE, SCREEN_WIDTH, renderer);

        bg_index = 0;
    }
}

void Graphics::update_menu(Menu& menu, int game_state, int player1, int player2, int map_index){

    event();    

    player1_draw.set_skin(player_skins, player1); player2_draw.set_skin(player_skins, player2);

    tiles.set_tile_set(grounds, map_index); bg_index = map_index;
    background.move(true);
    background.load_bg(backgrounds,backgrounds.size()-1);

    menu_draw.update(game_state, player1, player2, map_index, player1_draw.get_won(), player2_draw.get_won());

    render_menu(menu);
}

void Graphics::update_game(Player& player1, Player& player2, Game_map& game_map, bool control_enemy, int turn){
    
    event();

    background.move(false);
    background.load_bg(backgrounds,bg_index);

    gui.update(player1,player2);

    player1_draw.update(player1, control_enemy, turn);
    player2_draw.update(player2, control_enemy, turn);


    render_game(game_map);

}


void Graphics::render_menu(Menu& menu){
    SDL_RenderClear(renderer);

    background.draw(renderer);
    menu_draw.draw(renderer);

    SDL_RenderPresent(renderer);
}


void Graphics::render_game(Game_map& game_map){

    SDL_RenderClear(renderer);

    background.draw(renderer);
    tiles.draw(renderer, game_map);

    gui.render(renderer, player_skins, player1_draw.get_skin(), player2_draw.get_skin());

    if (player1_draw.get_y() > player2_draw.get_y()) {player2_draw.render(renderer); player1_draw.render(renderer);}
    else {player1_draw.render(renderer); player2_draw.render(renderer);}

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
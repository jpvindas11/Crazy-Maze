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

    background.init(TILE, SCREEN_WIDTH, SCREEN_HEIGHT);
    tiles.init(TILE, SCREEN_WIDTH, SCREEN_HEIGHT, x_draw_offset, y_draw_offset);

    map_index = "poison";

    init_player_draw(player1_draw, "assets/skins/char00.png", player1.get_x(), player1.get_y(),
    PLAYER_WIDTH, PLAYER_HEIGHT, P_FRAME_WIDTH, P_FRAME_HEIGHT);
    init_player_draw(player2_draw, "assets/skins/char01.png", player2.get_x(), player2.get_y(),
    PLAYER_WIDTH, PLAYER_HEIGHT, P_FRAME_WIDTH, P_FRAME_HEIGHT);

    background.load_bg("assets/maps/test/background.png",renderer);
    tiles.load_tile_set("assets/maps/test/ground.png",renderer);

    is_running = true;
}

void Graphics::update(Player& player1, Player& player2, Game_map& game_map){
    
    loop_start = SDL_GetTicks(); //Get ticks at start of this frame

    event();
    controls(player1, player2);

    animation(player1_draw.image_frame, player1_draw.image_index, player1_draw.image_speed, player1_draw.image_length);
    animation(player2_draw.image_frame, player2_draw.image_index, player2_draw.image_speed, player2_draw.image_length);

    render(player1,player2,game_map);

}

void Graphics::render(Player& player1, Player& player2, Game_map& game_map){

    SDL_RenderClear(renderer);

    background.draw(renderer);

    tiles.draw(renderer, game_map);

    set_rect(player1_draw.player_rect, (player1.get_x()+x_draw_offset)*TILE, (player1.get_y()+y_draw_offset)*TILE - P_YOFFSET, PLAYER_WIDTH, PLAYER_HEIGHT); 
    set_rect(player1_draw.player_spr, player1_draw.image_frame*P_FRAME_WIDTH, player1_draw.action_index*P_FRAME_HEIGHT, P_FRAME_WIDTH, P_FRAME_HEIGHT);
    SDL_RenderCopy(renderer, player1_draw.player_tex, &player1_draw.player_spr, &player1_draw.player_rect);

    set_rect(player2_draw.player_rect, (player2.get_x()+x_draw_offset)*TILE, (player2.get_y()+y_draw_offset)*TILE - P_YOFFSET, PLAYER_WIDTH, PLAYER_HEIGHT); 
    set_rect(player2_draw.player_spr, player2_draw.image_frame*P_FRAME_WIDTH, player2_draw.action_index*P_FRAME_HEIGHT, P_FRAME_WIDTH, P_FRAME_HEIGHT);
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
        int P1_X=player1.get_x();
        int P1_Y=player1.get_y();
        int P2_X=player2.get_x();
        int P2_Y=player2.get_y();

        //PLAYER 1
        if (window_event.key.keysym.sym == SDLK_d){
            P1_X+=1;
            player1_draw.action_index = 2;
            player1_draw.image_speed = 7;
        }
        if (window_event.key.keysym.sym == SDLK_a){
            P1_X-=1;
            player1_draw.action_index =(3);
        }
        if (window_event.key.keysym.sym == SDLK_w){
            P1_Y-=1;
            player1_draw.action_index =(1);
        }
        if (window_event.key.keysym.sym == SDLK_s){
            P1_Y+=1;
            player1_draw.action_index =(0);
        }
        //PLAYER 2
        if (window_event.key.keysym.sym == SDLK_RIGHT){
            P2_X+=1;
            player2_draw.action_index =(2);
             player2_draw.image_speed = 8;
        }
        if (window_event.key.keysym.sym == SDLK_LEFT){
            P2_X-=1;
            player2_draw.action_index =(3);
        }
        if (window_event.key.keysym.sym == SDLK_UP){
            P2_Y-=1;
            player2_draw.action_index =(1);
        }
        if (window_event.key.keysym.sym == SDLK_DOWN){
            P2_Y+=1;
            player2_draw.action_index =(0);
        }
        player1.update(P1_X,P1_Y);
        player2.update(P2_X,P2_Y);
    }
}


void Graphics::set_rect(SDL_Rect& rect, int x, int y, int w, int h){
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

void Graphics::init_player_draw(PlayerDraw& player, const char* sprite, int x, int y, 
int width, int height, int frame_width, int frame_height){

    player.player_tex = load_texture(sprite,renderer);

    set_rect(player.player_rect, x, y, width, height);
    set_rect(player.player_spr, 0, 0, frame_width, frame_height);

    player.image_frame = 0;
    player.image_speed = 0;
    player.image_length = 4;
    player.image_index = 0;
    player.action_index = 0;
}

void Graphics::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
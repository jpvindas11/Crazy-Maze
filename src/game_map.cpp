#include "game_map.h"
#include "iostream"


Game_map::Game_map(int width, int height) : height(height), width(width) {

    map=(int **)malloc(height * sizeof(int *));
    for(int i=0;i<height;i++){
        map[i] = (int *)malloc(width * sizeof(int));
    }

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if (i == j) {map[i][j]=1;}
            else {map[i][j]=0;}
        }
    }
}

Game_map::~Game_map() {
    for(int i=0;i<height;i++){
        free(map[i]);
    }
    free(map);
}

void Game_map::print_map(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            printf(" %i", map[i][j]);

        }
        printf("\n");
    }
}
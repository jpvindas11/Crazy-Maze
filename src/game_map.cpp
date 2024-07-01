#include "game_map.h"
#include "iostream"


Game_map::Game_map(int width, int height) : height(height), width(width) {
    map.resize(height, std::vector<Cell>(width));

    start_generation(width, height);
}

void Game_map::start_generation(int width, int height){
    std::srand(std::time(0));

    portal_list.clear();

    int treasure_x = std::rand() % height;
    int treasure_y = std::rand() % width;
    
    map[treasure_x][treasure_y].set_treasure(true);

    for (auto& row : map) {
        for (Cell& cell : row) {
            cell.update_Powers(height, width);
        }
    }
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Cell& cell = map[i][j];

            // if there is a portal, we have to make the other 
            if (cell.getPortal()) {
                int portal1_x = i;
                int portal1_y = j;
    
                int other_X, other_Y;
                do {
                    other_X = std::rand() % height;
                    other_Y = std::rand() % width;
                } while (!map[other_X][other_Y].isEmpty());
                map[other_X][other_Y].setPortal(true);
                portal_list.push_back({{portal1_x, portal1_y}, {other_X, other_Y}});
            }
            
        }
    }

    init_map(0, 0);
    fill_east_side();
}
void Game_map::clear_map() {
    for (auto& tMap : map) {
        tMap.clear();
    }
    map.clear();
}

void Game_map::reset_map(){
    for (auto& row : map) {
        for (Cell& cell : row) {
            
            cell.clean_cell();
            cell.setBottomWall(true);
            cell.setTopWall(true);
            cell.setRightWall(true);
            cell.setLeftWall(true);
            cell.setVisited(false);
        }
    }
}

Game_map::~Game_map() {
    clear_map();
}
Cell& Game_map::get_map_index(int x, int y) {
    return map[x][y];
}

void Game_map::init_map(int x, int y) {
    int newX, newY;

    map[x][y].setVisited(true);

    
    std::vector<int> directions = {0, 1, 2, 3};

    for (int i = directions.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        
        
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    
    for (int i = 0; i < 4; ++i) {
        int randMove = directions[i];

        if (randMove == 0) { // mover a la izquierda
            newX = x;
            newY = y - 1;
        } else if (randMove == 1) { // mover a la derecha
            newX = x;
            newY = y + 1;
        } else if (randMove == 2) { // mover hacia arriba
            newX = x - 1;
            newY = y;
        } else if (randMove == 3) { // mover hacia abajo
            newX = x + 1;
            newY = y;
        }

        if (newX >= 0 && newY >= 0 && newX < this->height && newY < this->width && !map[newX][newY].isVisited()) {
            if (newX < x) { // arriba
                map[x][y].setTopWall(false);
                map[newX][newY].setBottomWall(false);
            } else if (newX > x) { // abajo
                map[x][y].setBottomWall(false);
                map[newX][newY].setTopWall(false);
            } else if (newY < y) { // izquierda
                map[x][y].setLeftWall(false);
                map[newX][newY].setRightWall(false);
            } else if (newY > y) { // derecha
                map[x][y].setRightWall(false);
                map[newX][newY].setLeftWall(false);
            }

            add_extra_edges(x,y);

            init_map(newX, newY);
        }
    }
}
bool Game_map::bool_add_extra_edge() {
    double rand_prob = static_cast<double>(std::rand()) / RAND_MAX;
    return rand_prob < EXTRA_EDGE_PROB;
}

void Game_map::add_extra_edges(int x, int y) {
    if (bool_add_extra_edge()){
        int random = 0;
        int direction = 0; 
        bool set = false;
        while(!set){
            random = int(std::rand() % 4);
            direction = random;

            if (random == 0) { // arriba
                if (x > 0){
                    map[x][y].setTopWall(false);
                    map[x-1][y].setBottomWall(false);
                    set = true;
                }
            } else if (random == 1) { // abajo
                if (x < height-1){
                    map[x][y].setBottomWall(false);
                    map[x+1][y].setTopWall(false);
                    set = true;
                }
            } else if (random == 2) { // izquierda
                if (y > 0){
                    map[x][y].setLeftWall(false);
                    map[x][y-1].setRightWall(false);
                    set = true;
                }
            } else if (random == 3) { // derecha
                if (x < width-1){
                map[x][y].setRightWall(false);
                map[x][y+1].setLeftWall(false);
                set = true;
                }
            }
        }
    }
}

void Game_map::fill_east_side(){
    for (int i = 0; i < height; ++i){
        map[i][width-1].setRightWall(true);
    }
}







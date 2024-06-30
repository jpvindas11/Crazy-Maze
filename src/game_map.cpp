#include "game_map.h"
#include "iostream"


Game_map::Game_map(int width, int height) : height(height), width(width) {
    std::srand(std::time(0));
    map.resize(height, std::vector<Cell>(width));
    for (auto& treasure_pos : treasure_positions) {
        int treasure_x = treasure_pos.first;
        int treasure_y = treasure_pos.second;
        map[treasure_x][treasure_y].set_treasure(true);
    }
    for (auto& row : map) {
        for (Cell& cell : row) {
            
            cell.update_Powers(height, width);
        }
    }
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Cell& cell = map[i][j];

            // Si la celda tiene un portal, asegúrate de que haya un par en una celda vacía
            if (cell.getPortal()) {
                int other_X, other_Y;
                do {
                    other_X = std::rand() % height;
                    other_Y = std::rand() % width;
                } while (!map[other_X][other_Y].isEmpty());
                map[other_X][other_Y].setPortal(true);
            }
            
        }
    }

    init_map(0, 0);
    fill_east_side();
}

Game_map::~Game_map() {
    for (auto& tMap : map) {
        tMap.clear();
    }
    map.clear();
}
Cell& Game_map::get_map_index(int x, int y) {
    return map[x][y];
}
void Game_map::set_treasure_at(Player& player1, Player& player2) {
    int player1_x = player1.get_x();
    int player1_y = player1.get_y();
    int player2_x = player2.get_x();
    int player2_y = player2.get_y();

    std::cout << "Player 1 position: (" << player1_x << ", " << player1_y << ")" << std::endl;
    std::cout << "Player 2 position: (" << player2_x << ", " << player2_y << ")" << std::endl;

    int manhattan_distance = abs(player1_x - player2_x) + abs(player1_y - player2_y);
    std::cout << "Manhattan distance: " << manhattan_distance << std::endl;

    int treasure_x = (player1_x + player2_x) / 2;
    int treasure_y = (player1_y + player2_y) / 2;
    std::cout << "nueva coordenada: (" << treasure_x << ", " << treasure_y << ")" << std::endl;
    
    treasure_positions.push_back(std::make_pair(treasure_x, treasure_y));
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







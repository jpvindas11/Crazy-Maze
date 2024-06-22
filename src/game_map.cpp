#include "game_map.h"
#include "iostream"


Game_map::Game_map(int width, int height) : height(height), width(width) {
    std::srand(std::time(0));
    map.resize(height, std::vector<Cell>(width));

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
            /*
            std::cout << "Cell (" << i << "," << j << ") Properties:" << std::endl;
            std::cout << "  Portal: " << (cell.getPortal() ? "Yes" : "No") << std::endl;
            std::cout << "  Double Play: " << (cell.get_double_play() ? "Yes" : "No") << std::endl;
            std::cout << "  Control Enemy: " << (cell.getControlEnemy() ? "Yes" : "No") << std::endl;
            std::cout << "  Jump Wall: " << (cell.getJumpWall() ? "Yes" : "No") << std::endl;
            std::cout << std::endl;*/
        }
    }

    init_map(0, 0);
    
    add_treasure(width, height);
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

void Game_map::add_treasure(int width, int height){
    get_map_index(int(std::rand()%height),int(std::rand()%width)).set_treasure(true);
}
void Game_map::print_map_state() const {
    std::cout << "Mapa:" << std::endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            const Cell& cell = map[i][j];
            std::cout << "(" << i << ", " << j << "): ";
            std::cout << "Top: " << (cell.hasTopWall() ? "Yes" : "No") << " ";
            std::cout << "Bottom: " << (cell.hasBottomWall() ? "Yes" : "No") << " ";
            std::cout << "Left: " << (cell.hasLeftWall() ? "Yes" : "No") << " ";
            std::cout << "Right: " << (cell.hasRightWall() ? "Yes" : "No") << std::endl;
        }
    }
}

void Game_map::print_map(){
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            const Cell& cell = map[i][j];
            std::cout << "Cell (" << i << "," << j << "):\n";
            std::cout << "  Portal: " << (cell.getPortal() ? "Yes" : "No") << "\n";
            std::cout << "  Double Play: " << (cell.get_double_play() ? "Yes" : "No") << "\n";
            std::cout << "  Control Enemy: " << (cell.getControlEnemy() ? "Yes" : "No") << "\n";
            std::cout << "  Jump Wall: " << (cell.getJumpWall() ? "Yes" : "No") << "\n";
            std::cout << "  Top Wall: " << (cell.hasTopWall() ? "Yes" : "No") << "\n";
            std::cout << "  Bottom Wall: " << (cell.hasBottomWall() ? "Yes" : "No") << "\n";
            std::cout << "  Left Wall: " << (cell.hasLeftWall() ? "Yes" : "No") << "\n";
            std::cout << "  Right Wall: " << (cell.hasRightWall() ? "Yes" : "No") << "\n";
            std::cout << "  Visited: " << (cell.isVisited() ? "Yes" : "No") << "\n";
            std::cout << std::endl;
        }
    }
}




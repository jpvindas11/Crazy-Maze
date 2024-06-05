#ifndef PLAYER_H
#define PLAYER_H

class Player{

public:

    Player(int x_start, int y_start);
    ~Player(){};

    void update();
    int get_x();
    int get_y();

public:
    int x;
    int y;

private:

    //Cuando se hagan métodos para mover al jugador, hay que pasar x & y aquí en private. uwu

};


#endif
#ifndef PLAYER_H
#define PLAYER_H

class Player{

public:

    Player(int x_start, int y_start);
    ~Player(){};

    void update(int new_X,int new_Y);
    inline int get_x(){return this->x;}
    inline int get_y(){return this->y;}
    inline void set_x(int new_X){this->x=new_X;}
    inline void set_y(int new_Y){this->y=new_Y;}

private:

    int x;
    int y;

    //Cuando se hagan métodos para mover al jugador, hay que pasar x & y aquí en private. uwu

};


#endif
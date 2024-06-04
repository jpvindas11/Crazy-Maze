#ifndef PLAYER_H
#define PLAYER_H

class Player{

public:

    Player(){};
    ~Player(){};

    void init(int x_start, int y_start, int img_speed_start);
    void update();
    void animation();
    int get_frame() {return image_frame;}
    int get_action() {return action_index;}
    void set_action(int action) {action_index = action;}
    const char* get_sprite() {return sprite;}

public:
    int x;
    int y;
    int width;
    int height;

private:

    int image_frame = 0;
    int image_index = 0;
    int image_speed = 6;
    int image_length = 4;
    int action_index = 0;
    const char* sprite;

};


#endif
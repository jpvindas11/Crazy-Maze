#include "cell.h"


bool Cell::isPortal(int height,int width)
{
    double portalProb = static_cast<double>(rand()) / RAND_MAX; 

    if (portalProb <= PORTAL_SPAWN_RATE) {

        return true;
    } else {
        return false;
    }
    
}

bool Cell::double_play()
{

    double powerProb = static_cast<double>(rand()) / RAND_MAX; 

    if (powerProb <= DOUBLE_SPAWN_RATE) {

        return true;
    } else {
        return false;
    }

}

bool Cell::control_Enemy()
{

    double powerProb = static_cast<double>(rand()) / RAND_MAX; 

    if (powerProb <= CONTROL_SPAWN_RATE) {

        return true;
    } else {
        return false;
    }

}

bool Cell::jump_Wall()
{
    double powerProb = static_cast<double>(rand()) / RAND_MAX; 

    if (powerProb <= JUMP_SPAWN_RATE) {
        return true;
    } else {
        return false;
    }

}


void Cell::update_Powers(int height, int width) {
    if (!isEmpty()) {
        return; 
    }
    
    
    int randomPower = std::rand() % 4;
    
    if (randomPower == 0) { 
        if (!has_Portal) {
            has_Portal = isPortal(height, width);
        }
    } else if (randomPower == 1) { 
        has_double_Play = double_play();
    } else if (randomPower == 2) { 
        has_control_Enemy = control_Enemy();
    } else if (randomPower == 3) {
        has_jump_wall = jump_Wall();
    }

}

void Cell::clean_cell() {
    //std::cout << "Cleaning cell at memory address: " << this << std::endl;
    setPortal(false);
    set_control_enemy(false);
    set_double_play(false);
    set_jump_wall(false);
    set_treasure(false);
   
}
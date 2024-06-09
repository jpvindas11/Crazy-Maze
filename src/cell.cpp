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

    if (powerProb <= POWER_SPAWN_RATE) {

        return true;
    } else {
        return false;
    }

}

bool Cell::control_Enemy()
{

    double powerProb = static_cast<double>(rand()) / RAND_MAX; 

    if (powerProb <= POWER_SPAWN_RATE) {

        return true;
    } else {
        return false;
    }

}

bool Cell::jump_Wall()
{
    double powerProb = static_cast<double>(rand()) / RAND_MAX; 

    if (powerProb <= POWER_SPAWN_RATE) {
        return true;
    } else {
        return false;
    }

}

void Cell::update_Powers(int height,int width)
{
    int randomPower=0 + std::rand()%(4);

    if(randomPower==0){//ver si hay portal
        if(has_Portal==false){
            has_Portal=isPortal(height,width);
        }
    }else if(randomPower==1){//ver i hay double play
        has_double_Play=double_play();    
    
    }else if(randomPower==2){//ver si hay control enemy
        has_control_Enemy=control_Enemy();
    }else if(randomPower==3){
        has_jump_wall=jump_Wall();
    }
}


#include "../../lib/Characters/Player.hpp"
#include <assert.h>

using namespace std;

Player::Player(string name){
    this->name = name;
}

void Player::setAtkDstrbtn(int num){
    this->atkDstrbtn = num;
}

int Player::getAtkDstrbtn(){
    return atkDstrbtn;  
}

void Player::levelUp(){
    
   level += 1;
}
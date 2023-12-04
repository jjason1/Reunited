#include "../../lib/Characters/Player.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

Player::Player(string name) : Character(name), atkDstrbtn(0) {
    assert(level>=0 && "Your level must not be less than 0!");
}

//List all the skills
void Player::listSkills(ostream &out){ 
   //Not being implemented yet.
}

//Skill selection function for override
int Player::selectSkill(istream &in) {
    //Not being implemented yet.
    return 1;
}

void Player::setAtkDstrbtn(int distribution) {
    this->atkDstrbtn = distribution;
}

int Player::getAtkDstrbtn() {
    return atkDstrbtn;
}

void Player::resetHealth() {
    int baseHealth = 100;
    this->setHealth(baseHealth + (this->getLevel() - 1) * this->hpIncrmnt);
}

#include "../../lib/Characters/Player.hpp"
#include <iostream>

using namespace std;

Player::Player(string name, int level):Character(name),atkDstrbtn(0) {
    assert(level>=0 && "Your level must not be less than 0!");
}

//List all the skills
void Player::listSkills(ostream &out){ 
   
}

//Skill selection function for override
void Player::selectSkill(const string &skillName) {
    
}

void Player::setAtkDstrbtn(int distribution) {
    this->atkDstrbtn = distribution;
}

int Player::getAtkDstrbtn() {
    return atkDstrbtn;
}

void Player::levelUp() {
    this->level++;
}
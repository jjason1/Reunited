#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player(string name):Character(name),atkDstrbtn(0) {

}

//List all the skills
void Player::listSkills(ostream &out){ 
    for(int size_s = 0; i < skills.size(); ++i){
        out << i+1 << ". " <<  skills[i] << endl;
    }
}

//Skill selection function for override
void Player::selectSkill(const sstring &skillName) {
    for (const string& skill : skills) {
        if (skill == skillName) {
            currentSkill = skillName;
            cout << "Skill '" << currentSkill << "' selected." << endl;
            return;
        }
    }
    cerr << "Skill ' " << skillName << " ' not found." << endl;
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
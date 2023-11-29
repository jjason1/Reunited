#include "../../lib/Enemies/Golem.hpp"
#include <iostream>

using namespace std;


Golem::Golem(string name, int level) : Enemy::Enemy(name, level) {
    this->setHealth(3000);
    this->setAttack(50);
    this->setDefense(1000);
    //CD = terms;
}

void Golem::lazerBlaze(Character *target) {
    if(target == nullptr){
        cout << "Target cannot be null." <<endl;
    }
    target->takeDamage(this->getAttack() * 2); 
    cout<< this->getName() << " attacks " << target->getName() << " with lazer blaze!" <<endl;
}

void Golem::earthquake(vector<Character *> &targets) {
     for (Character *target : targets) {
        target->takeDamage(this->getAttack());
        cout<< this->getName() << " attacks " << target->getName() << " with earthquake!" <<endl;
     }
}

void Golem::shieldGen() {
    this->setDefense(this->getDefense() + 500);
    cout << this->getName() << " generates a protective shield!" <<endl;
}

#include "../../lib/Enemies/Golem.hpp"
#include <iostream>

including namespace std;


Golem::Golem(string name, int level) : Enemy(name, level) {
    this->setHealth(3000);
    this->setAttack(50);
    this->setDefense(1000);
}

void Golem::lazerBlaze(Character *target) {
    if(taget == nullptr){
        cout << "Target cannot be null."
    }
    target->takeDamage(this->getAttack()); 
    cout<< this->getName() << " attacks " << target->getName() << " with lazer blaze!" <<endl;
}

void Golem::earthquake(vector<Character *> &targets) {
     for (Character *target : targets) {
        target->takeDamage(this->getAttack());
     }
}
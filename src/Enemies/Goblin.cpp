#include "../../lib/Enemies/Goblin.hpp"

Goblin::Goblin(string name,int level) : Enemy::Enemy(name,level){}

/*
void Goblin::lifeSwipe(Character *c){
    //Health to be stolen.
    int stolenHp=10;
    //The player's health is stolen.
    c->takeDamage(stolenHp);
    //The stolen hp is added to the goblin's hp.
    this->setHealth(this->getHealth()+stolenHp);
}
*/
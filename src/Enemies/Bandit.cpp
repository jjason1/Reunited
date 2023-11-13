#include "../../lib/Enemies/Bandit.hpp"

Bandit::Bandit(string name,int level) : Enemy::Enemy(name,level){
    //Setting our stat increments:
    int hpInc,defInc,atkInc;
    hpInc = defInc = atkInc = 5;
    this->setIncrmnts(hpInc,defInc,atkInc);
    //Base stats:
    this->setHealth(150); 
    this->setDefense(80);
    this->setAttack(25);
}

/*
void Bandit::stun(Character *c){
    //The player is stunned for one turn.
    c->setMovable(false);
}
*/

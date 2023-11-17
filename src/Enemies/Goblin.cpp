#include "../../lib/Enemies/Goblin.hpp"

Goblin::Goblin(string name,int level) : Enemy::Enemy(name,level){
    //Setting our stat increments:
    int hpInc,defInc,atkInc;
    hpInc = defInc = atkInc = 5;
    this->setIncrmnts(hpInc,defInc,atkInc);
    //Base stats:
    this->setHealth(200);
    this->setDefense(90);
    this->setAttack(30);
}

void Goblin::lifeSwipe(Character *c){
    //Health to be stolen.
    int stolenHp=10;
    //The player's health is stolen.
    c->takeDamage(stolenHp);
    //The stolen hp is added to the goblin's hp.
    this->setHealth(this->getHealth()+stolenHp);
    cout<<this->getName()<<" used life swipe on "<<c->getName()
        <<" and stole "<<stolenHp<<" hp from "<<c->getName()<<"."<<endl;
}

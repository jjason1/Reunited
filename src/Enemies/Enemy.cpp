#include "../../lib/Enemies/Enemy.hpp"
#include <assert.h>

Enemy::Enemy(string name, int level){
    this->level=level;
    this->name=name;
    //Our name has to be a non-empty string.
    assert(name!="" && "Your name must not be empty!");
    //Our level can't be less than 0.
    assert(level>=0 && "Your level must not be less than 0!");
    //Setting default values.
    this->health=0;
    this->defense=0;
    this->attack=0;
    this->atkIncrmnt=0;
    this->defIncrmnt=0;
    this->hpIncrmnt=0;
    this->isMovable=true;
}

void Enemy::getStatus(ostream &out){
    out << endl;
    out << name << "'s Status: " << endl;
    out << "--------------------------\n";
    out << "Level   = " << level << endl;
    out << "Health  = " << health << endl;
    out << "Defense = " << defense << endl;
    out << "Attack  = " << attack << endl;
    out << endl;
}

string Enemy::getName(){
    return name;
}

/*
void Enemy::takeDamage(int dmg){
    //Reduce our health by the specified damage.
    this->health -= dmg;
}

void Enemy::normalAttack(Character *c){
    //The character takes damage from the enemy.
    c->takeDamage(this->attack);
}
*/
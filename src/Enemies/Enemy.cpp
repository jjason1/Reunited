#include "../../lib/Enemies/Enemy.hpp"
#include <assert.h>

Enemy::Enemy(string name, int level) : Character::Character(name){
    this->level=level;
    //Our level can't be less than 0.
    assert(level>=0 && "Your level must not be less than 0!");
}

void Enemy::normalAttack(Character *c){
    //The character takes damage from the enemy.
    cout<<this->getName()<<" used a normal attack on "<<c->getName()<<"."<<endl;
    c->takeDamage(this->attack);
}

int Enemy::selectSkill(){
    //Select one of your skills here. (Not implemented yet.)
    return 1;
}

void Enemy::useSkillOn(int skill, Character *c){
    //Use the given skill you've chosen on the given character. (Not implemented yet.)
}
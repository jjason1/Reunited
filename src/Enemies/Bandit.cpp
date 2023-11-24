#include "../../lib/Enemies/Bandit.hpp"

Bandit::Bandit(string name,int level) : Enemy::Enemy(name,level){
    //Setting our stat increments:
    int hpInc,defInc,atkInc;
    hpInc = defInc = atkInc = 5;
    this->setIncrmnts(hpInc,defInc,atkInc);
    //Base stats (For a Bandit):
    this->setHealth(150); 
    this->setDefense(80);
    this->setAttack(25);
}

void Bandit::stun(Character *c){
    //The player is stunned for one turn.
    c->setMovable(false);
    cout<<this->getName()<<" stunned "<<c->getName()<<"."<<endl;
}

//Only 2 skills are available: 
//1. normal attack
//2. stun
int Bandit::selectSkill(){
    //Generate a random number between 1-2.
    int chosenSkill=rand()%2+1;
    //Return the skill we randomly chose.
    return chosenSkill;
}

void Bandit::useSkillOn(int chosenSkill, Character *c){
    //Use the randomly chosen skill on the character.
    switch (chosenSkill){
        //Skill 2 is chosen: stun.
        case 2:{
            cout<<this->getName()<<" chose stun."<<endl;
            this->stun(c);
            break;
        }
        //Skill 1 is chosen: normal attack.
        default:{
            cout<<this->getName()<<" chose normal attack."<<endl;
            this->normalAttack(c);
            break;
        }
    }
}



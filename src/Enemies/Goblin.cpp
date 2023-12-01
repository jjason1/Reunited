#include "../../lib/Enemies/Goblin.hpp"

Goblin::Goblin(string name,int level) : Enemy::Enemy(name,level){
    //Setting our stat increments:
    int hpInc,defInc,atkInc;
    int baseHp=200,
        baseDef=90,
        baseAtk=30;
    hpInc = defInc = atkInc = 5;
    this->setIncrmnts(hpInc,defInc,atkInc);
    //Stats (For a Goblin):
    this->setHealth(baseHp+(level-1)*hpIncrmnt); 
    this->setDefense(baseDef+(level-1)*defIncrmnt);
    this->setAttack(baseAtk+(level-1)*atkIncrmnt);
}

void Goblin::lifeSwipe(Character *c){
    //Health to be stolen.
    int stolenHp=10;
    //Output attack message.
    cout<<this->getName()<<" used life swipe on "<<c->getName()
        <<" and stole "<<stolenHp<<" hp from "<<c->getName()<<"."<<endl;
    //The player's health is stolen.
    c->takeDamage(stolenHp);
    //The stolen hp is added to the goblin's hp.
    this->setHealth(this->getHealth()+stolenHp);
}

//Only 2 skills are available: 
//1. normal attack
//2. life swipe.
int Goblin::selectSkill(istream &){
    //Generate a random number between 1-2.
    int chosenSkill=rand()%2+1;
    //Return the skill we randomly chose.
    return chosenSkill;
}

void Goblin::useSkillOn(int chosenSkill, Character *c){
    //Use the randomly chosen skill on the character.
    switch (chosenSkill){
        //Skill 2 is chosen: life swipe.
        case 2:{
            cout<<this->getName()<<" chose life swipe."<<endl;
            this->lifeSwipe(c);
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
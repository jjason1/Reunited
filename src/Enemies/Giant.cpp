#include "../../lib/Enemies/Giant.hpp"

Giant::Giant(string name, int level) : Enemy::Enemy(name, level){
    this->setHealth(4000); 
    this->setDefense(1500);
    this->setAttack(50);
}

void Giant::RainOfHammers(Character *target){
    cout << this->getName()<<" used Rain of Hammers!" << endl;     
    target->takeDamage(this->getAttack()); // damageAmount is the damage dealt by this skill
}
    
void Giant::heavyBlow(Character *target){
    cout<<this->getName()<<" used heavy blow and stunned "<<target->getName()<<"."<<endl;
    target->takeDamage(this->getAttack());
    target->setMovable(false);   
}

int Giant::selectSkill(istream &in){
    int chosenSkill=rand()%3+1;
    //Return the skill we randomly chose.
    return chosenSkill;
}

void Giant::useSkillOn(int chosenSkill, Character *target){
    switch (chosenSkill){
        //Skill 3 is chosen: heavy blow.
        case 3:{
            cout<<this->getName()<<" chose heavy blow."<<endl;
            this->heavyBlow(target);
            break;
        }
        //Skill 2 is chosen: rain of hammers.
        case 2:{
            cout<<this->getName()<<" chose Rain Of Hammers."<<endl;
            this->RainOfHammers(target);
            break;
        }
        //Skill 1 is chosen: normal attack.
        default:{
            cout<<this->getName()<<" chose normal attack."<<endl;
            this->normalAttack(target);
            break;
        }
        
    }
}

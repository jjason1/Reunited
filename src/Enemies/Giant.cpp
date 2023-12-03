#include "../../lib/Enemies/Giant.hpp"

Giant::Giant(string name, int level) : Enemy::Enemy(name, level){
    this->setHealth(4000); 
    this->setDefense(1500);
    this->setAttack(50);
}

void Giant::WarCry(){
    //buff: next 3 turns double damage
}

void Giant::RainOfHammers(vector<Player *> &targets){
    cout << "Giant uses Rain of Hammers on all enemies!" << endl;
    for (Player* target : targets) {
        if (target != nullptr) { // Check if the pointer is not null
            // Assuming there is a takeDamage method in Character class
            target->takeDamage(this->getAttack()); // damageAmount is the damage dealt by this skill
            cout << "Caused " << this->getAttack() << " damge to each member" << endl;
        }
    }
}

void Giant::GoblinSummon(){
    //Enemy teams +2 Goblin
}

void Giant::heavyBlow(vector<Player *> &targets){
    int randomIndex = rand() % targets.size(); 
    Player* target = targets[randomIndex];

    target->takeDamage(this->getAttack());
    target->setMovable(false);
    cout<<this->getName()<<"Heavy blow and stunned "<<target->getName()<<"."<<endl;
}

int Giant::selectSkill(istream &in){
    int chosenSkill=rand()%5 + 1;
    //Return the skill we randomly chose.
    return chosenSkill;
}

void Giant::useSkillOn(int chosenSkill, vector<Player *> &targets){
    switch (chosenSkill){
        //Skill 5 is chosen: heavy blow.
        case 5:{
            cout<<this->getName()<<" chose  heavy blow."<<endl;
            this->heavyBlow(targets);
            break;
        }
        //Skill 4 is chosen: goblin summon.
        case 4:{
            cout<<this->getName()<<" chose goblin summon."<<endl;
            this->GoblinSummon();
            break;
        }
        //Skill 3 is chosen: rain Of hammers.
        case 3:{
            cout<<this->getName()<<" rain Of hammers."<<endl;
            this->RainOfHammers(targets);
            break;
        }
        //Skill 2 is chosen: war cry.
        case 2:{
            cout<<this->getName()<<" war cry."<<endl;
            this->WarCry();
            break;
        }
        //Skill 1 is chosen: normal attack.
        case 1:{
            cout<<this->getName()<<" normal attack."<<endl;

            int randomIndex = rand() % targets.size(); 
            Player* target = targets[randomIndex];

            this->normalAttack(target);
            break;
        }
        
    }
}
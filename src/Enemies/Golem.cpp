#include "../../lib/Enemies/Golem.hpp"
#include <iostream>

using namespace std;

//Golem is a boss, only one level.
Golem::Golem(string name, int level) : Enemy::Enemy(name, level) {
    this->setHealth(3000);
    this->setAttack(50);
    this->setDefense(1000);
    //CD = terms;
}

void Golem::lazerBlaze(Character *chracter) {
    chracter->takeDamage(this->getAttack() * 2); 
    cout<< this->getName() << " attacks " << chracter->getName() << " with lazer blaze!" <<endl;
}

void Golem::earthquake(vector<Character *> &chracters) {
     for (Character *chracter : chracters) {
        chracter->takeDamage(this->getAttack());
        cout<< this->getName() << " attacks " << chracter->getName() << " with earthquake!" <<endl;
     }
}

void Golem::shieldGen() {
    this->setHealth(this->getHealth() + 500);
    cout << this->getName() << " generates a protective shield of 500 HP!" <<endl;
}

int Golem::selectSkill(istream &in){
    //Generate a random number between 1-4.
    int chosenSkill=rand()%4+1;

    return chosenSkill;
}

void Golem::useSkillOn(int chosenSkill, vector<Character *> &chracters){
    //Use the randomly chosen skill on the character.
    switch (chosenSkill){
        //Skill 4 is shieldGen
        case 4:{
            cout<<this->getName()<<" chose shield generation."<<endl;
            this->shieldGen();
            break;
        }
        //Skill 3 is earthquake.
         case 3:{
            cout<<this->getName()<<" chose earthquake."<<endl;
            this->earthquake(chracters);
            break;
        }
        //Skill 2 is lazerBlaze.
         case 2:{
            cout<<this->getName()<<" chose lazer blaze."<<endl;
            int randomIndex = rand() % chracters.size(); // Random index
            Character* chracter = chracters[randomIndex]; // Get chracter at random index
            this->lazerBlaze(chracter);
            break;
        }
        //Skill 1 is normal attack.
         case 1:{
            cout<<this->getName()<<" chose lazer blaze."<<endl;
            int randomIndex = rand() % chracters.size(); // Random index
            Character* chracter = chracters[randomIndex]; // Get chracter at random index
            this->normalAttack(chracter);
            break;
        }
    }
}
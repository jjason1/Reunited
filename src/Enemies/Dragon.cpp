#include "../../lib/Enemies/Dragon.hpp"
#include <random>

Dragon::Dragon(string name, int level) : Enemy::Enemy(name, level){
    //This is a boss and only one level.
    this->setHealth(3500); 
    this->setDefense(1700);
    this->setAttack(40);
}

void Dragon::fireball(Character *c){
    random_device rd; 
    mt19937 eng(rd());
    uniform_real_distribution<> distr(1.25, 1.75);

    double fire = distr(eng);
    c->takeDamage(this->getAttack() * fire);
    cout << this->getName() << "fire balled " << c->getName();
}

void Dragon::annihilation(Character *c){
    int anni = 2;
    c->takeDamage(this->getAttack() * anni);
    cout << this->getName() << "used annihilation on " << c->getName();
}

void Dragon::dragonShadow(){
    //Enemy team +1 shadow dragon
}

int Dragon::selectSkill(istream &in){
    //Generate a random number between 1-4.
    int chosenSkill=rand()%4+1;
    //Return the skill we randomly chose.
    return chosenSkill;
}

void Dragon::useSkillOn(int chosenSkill, Character *c){
    switch (chosenSkill){
        //Skill 4 is chosen: dragonshadow.
        case 4:{
            cout<<this->getName()<<" chose dragon shadow."<<endl;
            this->dragonShadow();
            break;
        }
        //Skill 3 is chosen: annihilation.
        case 3:{
            cout<<this->getName()<<" chose annihilation."<<endl;
            this->annihilation(c);
            break;
        }
    }
}
#include "../../lib/Characters/Warrior.hpp"
using namespace std;
#include<iostream>
#include<string>

Warrior::Warrior(string name) : Character::Character(name){
    // Declare the increment
    
    int baseStats = 100;
    this->setHealth(baseStats);
    this->setDefense(baseStats);
    this->setAttack(baseStats);
    // Declare the base stat(Hp, Def, Atk = 100 at LV1)
    // this->setIncrmnts(hpInc, defInc, atkInc);
}

    //Strike is normal attack.
void Warrior::strike(Enemy *e) {
    cout << this->getName() << " used strikee on " << e->getName() << "." << endl;
    e->takeDamage(this->getAttack());
}

void Warrior::heavyStrike(Enemy *e) {
    //Only bonus after strike(Not implemented)
    double multiplier = 1.5;
    cout << this->getName() << " used heavy strike on " << e->getName() << "." << endl;
    e->takeDamage(this->getAttack() * multiplier);
}

void Warrior::warCry() {
    int warCry = 2;
    this->setAttack(warCry * this->getAttack());
    cout << this->getName() << " used War Cry, you gained double attack in next three terms." << endl;
}

void Warrior::stormStrike(Enemy *e) {
    //Only bonus after heavy strike(Not implemented)
    int bonus = 2;
    cout << this->getName() << " used storm strike on " << e->getName() << "." << endl;
    e->takeDamage(this->getAttack() * bonus);
}

void Warrior::bloodDraining() {
    double drain = 0.2;
    //in next 6 turns(Not implemented):
    this->setHealth(this->getHealth() + drain * this->getAttack());
    cout << this->getName() << " used bloodDraining, you gained  health from your attack." << endl;
}



void Warrior::heartOfAWarrior() {
    //in 5 turns:
    this->setHealth(1.2 * (this->getHealth() + this->getLevel() * hpIncrmnt));
    cout << this->getName() << " used heart of a warrior, increase 20% hp limit and regenerate 5% of hp in battle for 5 turns." << endl;
    
}

void Warrior::unstoppableFury() {
    //in 5 turns:
    if(this->getHealth() <= 0){
        this->setHealth(1);
    }
    rageBar = 100;
    cout << this->getName() << " used unstoppable fury, you won't die in next 5 rounds and your rage bar is full." << endl;
}

void Warrior::letTamBleed(Enemy *e){
    //in 10 turns:
    double bleed = 0.3;
    e->takeDamage(this->getAttack() * bleed);
    cout << this->getName() << " used let them bleed, you will gain health from your attack." << endl;
}

void Warrior::doomOfTheEnemy(Enemy *e){
    int doom = 4;
    if(rageBar >= 99){
        e->takeDamage(this->getAttack() * doom);
        cout << this->getName() << " used let them doom of enemy on " << e->getName() << endl;
    }
    else{
        cout << "Don't have enough rage bar to use the skill." << endl;
    }
}

void Warrior::listSkills(ostream &out){
    out << "Skills:\n";
    out << "--------------------------\n";
    out << "1: Strike\n";
    out << "2: Heavy Strike\n";
    out << "3: War Cry\n";
    out << "4: Storm Strike\n";
    out << "5: Heart of a Warrior\n";
    out << "6: Unstoppable Fury\n";
    out << "7: Let Them Bleed\n";
    out << "8: Doom of the Enemy\n";
    out << "\nSelect the skill you would like to use: " << endl;
}

int Warrior::selectSkill(istream &in)
{
    string skill="";
    stringstream ss;
    int numSkill=0;
    getline(in,skill);

    bool checkInputCorrect = false;
    for (int i = 1; i <= 8; i++) { // check the input is correct or not
        if (skill == to_string(i)) {
        checkInputCorrect = true;
        ss << skill;
        ss >> numSkill;
        return numSkill;
        }
    }

    while (!checkInputCorrect) { // wrong output will go in here and input again
        cout << "Please choose a target again:" << endl;
        getline(in, skill);
        for (int i = 1; i <= 8; i++) {
            if (skill == to_string(i)) {
                checkInputCorrect = true;
                ss << skill;
                ss >> numSkill;
                return numSkill;
            }
        }
    }
    return numSkill;
}


void Warrior::useSkillOn(int skill, Enemy *e){
    if (skill == 1)
    {
        cout << this->getName() << " chose strike." << endl;
        this->strike(e);
    }
    else if (skill == 2)
    {
        cout << this->getName() << " chose heavyStrike." << endl;
        this->heavyStrike(e);
    }
    else if (skill == 3)
    {
        cout << this->getName() << " chose war cry." << endl;
        this->warCry();
    }
    else if (skill == 4)
    {
        cout << this->getName() << " chose storm strike." << endl;
        this->stormStrike(e);
    }
    else if (skill == 5)
    {
        cout << this->getName() << " chose heart of a Warrior." << endl;
        this->heartOfAWarrior();
    }
    else if (skill == 6)
    {
        cout << this->getName() << " chose unstoppable fury." << endl;
        this->unstoppableFury();
    }
    else if (skill == 7)
    {
        cout << this->getName() << " chose let them bleed." << endl;
        this->letTamBleed(e);
    }
    else if (skill == 8)
    {
        cout << this->getName() << " chose doom of the enemy." << endl;
        this->doomOfTheEnemy(e);
    }
    else{
        cout<< "Please select a valid skill."<< endl;
    }
}

void Warrior::levelUp()
{

    int baseStats = 100;
    this->setHealth(baseStats);
    this->setDefense(baseStats);
    this->setAttack(baseStats);

    int hpInc,defInc,atkInc;
    hpInc =  defInc = 10;
    atkInc = 5;
    
    this->level++;
    this->setHealth(baseStats + (level - 1) * hpInc);
    this->setDefense(baseStats + (level - 1) * defInc);
    this->setAttack(baseStats + (level - 1) * atkInc);
}

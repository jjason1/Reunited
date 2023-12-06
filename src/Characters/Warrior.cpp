#include "../../lib/Characters/Warrior.hpp"
using namespace std;
#include<iostream>
#include<string>

Warrior::Warrior(string name) : Character::Character(name){
    // Declare the base stat(Hp, Def, Atk = 100 at LV1)
    int baseStats = 100;
    this->setHealth(baseStats);
    this->setDefense(baseStats);
    this->setAttack(baseStats);
    
    int hpInc,defInc,atkInc;
    hpInc =  defInc = 10;
    atkInc = 5;
    this->setIncrmnts(hpInc, defInc, atkInc);
}

//Strike is normal attack.
void Warrior::strike(Character *c) {
    cout << this->getName() << " used strike on " << c->getName() << "." << endl;
    c->takeDamage(this->getAttack());
}

void Warrior::heavyStrike(Character *c) {
   
    double multiplier = 1.5;
    cout << this->getName() << " used heavy strike on " << c->getName() << "." << endl;
    c->takeDamage(this->getAttack() * multiplier);
}

void Warrior::warCry() {
    int warCry = 2;
    this->setAttack(warCry * this->getAttack());
    cout << this->getName() << " used war cry, dealing double damage!" << endl;
}

void Warrior::stormStrike(Character *c) {
    int bonus = 2;
    cout << this->getName() << " used storm strike on " << c->getName() << "." << endl;
    c->takeDamage(this->getAttack() * bonus);
}

void Warrior::heartOfAWarrior() {
    int baseHp=100;
    this->setHealth(1.2 * (baseHp + (this->getLevel()-1) * hpIncrmnt));
    cout << this->getName() << " used heart of a warrior, resulting in all hp being restored in addition to a 20% increase." << endl;
    
}

void Warrior::listSkills(ostream &out){
    out << "Skills:\n";
    out << "--------------------------\n";
    out << "1: Strike\n";
    out << "2: Heavy Strike\n";
    out << "3: War Cry\n";
    out << "4: Storm Strike\n";
    out << "5: Heart of a Warrior\n";
    out << "\nSelect the skill you would like to use: " << endl;
}

int Warrior::selectSkill(istream &in)
{
    string skill="";
    stringstream ss;
    int numSkill=0;
    getline(in,skill);

    bool checkInputCorrect = false;
    for (int i = 1; i <= 5; i++) { // check the input is correct or not
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
        for (int i = 1; i <= 5; i++) {
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


void Warrior::useSkillOn(int skill, Character *c){
    if (skill == 1)
    {
        cout << this->getName() << " chose strike." << endl;
        this->strike(c);
    }
    else if (skill == 2)
    {
        cout << this->getName() << " chose heavy strike." << endl;
        this->heavyStrike(c);
    }
    else if (skill == 3)
    {
        cout << this->getName() << " chose war cry." << endl;
        this->warCry();
    }
    else if (skill == 4)
    {
        cout << this->getName() << " chose storm strike." << endl;
        this->stormStrike(c);
    }
    else if (skill == 5)
    {
        cout << this->getName() << " chose heart of a warrior." << endl;
        this->heartOfAWarrior();
    }
    else{
        cout<< "Please select a valid skill."<< endl;
    }
}

void Warrior::levelUp()
{
    this->level++;
    this->setHealth(100 + (this->getLevel() - 1) * this->hpIncrmnt);
    this->setDefense(100 + (this->getLevel() - 1) * this->defIncrmnt);
    this->setAttack(100 + (this->getLevel() - 1) * this->atkIncrmnt);
}

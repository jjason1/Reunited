#include "../lib/Characters/Warrior.hpp"
using namespace std;
#include<iostream>
#include<string>

Warrior::Warrior(string name) : Player::Player(name){
    // Declare the increment
    int hpInc,defInc,atkInc;
    hpInc =  defInc = 10;
    atkInc = 5;

    // Declare the base stat(Hp, Def, Atk = 100 at LV1)
    this->setIncrmnts(hpInc, defInc, atkInc);

    int baseStats = 100;
    this->setHealth(baseStats);
    this->setDefense(baseStats);
    this->setAttack(baseStats);

    //Strike is normal attack.
    void Warrior::strike(Enemy *e){
        cout << this->getName() << " used strikee on " << e->getName() << "." << endl;
        e->takeDamage(this->getAttack());
    }

    void Warrior::heavyStrike(Enemy *e){
        double multiplier = 1.5;
        cout << this->getName() << " used heavyStrike on " << e->getName() << "." << endl;
        e->takeDamage(this->getAttack() * multiplier);
    }
}
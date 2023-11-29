#include "../../lib/Characters/Mage.hpp"
#include <assert.h>

using namespace std;

Mage::Mage(string name) : Character::Character(name)
{
    this->boostedTurns = 0;
    int hpInc, defInc, atkInc, baseStat = 100;

    hpInc = atkInc = 10;
    defInc = 5;
    this->setIncrmnts(hpInc, defInc, atkInc);

    this->setAttack(baseStat);
    this->setDefense(baseStat);
    this->setHealth(baseStat);
}

void Mage::fireBall(Enemy *e)
{

    int multiplier = 1;

    if (this->boostedTurns > 0)
    {
        multiplier += 1;
        boostedTurns--;
    }

    cout << this->getName() << " used fire ball on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Mage::healing()
{
    int heal = 0.5 * this->getHealth();

    if(this->boostedTurns > 0){
        heal += 0.5 * this->getHealth();
        boostedTurns--;
    }
    
    this->setHealth(heal + this->getHealth());

    cout << this->getName() << " used healing." << endl;
    cout << this->getName() << " healed " << heal << " hp." << endl;
}

void Mage::iceStorm(Enemy *e)
{
    double multiplier = 0.5;
    if (this->boostedTurns > 0)
    {
        multiplier += 1;
        boostedTurns--;
    }

    cout << this->getName() << " used ice storm on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Mage::thunderBlast(Enemy *e)
{
    double multiplier = 1.5;

    if (this->boostedTurns > 0)
    {
        multiplier += 1;
        boostedTurns--;
    }

    cout << this->getName() << " used thunder blast on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Mage::skillBoost()
{
    boostedTurns++;
}
#include "../../lib/Characters/Mage.hpp"
#include <assert.h>

using namespace std;

Mage::Mage(string name) : Character::Character(name)
{
    this->boost = 0;
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

    if (this->boost > 0)
    {
        multiplier += 1;
        boost--;
    }

    cout << this->getName() << " used fire ball on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Mage::healing()
{
    int heal = 0.5 * this->getHealth();
    this->setHealth(heal + this->getHealth());

    cout << this->getName() << " healed its self." << endl;
}

void Mage::iceStorm(Enemy *e)
{
    double multiplier = 0.5;
    if (this->boost > 0)
    {
        multiplier += 1;
        boost--;
    }

    cout << this->getName() << " used ice storm on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Mage::thunderBlast(Enemy *e)
{
    double multiplier = 1.5;

    if (this->boost > 0)
    {
        multiplier += 1;
        boost--;
    }

    cout << this->getName() << " used thunder blast on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Mage::skillBoost()
{
    boost++;
}
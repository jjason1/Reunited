#include "../../lib/Characters/Samurai.hpp"
using namespace std;

Samurai::Samurai(string name) : Character::Character(name)
{
    int hpInc, defInc, atkInc, baseStat = 100;
    hpInc = defInc = 5;
    atkInc = 15;
    this->setIncrmnts(hpInc, defInc, atkInc);

    this->setHealth(baseStat);
    this->setDefense(baseStat);
    this->setAttack(baseStat);
}

void Samurai::directStrike(Enemy *e)
{

    cout << this->getName() << " used direct strike on " << e->getName() << "." << endl;
    e->takeDamage(this->getAttack());
}

void Samurai::sheathBlade(Enemy *e)
{
    double multiplier = 1.5;

    cout << this->getName() << " used sheath blade on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Samurai::wideRangeStrike(Enemy *e)
{

    double multiplier = 0.5;

    cout << this->getName() << " used wide range strike on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Samurai::shadowDegeneration(Enemy *e)
{
    double multiplier = 0.2;

    cout << this->getName() << " used shadow degeneration on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
}

void Samurai::smokeBomb(Enemy *e)
{

    double multiplier = 0.5;

    cout << this->getName() << " used smoke bomb on " << e->getName() << "." << endl;
    e->takeDamage(multiplier * this->getAttack());
    e->setMovable(false);
}
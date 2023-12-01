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

void Samurai::directStrike(Character *c)
{

    cout << this->getName() << " used direct strike on " << c->getName() << "." << endl;
    c->takeDamage(this->getAttack());
}

void Samurai::sheathBlade(Character *c)
{
    double multiplier = 1.5;

    cout << this->getName() << " used sheath blade on " << c->getName() << "." << endl;
    c->takeDamage(multiplier * this->getAttack());
}

void Samurai::wideRangeStrike(Character *c)
{

    double multiplier = 0.5;

    cout << this->getName() << " used wide range strike on " << c->getName() << "." << endl;
    c->takeDamage(multiplier * this->getAttack());
}

void Samurai::shadowDegeneration(Character *c)
{
    double multiplier = 0.2;

    cout << this->getName() << " used shadow degeneration on " << c->getName() << "." << endl;
    c->takeDamage(multiplier * this->getAttack());
}

void Samurai::smokeBomb(Character *c)
{

    double multiplier = 0.5;

    cout << this->getName() << " used smoke bomb on " << c->getName() << "." << endl;
    c->takeDamage(multiplier * this->getAttack());
    c->setMovable(false);
}

int Samurai::selectSkill(istream &){
    // Select one of your skills here. (Not implemented yet.)
    return 1;
}

void Samurai::useSkillOn(int skill, Character *c) {}

void Samurai::listSkills(ostream &) {}
#include "../../lib/Characters/Characters.hpp"
#include <assert.h>

using namespace std;

Characters::Character(string name)
{
    this->name = name;
    assert(name != "" && "Your name must not be empty!");

    this->level = 1;
    this->setHealth(0);
    this->setDefense(0);
    this->setAttack(0);
    this->setIncrmnts(0, 0, 0);
    this->setMovable(true);
    this->atkDstrbtn = 0;
}

void Characters::getStatus(ostream &out)
{
    out << endl;
    out << name << "'s Status: " << endl;
    out << "--------------------------\n";
    out << "Level   = " << level << endl;
    out << "Health  = " << health << endl;
    out << "Defense = " << defense << endl;
    out << "Attack  = " << attack << endl;
    out << endl;
}

string Characters::getName()
{
    return name;
}

void Characters::setAttack(int atk)
{
    this->attack = atk;
}

void Characters::setDefense(int def)
{
    this->defense = def;
}

void Characters::setHealth(int hp)
{
    this->health = hp;
}

void Characters::setIncrmnts(int hpInc, int defInc, int atkInc)
{
    this->hpIncrmnt = hpInc;
    this->defIncrmnt = defInc;
    this->atkIncrmnt = atkInc;
}

int Characters::getHealth()
{
    return this->health;
}

int Characters::getDefense()
{
    return this->defense;
}

int Characters::getAttack()
{
    return this->attack;
}

void Characters::setMovable(bool status)
{
    this->isMovable = status;
}

bool Characters::checkMovable()
{
    return this->isMovable;
}

void Characters::takeDamage(int dmg)
{
    this->health -= dmg;
}

void Characters::levelUp()
{
    level += 1;
}
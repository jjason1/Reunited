#include "../../lib/Characters/Character.hpp"
#include <assert.h>

using namespace std;

Character::Character(string name)
{
    this->name = name;
    assert(name != "" && "Your name must not be empty!");

    this->level = 1;
    this->setHealth(0);
    this->setDefense(0);
    this->setAttack(0);
    this->setIncrmnts(0, 0, 0);
    this->setMovable(true);
}

void Character::getStatus(ostream &out)
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

string Character::getName()
{
    return name;
}

void Character::setAttack(int atk)
{
    this->attack = atk;
}

void Character::setDefense(int def)
{
    this->defense = def;
}

void Character::setHealth(int hp)
{
    this->health = hp;
}

void Character::setIncrmnts(int hpInc, int defInc, int atkInc)
{
    this->hpIncrmnt = hpInc;
    this->defIncrmnt = defInc;
    this->atkIncrmnt = atkInc;
}

int Character::getHealth()
{
    return this->health;
}

int Character::getDefense()
{
    return this->defense;
}

int Character::getAttack()
{
    return this->attack;
}

void Character::setMovable(bool status)
{
    this->isMovable = status;
}

bool Character::checkMovable()
{
    return this->isMovable;
}

void Character::takeDamage(int dmg)
{
    this->health -= dmg;
}

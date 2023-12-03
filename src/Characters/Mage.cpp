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

void Mage::fireBall(Character *c)
{

    int multiplier = 1;

    if (this->boostedTurns > 0)
    {
        multiplier += 1;
        boostedTurns--;
    }

    cout << this->getName() << " used fire ball on " << c->getName() << "." << endl;
    c->takeDamage(multiplier * this->getAttack());
}

void Mage::healing()
{
    int heal = 0.5 * this->getHealth();

    if (this->boostedTurns > 0)
    {
        heal += 0.5 * this->getHealth();
        boostedTurns--;
    }

    this->setHealth(heal + this->getHealth());

    cout << this->getName() << " used healing." << endl;
    cout << this->getName() << " healed " << heal << " hp." << endl;
}

void Mage::iceStorm(Character *c)
{
    double multiplier = 0.5;
    if (this->boostedTurns > 0)
    {
        multiplier += 1;
        boostedTurns--;
    }

    cout << this->getName() << " used ice storm on " << c->getName() << "." << endl;
    c->takeDamage(multiplier * this->getAttack());
}

void Mage::thunderBlast(Character *c)
{
    double multiplier = 1.5;

    if (this->boostedTurns > 0)
    {
        multiplier += 1;
        boostedTurns--;
    }

    cout << this->getName() << " used thunder blast on " << c->getName() << "." << endl;
    c->takeDamage(multiplier * this->getAttack());
}

void Mage::skillBoost()
{
    boostedTurns++;
}

void Mage::listSkills(ostream &out)
{
    out << endl;
    out << "Skills" << endl;
    out << "--------------------------\n";
    out << "1. Fireball" << endl;
    out << "2. Heal" << endl;
    out << "3. Ice storm" << endl;
    out << "4. Thunder blast" << endl;
    out << "5. Skill boost" << endl;
    out << "Select the skill you would like use: " << endl;
}

int Mage::selectSkill(istream &in)
{
    int skill;

    listSkills(cout);
    in >> skill;

    while (skill < 1 || skill > 5)
    {
        listSkills(cout);
        cout << "Invalid input. Please enter a number between 1 and 5." << endl;
        in.clear();                                         // Clear input stream to handle non-integer inputs
        in.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        in >> skill;
    }
    return skill;
}

void Mage::useSkillOn(int skill, Character *c)
{
    if (skill == 1)
    {
        cout << this->getName() << " chose fireball." << endl;
        this->fireBall(c);
    }
    else if (skill == 2)
    {
        cout << this->getName() << " chose heal." << endl;
        this->healing();
    }
    else if (skill == 3)
    {
        cout << this->getName() << " chose ice storm." << endl;
        this->iceStorm(c);
    }
    else if (skill == 4)
    {
        cout << this->getName() << " chose thunder blast." << endl;
        this->thunderBlast(c);
    }
    else
    {
        cout << this->getName() << " chose skill boost." << endl;
        this->skillBoost();
    }
}

void Mage::levelUp()
{
    // Base stats:
    int baseHp = 100,
        baseDef = 100,
        baseAtk = 100;
    // Updating level + stats:
    this->level++;
    this->setHealth(baseHp + (level - 1) * hpIncrmnt);
    this->setDefense(baseDef + (level - 1) * defIncrmnt);
    this->setAttack(baseAtk + (level - 1) * atkIncrmnt);
}
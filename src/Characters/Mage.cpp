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

    if (this->boostedTurns > 0)
    {
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
    out << "Select the skill you would like use" << endl;
    out << endl;
}

int Mage::selectSkill()
{
    int skill;
    ostream &out = cout;
    istream &in = cin;

    listSkills(out);
    in >> skill;

    while (skill < 1 || skill > 5)
    {
        listSkills(out);
        out << "Invalid input. Please enter a number between 1 and 5." << endl;
        in.clear();                                         // Clear input stream to handle non-integer inputs
        in.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        in >> skill;
    }
    return skill;
}

void Mage::useSkillOn(int skill, Enemy *e)
{
    if (skill == 1)
    {
        cout << this->getName() << " chose fireball." << endl;
        this->fireBall(e);
    }
    else if (skill == 2)
    {
        cout << this->getName() << " chose heal." << endl;
        this->healing();
    }
    else if (skill == 3)
    {
        cout << this->getName() << " chose ice storm." << endl;
        this->iceStorm(e);
    }
    else if (skill == 4)
    {
        cout << this->getName() << " chose thunder blast." << endl;
        this->thunderBlast(e);
    }
    else
    {
        cout << this->getName() << " chose skill boost." << endl;
        this->skillBoost();
    }
}
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

void Samurai::listSkills(ostream &out)
{
    out << endl;
    out << "Skills" << endl;
    out << "--------------------------\n";
    out << "1. Direct strike" << endl;
    out << "2. Sheath blade" << endl;
    out << "3. Wide range strike" << endl;
    out << "4. Shadow degeneration" << endl;
    out << "5. Smoke bomb" << endl;
    out << "Select the skill you would like use" << endl;
    out << endl;
}
int Samurai::selectSkill()
{
    int skill;
    stringstream ss;
    listSkills(ss);
    cin >> skill;

    while (skill == 0 || skill >= 6)
    {
        listSkills(ss);
        cin >> skill;
    }

    return skill;
}

void Samurai::useSkillOn(int skill, Enemy *e)
{
    if (skill == 1)
    {
        cout << this->getName() << " chose direct strike." << endl;
        this->directStrike(e);
    }
    else if (skill == 2)
    {
        cout << this->getName() << " chose sheath blade." << endl;
        this->sheathBlade(e);
    }
    else if (skill == 3)
    {
        cout << this->getName() << " chose wide range strike." << endl;
        this->wideRangeStrike(e);
    }
    else if (skill == 4)
    {
        cout << this->getName() << " chose shadow degeneration." << endl;
        this->shadowDegeneration(e);
    }
    else
    {
        cout << this->getName() << " chose smoke bomb." << endl;
        this->smokeBomb(e);
    }
}

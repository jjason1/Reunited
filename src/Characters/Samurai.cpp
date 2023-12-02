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
    out << "\nSelect the skill you would like to use: " << endl;
}
int Samurai::selectSkill(istream &in)
{
    string skill="";
    stringstream ss;
    int numSkill=0;
    getline(in,skill);

    bool checkInputCorrect = false;
    for (int i = 1; i <= 5; i++) { // check the input is correct or not
        if (skill == to_string(i)) {
        checkInputCorrect = true;
        ss << skill;
        ss >> numSkill;
        return numSkill;
        }
    }

    while (!checkInputCorrect) { // wrong output will go in here and input again
        cout << "Please choose a target again:" << endl;
        getline(in, skill);
        for (int i = 1; i <= 5; i++) {
            if (skill == to_string(i)) {
                checkInputCorrect = true;
                ss << skill;
                ss >> numSkill;
                return numSkill;
            }
        }
    }
    return numSkill;
}

void Samurai::useSkillOn(int skill, Character *c)
{
    if (skill == 1)
    {
        cout << this->getName() << " chose direct strike." << endl;
        this->directStrike(c);
    }
    else if (skill == 2)
    {
        cout << this->getName() << " chose sheath blade." << endl;
        this->sheathBlade(c);
    }
    else if (skill == 3)
    {
        cout << this->getName() << " chose wide range strike." << endl;
        this->wideRangeStrike(c);
    }
    else if (skill == 4)
    {
        cout << this->getName() << " chose shadow degeneration." << endl;
        this->shadowDegeneration(c);
    }
    else
    {
        cout << this->getName() << " chose smoke bomb." << endl;
        this->smokeBomb(c);
    }
}

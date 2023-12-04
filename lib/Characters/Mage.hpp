#ifndef MAGE_HPP
#define MAGE_HPP

#include "Character.hpp"
#include "../Enemies/Enemy.hpp"

#include <iostream>
using namespace std;

class Mage : public Character
{
private:
    int manaBar;
    unsigned int boostedTurns;

public:
    Mage(string);
    void fireBall(Character *);
    void healing();
    void iceStorm(Character *);
    void thunderBlast(Character *);
    void skillBoost();

    virtual void listSkills(ostream &);
    virtual int selectSkill(istream &);
    virtual void useSkillOn(int, Character *);
    virtual void levelUp();
};

#endif
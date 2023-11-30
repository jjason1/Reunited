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
    void fireBall(Enemy *);
    void healing();
    void iceStorm(Enemy *);
    void thunderBlast(Enemy *);
    void skillBoost();

    virtual void listSkills(ostream &);
    virtual int selectSkill();
    virtual void useSkillOn(int, Enemy *);
};

#endif
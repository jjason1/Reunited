#ifndef SAMURAI_HPP
#define SAMURAI_HPP

#include "Character.hpp"
#include "../Enemies/Enemy.hpp"

#include <iostream>
using namespace std;

class Samurai : public Character
{
public:
    Samurai(string);
    void directStrike(Character *);
    void sheathBlade(Character *);
    void wideRangeStrike(Character *);
    void shadowDegeneration(Character *);
    void smokeBomb(Character *);

    virtual void listSkills(ostream &);
    virtual int selectSkill();
    virtual void useSkillOn(int, Character *);
};

#endif
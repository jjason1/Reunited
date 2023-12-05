#ifndef SAMURAI_HPP
#define SAMURAI_HPP

#include "Character.hpp"
#include "../Enemies/Enemy.hpp"
#include <sstream>
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
    virtual int selectSkill(istream &);
    virtual void useSkillOn(int, Character *);
    virtual void levelUp();
};

#endif
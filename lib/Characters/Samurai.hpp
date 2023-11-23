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
    void directStrike(Enemy *);
    void sheathBlade(Enemy *);
    void wideRangeStrike(Enemy *);
    void shadowDegeneration(Enemy *);
    void smokeBomb(Enemy *);
};

#endif
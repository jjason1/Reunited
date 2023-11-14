#ifndef SAMURAI_HPP
#define SAMURAI_HPP
#include "Characters.hpp"

#include <iostream>
using namespace std;

class Samurai : public Characters{
public:
    void directStrike(Enemy *);
    void sheathBlade(Enemy *);
    void wideRangeStrike(Enemy *);
    void smokeBomb(Enemy *);
    void shadowDegeneration(Enemy *);
}

#endif
#ifndef GIANT_HPP
#define GIANT_HPP

#include<vector>

using namespace std;

#include "Enemy.hpp"
#include "../Characters/Character.hpp"

class Giant : public Enemy {
    public:
    Giant(string, int);
    void RainOfHammers(Character *);
    void heavyBlow(Character *);

    virtual int selectSkill(istream &);
    virtual void useSkillOn(int, Character *);
};

#endif /* GIANT_HPP */
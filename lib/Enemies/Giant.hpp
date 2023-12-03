#ifndef GIANT_HPP
#define GIANT_HPP

#include<vector>

using namespace std;

#include "Enemy.hpp"
#include "../Characters/Player.hpp"

class Giant : public Enemy {
    public:
    Giant(string, int);
    void WarCry();
    void RainOfHammers(vector<Player *> &);
    void GoblinSummon();
    void heavyBlow(vector<Player *> &);

    virtual int selectSkill(istream &);
    virtual void useSkillOn(int, vector<Player *> &);
};

#endif /* GIANT_HPP */
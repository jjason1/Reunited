#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"
#include "../Enemies/Enemy.hpp"


class Warrior : Character {
    private:
        int rageBar = 0;
    public:
        Warrior(string name, int level);
        void strike(Enemy *);
        void heavyStrike(Enemy *);
        void warCry();
        void stormStrike(Enemy *);
        void bloodDraining();
        void rageBurst();
        void taunt(Enemy *);
        void heartOfAWarrior();
        void unstoppableFury();
        void letTamBleed(Enemy *);
        void doomOfTheEnemy(Enemy *);

};

#endif / * WARRIOR_HPP * /
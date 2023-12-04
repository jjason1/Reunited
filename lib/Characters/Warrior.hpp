#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"
#include "../Enemies/Enemy.hpp"
#include <iostream>

using namespace std;

class Warrior : public Character {
    private:
        int rageBar = 0;
    public:
        Warrior(string);
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

        virtual void listSkills(ostream &);
        virtual int selectSkill(istream &);
        virtual void useSkillOn(int, Enemy *);
        virtual void levelUp();

};

#endif 
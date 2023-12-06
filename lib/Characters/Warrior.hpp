#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"
#include "../Enemies/Enemy.hpp"
#include <iostream>
#include "../checkInput.h"
using namespace std;

class Warrior : public Character {
    private:
        int rageBar = 0;
    public:
        Warrior(string);
        void strike(Character *);
        void heavyStrike(Character *);
        void warCry();
        void stormStrike(Character *);
        void bloodDraining();
        void rageBurst();
        void taunt(Character *);
        void heartOfAWarrior();
        void unstoppableFury();
        void letTamBleed(Character *);
        void doomOfTheEnemy(Character *);

        virtual void listSkills(ostream &);
        virtual int selectSkill(istream &);
        virtual void useSkillOn(int, Character *);
        virtual void levelUp();

};

#endif 
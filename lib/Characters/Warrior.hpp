#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Player.hpp"
#include "../Enemies/Enemy.hpp"



class Warrior : public Player {
    private:
        int rageBar = 0;
    public:
        Warrior(string);
        void strike(Enemy *);
        void heavyStrike(Enemy *);
        void warCry();
        void stormStrike(Enemy *);
        void bloodDraining();
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
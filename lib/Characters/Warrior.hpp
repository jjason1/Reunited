#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "../final-project-akhan197-bli181-cchua042-jlin379/lib/Characters/Player.hpp"



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
        void rageBurst();
        void taunt(Enemy *);
        void heartOfAWarrior();
        void unstoppableFury();
        void letTamBleed(Enemy *);
        void doomOfTheEnemy(Enemy *);

        virtual void listSkills(ostream &);
        virtual int selectSkill();
        virtual void useSkillOn(int, Enemy *);


};

#endif / * WARRIOR_HPP * /
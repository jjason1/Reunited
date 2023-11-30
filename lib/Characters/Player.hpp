#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Characters/Character.hpp"

#include <iostream>
#include <string>

using namespace std;

class Player : public Character {
    private:
        int atkDstrbtn;
        int HpInc;
    public:
        Player(string name);
        virtual void listSkills(ostream &out);
        virtual int selectSkill();
        void setAtkDstrbtn(int distribution);
        int getAtkDstrbtn();
        void resetHealth(int HpInc);

};

#endif
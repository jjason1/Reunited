#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player : public Character {
    private:
        int atkDstrbtn;
    public:
        Player(string name);
        virtual void listSkills(ostream &out);
        virtual int selectSkill(istream &in);
        void setAtkDstrbtn(int distribution);
        int getAtkDstrbtn();
        void resetHealth();
};

#endif

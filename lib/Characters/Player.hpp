#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Characters/Character.hpp"

#include <iostream>
#include <string>

using namespace std;

virtual Player : public Character {
    private:
        int atkDstrbtn;
    
    public:
        Player(string name);
        virtual void listSkills(ostream &out);
        virtual int selectSkill(const string &skillName);
        void setAtkDstrbtn(int distribution);
        int getAtkDstrbtn();
        void levelUp();

};

#endif
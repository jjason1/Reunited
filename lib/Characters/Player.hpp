#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Characters/Character.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player : public Character {
    private:
        int atkDstrbtn;
        vector<string> skills;
        string currentSkill;
    public:
        Player(string name, int leavel);
        void listSkills(ostream &out);
        virtual void selectSkill(const string &skillName);
        void setAtkDstrbtn(int distribution);
        int getAtkDstrbtn();
        void levelUp();

};

#endif
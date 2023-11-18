#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class Player : public Character
{
private:
    int atkDstrbtn;

public:
    Player(string);
    void setAtkDstrbtn(int);
    int getAtkDstrbtn();
    void levelUp();
    // void listSkills(ostream &);
    // virtual void selectSkill(const string &);
}

#endif
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <fstream>
#include "Character.hpp"
#include <istream>
#include <ostream>

using namespace std;

class Character
{
protected:
    int health,
        defense,
        attack,
        hpIncrmnt,
        defIncrmnt,
        atkIncrmnt,
        level;
    bool isMovable;
    string name;

public:
    Character(string);
    void setHealth(int);
    void setDefense(int);
    void setAttack(int);
    void setIncrmnts(int, int, int);
    int getHealth();
    int getDefense();
    int getAttack();
    int getLevel();
    string getName();
    void getStatus(ostream &);
    void takeDamage(int);
    bool checkMovable();
    void setMovable(bool);

    virtual void listSkills(ostream &);
    virtual int selectSkill(istream &);
    virtual void useSkillOn(int, Character *);
    virtual void levelUp();
};

#endif

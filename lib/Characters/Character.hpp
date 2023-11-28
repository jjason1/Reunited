#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <fstream>
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
    virtual int selectSkill();
    virtual void useSkillOn(int, Character *);
};

#endif
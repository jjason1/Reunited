#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <fstream>
using namespace std;

class Character
{
private:
    int health,
        defense,
        attack,
        hpIncrmnt,
        defIncrmnt,
        atkIncrmnt,
        level,
        atkDstrbtn;

    bool isMovable;
    string name;

public:
    Character(string);
    int getAtkDstrbtn();
    void setAtkDstrbtn(int);
    void getStatus(ostream &);
    void setHealth(int);
    void setDefense(int);
    void setAttack(int);
    void setIncrmnts(int, int, int);
    void levelUp();
    void takeDamage(int);
    void setMovable(bool);
    int getHealth();
    int getDefense();
    int getAttack();
    string getName();
    bool checkMovable();
};

#endif
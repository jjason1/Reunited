#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include "Character.h"
using std::string;

class Warrior: public Character
{
private:
    int rageBar;

public:
    Warrior(const string& name);
    ~Warrior();
};



#endif
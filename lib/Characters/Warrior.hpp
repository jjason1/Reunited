#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include "Character.hpp"
using std::string;

class Warrior: public Character
{
private:
    int rageBar;

public:
    Warrior(string name);
    ~Warrior();
};

#endif
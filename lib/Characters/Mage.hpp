#include "Character.hpp"
#include "../Enemies/Enemy.hpp"

#include <iostream>
using namespace std;

class Mage : public Character
{
private:
    int manaBar;

public:
    Mage(string);
    void fireBall(Enemy *);
    void healing();
    void iceStorm(Enemy *);
    void thunderBlast(Enemy *);
    void skillBoost();
}
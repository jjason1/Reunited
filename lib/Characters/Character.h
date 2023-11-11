
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using std::string;


class Character 
{
private:
    int health;
    int defense;
    int attack;
    int hpIncrmnt;
    int defIncrmnt;
    int atkIncrmnt;
    bool isMovable;
    int atkDstrbtn;
    string name;
    int level;

public:
    Character(const string& n);
    ~Character();
    void showCharacterStatus();
    void levelUp();
    string showCharacterName();
};

#endif
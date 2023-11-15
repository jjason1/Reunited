#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "../Characters/Character.hpp"
using namespace std;

class Enemy {
    private:
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
        Enemy(string, int);
        void getStatus(ostream &);
        string getName();
        bool checkMovable();
        void setHealth(int);
        void setDefense(int);
        void setAttack(int);
        int getHealth();
        int getDefense();
        int getAttack();
        void setIncrmnts(int,int,int);
        void setMovable(bool);
        void takeDamage(int);
        void normalAttack(Character *);
};

#endif /* ENEMY_HPP */
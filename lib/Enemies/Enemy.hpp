#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <fstream>
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
        void takeDamage();
    public:
        void getStatus(ostream &);
        string getName();
        Enemy(string, int);
        //void normalAttack(Character *);
};

#endif /* ENEMY_HPP */
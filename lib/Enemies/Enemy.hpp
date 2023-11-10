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
<<<<<<< HEAD
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
=======
        void takeDamage();
    public:
        void getStatus(ostream &);
        string getName();
        Enemy(string, int);
>>>>>>> c60040b (Adding an enemy class and tests)
        //void normalAttack(Character *);
};

#endif /* ENEMY_HPP */
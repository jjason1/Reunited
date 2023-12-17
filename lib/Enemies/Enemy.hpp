#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include "../Characters/Character.hpp"
using namespace std;

class Enemy : public Character {
    public:
        Enemy(string, int);
        void normalAttack(Character *);
        virtual int selectSkill(istream &);
        virtual void useSkillOn(int, Character *);
};

#endif /* ENEMY_HPP */
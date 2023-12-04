#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "Enemy.hpp"
#include "../Characters/Character.hpp"

class Dragon : public Enemy {        
    public:
        Dragon(string, int);
        void fireball(Character *);
        void annihilation(Character *)
        void dragonShadow();

        virtual int selectSkill(istream &);
        virtual void useSkillOn(int, Character *);
};

#endif /* DRAGON_HPP */
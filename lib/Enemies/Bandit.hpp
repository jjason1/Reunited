#ifndef BANDIT_HPP
#define BANDIT_HPP

#include "Enemy.hpp"
#include "../Characters/Character.hpp"

class Bandit : public Enemy {        
    public:
        Bandit(string,int);
        void stun(Character *);
};

#endif /* BANDIT_HPP */
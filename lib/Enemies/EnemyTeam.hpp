#ifndef ENEMYTEAM_HPP
#define ENEMYTEAM_HPP

#include "Enemy.hpp"
#include "../Characters/Character.hpp"
#include <vector>

class EnemyTeam {
    private:
        vector<Enemy *> enemyList;
    public:
        EnemyTeam(vector<Enemy *>);
        int getSize();
        Character * chooseTarget(vector<Character *>,int);
        void addEnemy(Enemy *);
};

#endif /* ENEMYTEAM_HPP */
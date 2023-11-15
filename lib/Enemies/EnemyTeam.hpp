#ifndef ENEMYTEAM_HPP
#define ENEMYTEAM_HPP

#include "Enemy.hpp"
#include "../Characters/Character.hpp"
#include <vector>

class EnemyTeam {
    private:
        int numEnemies;
        vector<Enemy *> enemyList;
    public:
        EnemyTeam(vector<Enemy *>);
        void setSize(int);
        int getSize();
        Character * chooseTarget(vector<Character *>,int);
        void addEnemy(Enemy *);
};

#endif /* ENEMYTEAM_HPP */
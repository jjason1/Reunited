#ifndef ENEMYTEAM_HPP
#define ENEMYTEAM_HPP

#include "Enemy.hpp"
#include "../Characters/CharacterTeam.hpp"

class EnemyTeam : public CharacterTeam {
    public:
        EnemyTeam(vector<Character *>);
        Character * chooseTarget(vector<Character *>);
        void addEnemy(Enemy *);
};

#endif /* ENEMYTEAM_HPP */
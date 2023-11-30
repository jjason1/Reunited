#ifndef ENEMYTEAM_HPP
#define ENEMYTEAM_HPP

#include "Enemy.hpp"
#include "../Characters/CharacterTeam.hpp"

class EnemyTeam : public CharacterTeam {
    public:
        EnemyTeam(vector<Character *>, ostream &);
        Character *chooseTarget(vector<Character *>);
};

#endif /* ENEMYTEAM_HPP */
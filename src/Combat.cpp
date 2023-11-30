#include "../lib/Combat.hpp"

Combat::Combat(PlayerTeam *pTeam, EnemyTeam *eTeam, ostream &outout,
               istream &inin)
    : playerTeam(pTeam), enemyTeam(eTeam), out(outout), in(inin) {
  turns = 0;
}



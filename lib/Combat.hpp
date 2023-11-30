#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "../lib/Characters/PlayerTeam.hpp"
#include "../lib/Enemies/EnemyTeam.hpp"
#include <istream>
#include <ostream>

class Combat {
private:
  int turns;
  PlayerTeam *OriginalPlayerTeam; // store the original health and name of player
  PlayerTeam *playerTeam;
  PlayerTeam *outPlayerTeam; // store players that is already has hp<=0
  EnemyTeam *OriginalEnemyTeam; // store the original health and name of enemy
  EnemyTeam *enemyTeam;
  EnemyTeam *outEnemyTeam; // store enemies that is already has hp<=0
  ostream &out;
  istream &in;

public:
  Combat(PlayerTeam *, EnemyTeam *, ostream &, istream &);
  void startBattle();
  int showCurrentTurn();
  bool checkBattleEnd(); // check if either team all have been eliminated
  void resetCombat(); // reset combat when restart the combat
  bool chooseRestart(); // activated after defeated, choose escape the fight and
                        // pretend winning or restart the fight
  PlayerTeam *getPlayerTeam();
  PlayerTeam *getOutPlayerTeam();
  PlayerTeam *getOriginalPlayerTeam();
  EnemyTeam *getEnemyTeam();
  EnemyTeam *getOutEnemyTeam();
  EnemyTeam *getOriginalEnemyTeam();
};

#endif
#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "../lib/Characters/PlayerTeam.hpp"
#include "../lib/Enemies/EnemyTeam.hpp"
#include <istream>
#include <ostream>

class Combat {
    private:
      int turns;
      PlayerTeam *OriginalPlayerTeam; // store the original team 
      PlayerTeam *playerTeam;         // store the active team
      PlayerTeam *outPlayerTeam;    // store defeated players
      EnemyTeam *OriginalEnemyTeam; // store the original enemy team 
      EnemyTeam *enemyTeam;
      EnemyTeam *outEnemyTeam; // store defeated enemies
      ostream &out;
      istream &in;

    public:
      Combat(PlayerTeam *, EnemyTeam *, ostream &, istream &);
      ~Combat();
      void startBattle();
      int showCurrentTurn();
      bool checkBattleEnd(); // check if either team all have been eliminated
      void resetCombat();    // reset combat when restart the combat
      bool chooseRestart();  // activated after defeated, choose escape the fight and
                             // pretend winning or restart the fight
      void showAllCharactersStatus();
      PlayerTeam *getPlayerTeam();
      PlayerTeam *getOutPlayerTeam();
      PlayerTeam *getOriginalPlayerTeam();
      EnemyTeam *getEnemyTeam();
      EnemyTeam *getOutEnemyTeam();
      EnemyTeam *getOriginalEnemyTeam();

};

#endif

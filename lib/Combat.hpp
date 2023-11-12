#ifndef COMBAT_H
#define COMBAT_H
#include <string>
#include "./Characters/Character.hpp"
#include "./Enemies/Enemy.hpp"
#include <vector>
using std::string;
class Combat {
private:
  int turns;
  std::vector<Character *> characterTeam;
  std::vector<Enemy *> enemyTeam;
  

public:
  void starBattle();
  int showCurrentTurn();
  bool checkBattleEnd();
  Combat(vector<Character*>, vector<Enemy*>);
};
#endif
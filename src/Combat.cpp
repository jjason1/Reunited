#include "../lib/Combat.hpp"
#include <algorithm>
#include <vector>

Combat::Combat(PlayerTeam *pTeam, EnemyTeam *eTeam, ostream &outout,
               istream &inin)
    : OriginalPlayerTeam(pTeam), OriginalEnemyTeam(eTeam), out(outout),
      in(inin) {
  playerTeam = new PlayerTeam(*OriginalPlayerTeam);
  enemyTeam = new EnemyTeam(*OriginalEnemyTeam);
  vector<Character *> cPTeam, cETeam;
  outPlayerTeam = new PlayerTeam(cPTeam, out, in);
  outEnemyTeam = new EnemyTeam(cETeam, out);
  turns = 0;
}

int Combat::showCurrentTurn() {
  out << "Current turn is: " << this->turns << endl;
  return this->turns;
}

bool Combat::checkBattleEnd() {
  // check player team members' status and put down member to out
  vector<Character *> pTeam = playerTeam->getCharacters();
  for (auto player : pTeam) {
    if (player->getHealth() <= 0) {
      outPlayerTeam->addCharacter(player);
      pTeam.erase(std::remove(pTeam.begin(), pTeam.end(), player), pTeam.end());
    }
  }
  if (pTeam.empty()) {
    return true;
  }
  // check enemy team members' status and put down member to out
  vector<Character *> eTeam = enemyTeam->getCharacters();
  for (auto enemy : eTeam) {
    if (enemy->getHealth() <= 0) {
      outPlayerTeam->addCharacter(enemy);
      pTeam.erase(std::remove(pTeam.begin(), pTeam.end(), enemy), pTeam.end());
    }
  }
  if (eTeam.empty()) {
    return true;
  }
  return false;
}

void Combat::resetCombat() {
  // add all down player member back to team
  playerTeam = new PlayerTeam(*OriginalPlayerTeam);
  outPlayerTeam->getCharacters().clear();

  enemyTeam = new EnemyTeam(*OriginalEnemyTeam);
  outEnemyTeam->getCharacters().clear();
  turns = 0;
  this->startBattle();
}

void Combat::startBattle() {
  while (!checkBattleEnd()) {
    // players' turn
    for (auto player : playerTeam->getCharacters()) {
      if (player->checkMovable()) {
        Character *target =
            playerTeam->chooseTarget(enemyTeam->getCharacters());
        player->listSkills(out);
        player->useSkillOn(player->selectSkill(), target);
      }
      player->setMovable(true);
    }

  }
}
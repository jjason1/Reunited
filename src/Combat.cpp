#include "../lib/Combat.hpp"
#include <algorithm>
#include <string>
#include <type_traits>
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

PlayerTeam *Combat::getPlayerTeam() {
  return playerTeam;
}
PlayerTeam *Combat::getOutPlayerTeam() {
  return outPlayerTeam;
}
EnemyTeam *Combat::getEnemyTeam() {
  return enemyTeam;
}
EnemyTeam *Combat::getOutEnemyTeam() {
  return outEnemyTeam;
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

bool Combat::chooseRestart() {
  out << "Combat End." << endl;
  out << "Please choose a option:" << endl;
  out << "1- escape and pretend you win" << endl;
  out << "2- restart the battle" << endl;
  string input;
  getline(in, input);
  if (input == "1") {
    out << "You win the battle" << endl;
    return false;
  } else if (input == "2") {
    return true;
  } else {
    while (!(input == "1" || input == "2")) {
      out << "Please choose a option again:" << endl;
      getline(in, input);
      if (input == "1") {
        return false;
      } else if (input == "2") {
        return true;
      }
    }
  }
  return false;
}

void Combat::startBattle() {
  out << "Battle Start!" << endl;
  while (!checkBattleEnd()) {
    // players' turn
    turns++;
    out << "Turn:" << showCurrentTurn() << endl;
    for (auto player : playerTeam->getCharacters()) {
      if (player->checkMovable() && player->getHealth() > 0) { //only character that is movable and not dead can attack
        Character *target =
            playerTeam->chooseTarget(enemyTeam->getCharacters());
        player->listSkills(out);
        player->useSkillOn(player->selectSkill(), target);
      }
      player->setMovable(true);
    }
    // enemy's turn
    for (auto enemy : enemyTeam->getCharacters()) {
      if (enemy->checkMovable() && enemy->getHealth() > 0) { //only character that is movable and not dead can attack
        Character *target =
            enemyTeam->chooseTarget(playerTeam->getCharacters());
        enemy->useSkillOn(enemy->selectSkill(), target);
      }
      enemy->setMovable(true);
    }
    
  }
  if (playerTeam->getCharacters().empty()) {
    bool restart = chooseRestart();
    if (restart) { // restart battle and reset all characters to original status
      resetCombat();
      startBattle();
    }
  }
  out << "You win the battle." << endl;
  out << "Battle End." << endl;

}
#include "../lib/Combat.hpp"
#include "../lib/Characters/Player.hpp"
#include <algorithm>
#include <string>
#include <type_traits>
#include <vector>

Combat::Combat(PlayerTeam *pTeam, EnemyTeam *eTeam, 
               ostream &outout, istream &inin)
    : OriginalPlayerTeam(pTeam), OriginalEnemyTeam(eTeam), 
    out(outout), in(inin) {
    playerTeam = new PlayerTeam(*OriginalPlayerTeam);
    enemyTeam = new EnemyTeam(*OriginalEnemyTeam);
  //store the status of our original players
  vector<Character *> NewOriginalPlayerCharacters{}, NewOriginalEnemyCharacters{}; 
  for (auto player : OriginalPlayerTeam->getCharacters()) {
    Player *storedPlayerStatus = new Player(player->getName());
    storedPlayerStatus->setHealth(player->getHealth());
    NewOriginalPlayerCharacters.push_back(storedPlayerStatus);
  }
  OriginalPlayerTeam = new PlayerTeam(NewOriginalPlayerCharacters, out, in);
  //store status for original enemies
  for (auto enemy : OriginalEnemyTeam->getCharacters()) {
    Enemy *storedEnemyStatus = new Enemy(enemy->getName(), enemy->getLevel());
    storedEnemyStatus->setHealth(enemy->getHealth());
    NewOriginalEnemyCharacters.push_back(storedEnemyStatus);
  }
  OriginalEnemyTeam = new EnemyTeam(NewOriginalEnemyCharacters,out);
  //Setting out teams
  vector<Character *> cPTeam{}, cETeam{};
  outPlayerTeam = new PlayerTeam(cPTeam, out, in);
  outEnemyTeam = new EnemyTeam(cETeam, out);
  turns = 0;
}

PlayerTeam *Combat::getPlayerTeam() { return playerTeam; }
PlayerTeam *Combat::getOutPlayerTeam() { return outPlayerTeam; }
PlayerTeam *Combat::getOriginalPlayerTeam() { return OriginalPlayerTeam; }

EnemyTeam *Combat::getEnemyTeam() { return enemyTeam; }
EnemyTeam *Combat::getOutEnemyTeam() { return outEnemyTeam; }
EnemyTeam *Combat::getOriginalEnemyTeam() { return OriginalEnemyTeam; }



int Combat::showCurrentTurn() {
  out << "Current Turn: " << this->turns << endl;
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
  delete playerTeam;
  playerTeam = new PlayerTeam(pTeam, out, in);
  if (pTeam.empty()) {
    return true;
  }
  // check enemy team members' status and put down member to out
  vector<Character *> eTeam = enemyTeam->getCharacters();
  for (auto enemy : eTeam) {
    if (enemy->getHealth() <= 0) {
      outEnemyTeam->addCharacter(enemy);
      eTeam.erase(std::remove(eTeam.begin(), eTeam.end(), enemy), eTeam.end());
    }
  }
  delete enemyTeam;
  enemyTeam = new EnemyTeam(eTeam, out);
  if (eTeam.empty()) {
    return true;
  }
  return false;
}

bool findSameName(Character * it, Character * character) {
  if (it->getName() == character->getName()) {
    return true;
  }
  return false;
}


void Combat::resetCombat() {
  // add all down player member back to team
  vector<Character *> newPlayerTeam = playerTeam->getCharacters();
  vector<Character *> originalPlayerTeamCharaters =
      OriginalPlayerTeam->getCharacters();
  for (auto outPlayer : outPlayerTeam->getCharacters()) { //push outplayer back to original team and reset health
    auto iter = originalPlayerTeamCharaters.begin();
    while (iter!= originalPlayerTeamCharaters.end()) {
      if ((*iter)->getName() == outPlayer->getName()) {
        break;
      }
      iter++;
    }
    outPlayer->setHealth((*iter)->getHealth());
    outPlayer->setMovable(true);
    newPlayerTeam.push_back(outPlayer);
  }
  delete playerTeam;
  playerTeam = new PlayerTeam(newPlayerTeam, out ,in);
  vector<Character *> cPNEWTeam{}, cENEWTeam{};
  delete outPlayerTeam;
  cPNEWTeam.clear();
  outPlayerTeam = new PlayerTeam(cPNEWTeam, out, in);

  // enemy team reset part
  vector<Character *> newEnemyTeam = enemyTeam->getCharacters();
  vector<Character *> originalEnemyTeamCharaters =
      OriginalEnemyTeam->getCharacters();
  for (auto outEnemy : outEnemyTeam->getCharacters()) { //push outEnemy back to original team and reset health
    auto iter = originalEnemyTeamCharaters.begin();
    while (iter!= originalEnemyTeamCharaters.end()) {
      if ((*iter)->getName() == outEnemy->getName()) {
        break;
      }
      iter++;
    }
    outEnemy->setHealth((*iter)->getHealth());
    outEnemy->setMovable(true);
    newEnemyTeam.push_back(outEnemy);
  }
  delete enemyTeam;
  enemyTeam = new EnemyTeam(newEnemyTeam, out);
  delete outEnemyTeam;
  cENEWTeam.clear();
  outEnemyTeam = new EnemyTeam(cENEWTeam, out);


  turns = 0;
}

bool Combat::chooseRestart() {
  out << "\nCombat Over..." << endl;
  out << "Please choose an option: " << endl;
  out << "1- Escape and Pretend You've Won." << endl;
  out << "2- Restart The Battle." << endl;
  string input;
  getline(in, input);
  if (input == "1") {
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

void Combat::showAllCharactersStatus() {
  for (auto player : playerTeam->getCharacters()) {
    player->getStatus(out);
  }
  for (auto enemy : enemyTeam->getCharacters()) {
    enemy->getStatus(out);
  }
}

void Combat::startBattle() {
  out << "\nThe Battle Has Begun!" << endl;
  bool BattleEnd = checkBattleEnd();
  while (!BattleEnd) {
    // players' turn
    turns++;
    int turn = showCurrentTurn();
    showAllCharactersStatus();
    for (auto player : playerTeam->getCharacters()) {
      if (player->checkMovable() &&
          player->getHealth() >
              0) { // only character that is movable and not dead can attack
        Character *target =
            playerTeam->chooseTarget(enemyTeam->getCharacters());
        player->listSkills(out);
        player->useSkillOn(player->selectSkill(in), target);
      }
      player->setMovable(true);
    }
    // enemy's turn
    for (auto enemy : enemyTeam->getCharacters()) {
      if (enemy->checkMovable() &&
          enemy->getHealth() >
              0) { // only character that is movable and not dead can attack
        Character *target =
            enemyTeam->chooseTarget(playerTeam->getCharacters());
        enemy->useSkillOn(enemy->selectSkill(in), target);
      }
      enemy->setMovable(true);
    }
    out << "\nTurn " << turn << " is over." << endl;
    BattleEnd = checkBattleEnd();
  }
  if (playerTeam->getCharacters().empty()) {
    bool restart = chooseRestart();
    if (restart) { // restart battle and reset all characters to original status
      resetCombat();
      startBattle();
    }
  }
  out << "\nYou won the battle!" << endl;
  out << "The battle is now over." << endl <<endl;
}


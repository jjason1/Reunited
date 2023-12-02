#include "../lib/Characters/Samurai.hpp"
#include "../lib/Enemies/Bandit.hpp"
#include "../src/Combat.cpp"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>

TEST(testCombatClassSuite, testConstructor) {
  Player *tester1 = new Player("tester1");
  Player *tester2 = new Player("tester2");
  tester2->setHealth(100);
  vector<Character *> team{tester1, tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  Enemy *e1 = new Enemy("Aamir", 1);
  Enemy *e2 = new Enemy("Boyi", 1);
  vector<Character *> enemies{e1, e2};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);

  EXPECT_NO_THROW(new Combat(testPTeam, testETeam, cout, cin));
  Combat *c = new Combat(testPTeam, testETeam, cout, cin);
  vector<Character *> NewOriginalPlayerCharacters =
      c->getOriginalPlayerTeam()->getCharacters();
  auto iter = NewOriginalPlayerCharacters.begin();
  for (auto player : c->getPlayerTeam()->getCharacters()) {

    EXPECT_EQ(player->getName(), (*iter)->getName());
    EXPECT_EQ(player->getHealth(), (*iter)->getHealth());
    iter++;
  }

  vector<Character *> NewOriginalEnemyCharacters =
      c->getOriginalEnemyTeam()->getCharacters();
  auto iterEnemy = NewOriginalEnemyCharacters.begin();
  for (auto enemy : c->getEnemyTeam()->getCharacters()) {
    EXPECT_EQ(enemy->getName(), (*iterEnemy)->getName());
    EXPECT_EQ(enemy->getHealth(), (*iterEnemy)->getHealth());
    iterEnemy++;
  }
}

TEST(testCombatClassSuite, testShowTurns) {
  Player *tester1 = new Player("tester1");
  Player *tester2 = new Player("tester2");
  vector<Character *> team{tester1, tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  Enemy *e1 = new Enemy("Aamir", 1);
  Enemy *e2 = new Enemy("Boyi", 1);
  vector<Character *> enemies{e1, e2};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);
  Combat *c = new Combat(testPTeam, testETeam, cout, cin);

  EXPECT_EQ(c->showCurrentTurn(), 0); // because combat not start yet
}

TEST(testCombatClassSuite, testCombatEndWhileBothSideAreHealthy) {
  Samurai *tester1 = new Samurai("tester1");
  Samurai *tester2 = new Samurai("tester2");
  vector<Character *> team{tester1, tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  Bandit *e1 = new Bandit("Aamir", 1);
  Bandit *e2 = new Bandit("Boyi", 1);
  vector<Character *> enemies{e1, e2};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);
  Combat *c = new Combat(testPTeam, testETeam, cout, cin);

  EXPECT_FALSE(c->checkBattleEnd()); // no because everyone is healthy
  EXPECT_EQ(c->getEnemyTeam()->getCharacters(), enemies);
  EXPECT_EQ(c->getPlayerTeam()->getCharacters(), team);
  EXPECT_TRUE(c->getOutEnemyTeam()->getCharacters().empty());
  EXPECT_TRUE(c->getOutPlayerTeam()->getCharacters().empty());
}

TEST(testCombatClassSuite, testCombatEndWhileEnemySideHasBeenDefeated) {
  Samurai *tester1 = new Samurai("tester1");
  Samurai *tester2 = new Samurai("tester2");
  vector<Character *> team{tester1, tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  Bandit *e1 = new Bandit("Aamir", 1);
  Bandit *e2 = new Bandit("Boyi", 1);
  e1->setHealth(0);
  e2->setHealth(0);
  vector<Character *> enemies{e1, e2};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);
  Combat *c = new Combat(testPTeam, testETeam, cout, cin);

  EXPECT_TRUE(c->checkBattleEnd()); // yes because bandits are dead
  EXPECT_NE(c->getEnemyTeam()->getCharacters(), enemies);
  EXPECT_EQ(c->getPlayerTeam()->getCharacters(), team);
  EXPECT_FALSE(c->getOutEnemyTeam()->getCharacters().empty());
  EXPECT_EQ(c->getOutEnemyTeam()->getCharacters(), enemies);
  EXPECT_TRUE(c->getOutPlayerTeam()->getCharacters().empty());
}

TEST(testCombatClassSuite, testCombatEndWhilePlayerSideHasBeenDefeated) {
  Samurai *tester1 = new Samurai("tester1");
  Samurai *tester2 = new Samurai("tester2");
  tester1->setHealth(0);
  tester2->setHealth(0);
  vector<Character *> team{tester1, tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);

  Bandit *e1 = new Bandit("Aamir", 1);
  Bandit *e2 = new Bandit("Boyi", 1);
  vector<Character *> enemies{e1, e2};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);
  Combat *c = new Combat(testPTeam, testETeam, cout, cin);

  EXPECT_TRUE(c->checkBattleEnd()); // yes because bandits are dead
  EXPECT_EQ(c->getEnemyTeam()->getCharacters(), enemies);
  EXPECT_NE(c->getPlayerTeam()->getCharacters(), team);
  EXPECT_TRUE(c->getOutEnemyTeam()->getCharacters().empty());
  EXPECT_EQ(c->getOutPlayerTeam()->getCharacters(), team);
  EXPECT_FALSE(c->getOutPlayerTeam()->getCharacters().empty());
}

TEST(testCombatClassSuite, testChooseRestartWith1) {
  stringstream testout;
  stringstream testin;
  testin << "1" << endl;
  Samurai *tester1 = new Samurai("tester1");
  Samurai *tester2 = new Samurai("tester2");
  vector<Character *> team{tester1, tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);

  Bandit *e1 = new Bandit("Aamir", 1);
  Bandit *e2 = new Bandit("Boyi", 1);
  vector<Character *> enemies{e1, e2};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);
  Combat *c = new Combat(testPTeam, testETeam, testout, testin);

  stringstream confirmOut;
  confirmOut << "\nCombat Over..." << endl;
  confirmOut << "Please choose an option: " << endl;
  confirmOut << "1- Escape and Pretend You've Won." << endl;
  confirmOut << "2- Restart The Battle." << endl;

  EXPECT_FALSE(c->chooseRestart());
  EXPECT_EQ(testout.str(), confirmOut.str());
}

TEST(testCombatClassSuite, testResetCombatAfterPlayerSideHasBeenDefeated) {
  // initialize player team
  Samurai *tester1 = new Samurai("tester1");
  Samurai *tester2 = new Samurai("tester2");
  vector<Character *> team{tester1, tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  // initialize enemy team
  Bandit *e1 = new Bandit("Aamir", 1);
  Bandit *e2 = new Bandit("Boyi", 1);
  vector<Character *> enemies{e1, e2};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);

  // initialize confirm team to confirm player team has reset
  Samurai *confirmtester1 = new Samurai("tester1");
  Samurai *confirmtester2 = new Samurai("tester2");
  vector<Character *> confirmTeam{confirmtester1, confirmtester2};
  // emulate
  Combat *c = new Combat(testPTeam, testETeam, cout, cin);
  tester1->setHealth(0);
  tester2->setHealth(0);
  c->checkBattleEnd();
  c->resetCombat();

  EXPECT_FALSE(c->checkBattleEnd()); // no because everyone is healthy again

  auto iter = confirmTeam.begin();
  for (auto player :
       c->getPlayerTeam()->getCharacters()) { // check every player has restored
                                              // health back to origin

    EXPECT_EQ(player->getName(), (*iter)->getName());
    EXPECT_EQ(player->getHealth(), (*iter)->getHealth());
    iter++;
  }

  EXPECT_TRUE(c->getOutEnemyTeam()->getCharacters().empty());
  EXPECT_TRUE(c->getOutPlayerTeam()->getCharacters().empty());
}

TEST(testCombatClassSuite, testShowAllCharactersStatus) {

  stringstream testout;
  stringstream testin;
  stringstream out;
  // initialize player team
  Samurai *tester1 = new Samurai("tester1");
  vector<Character *> team{tester1};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  // initialize enemy team
  Bandit *e1 = new Bandit("Aamir", 1);
  vector<Character *> enemies{e1};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);
  Combat *c = new Combat(testPTeam, testETeam, testout, testin);

  c->showAllCharactersStatus();

  out << endl;
  out << "tester1's Status: " << endl;
  out << "--------------------------\n";
  out << "Level   = 1" << endl;
  out << "Health  = 100" << endl;
  out << "Defense = 100" << endl;
  out << "Attack  = 100" << endl;
  out << endl;
  out << endl;
  out << "Aamir's Status: " << endl;
  out << "--------------------------\n";
  out << "Level   = 1" << endl;
  out << "Health  = 150" << endl;
  out << "Defense = 80" << endl;
  out << "Attack  = 25" << endl;
  out << endl;

  EXPECT_EQ(testout.str(), out.str());
}

TEST(testCombatClassSuite, testCombatStartWin1V1) {
  stringstream testout;
  stringstream testin;
  stringstream out;

  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
                         // make sure bandit is not going to keep stunning the player

  //initialize player team
  Samurai *tester1 = new Samurai("tester1");

  

  vector<Character *> team{tester1};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, testin);
  // initialize enemy team
  Bandit *e1 = new Bandit("Aamir", 1);
  vector<Character *> enemies{e1};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);

  Combat *c = new Combat(testPTeam, testETeam, cout, testin);


  EXPECT_NO_THROW(c->startBattle());
}

TEST(testCombatClassSuite, testCombatStartWin2V3) {
  stringstream testout;
  stringstream testin;
  stringstream out;

  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
                         // make sure bandit is not going to keep stunning the player

  //initialize player team
  Samurai *tester1 = new Samurai("tester1");
  Samurai *tester2 = new Samurai("tester2");
  Samurai *tester3 = new Samurai("tester3");

  

  vector<Character *> team{tester1,tester2,tester3};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, testin);
  // initialize enemy team
  Bandit *e1 = new Bandit("Aamir", 1);
  Bandit *e2 = new Bandit("Boyi", 1);
  Bandit *e3 = new Bandit("Jason", 1);
  vector<Character *> enemies{e1,e2,e3};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);

  Combat *c = new Combat(testPTeam, testETeam, cout, testin);


  EXPECT_NO_THROW(c->startBattle());
}


TEST(testCombatClassSuite, testDestructor) {
  Player *tester1 = new Player("tester1");
  Player *tester2 = new Player("tester2");
  tester2->setHealth(100);
  vector<Character *> team{tester1, tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  Enemy *e1 = new Enemy("Aamir", 1);
  Enemy *e2 = new Enemy("Boyi", 1);
  vector<Character *> enemies{e1, e2};
  EnemyTeam *testETeam = new EnemyTeam(enemies, cout);

  Combat *c = new Combat(testPTeam, testETeam, cout, cin);

  EXPECT_NO_THROW(delete c);
}
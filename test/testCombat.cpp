#include "gtest/gtest.h"
#include <iostream>
#include "../src/Combat.cpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Enemies/Bandit.hpp"

TEST(testCombatClassSuite, testConstructor) {
  Player * tester1 = new Player("tester1");
  Player *tester2 = new Player("tester2");
  vector<Character *> team{tester1,tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  Enemy *e1=new Enemy("Aamir",1);
  Enemy *e2=new Enemy("Boyi",1);
  vector<Character *> enemies{e1,e2};
  EnemyTeam* testETeam = new EnemyTeam(enemies,cout);

  EXPECT_NO_THROW(new Combat(testPTeam, testETeam, cout, cin));
}

TEST(testCombatClassSuite, testShowTurns) {
  Player * tester1 = new Player("tester1");
  Player *tester2 = new Player("tester2");
  vector<Character *> team{tester1,tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  Enemy *e1=new Enemy("Aamir",1);
  Enemy *e2=new Enemy("Boyi",1);
  vector<Character *> enemies{e1,e2};
  EnemyTeam* testETeam = new EnemyTeam(enemies,cout);
  Combat *c = new Combat(testPTeam, testETeam, cout, cin);

  EXPECT_EQ(c->showCurrentTurn(), 0); // because combat not start yet
}

TEST(testCombatClassSuite, testCombatEndWhileBothSideAreHealthy) {
  Samurai * tester1 = new Samurai("tester1");
  Samurai *tester2 = new Samurai("tester2");
  vector<Character *> team{tester1,tester2};
  PlayerTeam *testPTeam = new PlayerTeam(team, cout, cin);
  Bandit *e1=new Bandit("Aamir",1);
  Bandit *e2=new Bandit("Boyi",1);
  vector<Character *> enemies{e1,e2};
  EnemyTeam* testETeam = new EnemyTeam(enemies,cout);
  Combat *c = new Combat(testPTeam, testETeam, cout, cin);

  EXPECT_FALSE(c->checkBattleEnd()); // no because everyone is healthy
}


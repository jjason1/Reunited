#include "gtest/gtest.h"
#include "../src/Enemies/EnemyTeam.cpp"
#include "../lib/Enemies/Bandit.hpp"
#include "../lib/Enemies/Goblin.hpp"
#include <sstream>
#include <string>

TEST(EnemyTeamSuite, testNewEnemyTeam){
    //Arrange.
    Enemy *e1=new Enemy("Aamir",1);
    Enemy *e2=new Enemy("Boyi",1);
    vector<Character *> enemies{e1,e2};
    //Act + Assert.
    EXPECT_NO_THROW(new EnemyTeam(enemies,cout));
}

TEST(EnemyTeamSuite, testNewGoblinTeam){
    //Arrange.
    Goblin *g1=new Goblin("Jason",1);
    Goblin *g2=new Goblin("Ryan",1);
    vector<Character *> goblins{g1,g2};
    //Act + Assert.
    EXPECT_NO_THROW(new EnemyTeam(goblins,cout));
}

TEST(EnemyTeamSuite, testNewBanditTeam){
    //Arrange.
    Bandit *b1=new Bandit("Jason",1);
    Bandit *b2=new Bandit("Boyi",1);
    vector<Character *> bandits{b1,b2};
    //Act + Assert.
    EXPECT_NO_THROW(new EnemyTeam(bandits,cout));
}

TEST(EnemyTeamSuite, testGetSize){
    //Arrange.
    Bandit *b1=new Bandit("Aamir",1);
    Bandit *b2=new Bandit("Boyi",1);
    vector<Character *> bandits{b1,b2};
    EnemyTeam *enemies=new EnemyTeam(bandits,cout);
    //Act.
    int size=enemies->getSize();
    //Assert.
    EXPECT_EQ(size,2);
}

TEST(EnemyTeamSuite, testAddEnemy){
    //Arrange.
    Bandit *b1=new Bandit("Aamir",1);
    Bandit *b2=new Bandit("Boyi",1);
    vector<Character *> bandits{b1,b2};
    EnemyTeam *enemies=new EnemyTeam(bandits,cout);
    //Act.
    enemies->addCharacter(new Bandit("Ryan",1));
    //Assert.
    EXPECT_EQ(enemies->getSize(),3);
}

TEST(EnemyTeamSuite, testChooseTarget){
    //Arrange.
    stringstream ss;
    Bandit *b1=new Bandit("Aamir",1);
    Bandit *b2=new Bandit("Boyi",1);
    vector<Character *> bandits{b1,b2};
    EnemyTeam *enemies=new EnemyTeam(bandits,ss);
    Character *c1=new Character("Jason");
    Character *c2=new Character("Ryan");
    vector<Character *> targets{c1,c2};
    string target1="Jason is being targeted by the enemy team.\n";
    string target2="Ryan is being targeted by the enemy team.\n";
    //Act.
    Character *target=enemies->chooseTarget(targets);
    //Assert.
    if(target->getName()=="Jason") EXPECT_EQ(ss.str(),target1);
    else EXPECT_EQ(ss.str(),target2);
}

TEST(EnemyTeamSuite, testNoTargetFound){
    //Arrange.
    stringstream ss;
    Bandit *b1=new Bandit("Aamir",1);
    Bandit *b2=new Bandit("Boyi",1);
    vector<Character *> bandits{b1,b2};
    EnemyTeam *enemies=new EnemyTeam(bandits,ss);
    vector<Character *> targets; //Empty.
    string errMsg="No targets are available.\n";
    //Act.
    Character *target=enemies->chooseTarget(targets);
    //Assert.
    EXPECT_EQ(target,nullptr);
    EXPECT_EQ(ss.str(),errMsg);
}
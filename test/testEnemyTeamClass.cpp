#include "gtest/gtest.h"
#include "../src/Enemies/EnemyTeam.cpp"
#include "../lib/Enemies/Bandit.hpp"
#include "../lib/Enemies/Goblin.hpp"

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

//test getSize

//test addEnemy

//test addCharacter

//test chooseTarget


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
    EXPECT_NO_THROW(new EnemyTeam(enemies));
}

//test goblin team

//test bandit team

//test getSize

//test addEnemy

//test addCharacter

//test chooseTarget


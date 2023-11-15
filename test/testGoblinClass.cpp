#include "gtest/gtest.h"
#include "../src/Enemies/Goblin.cpp"

TEST(GoblinClassSuite, testNewGoblin){
    int level=1;
    string name="Aamir";
    EXPECT_NO_THROW(new Goblin(name, level));
}

TEST(GoblinClassSuite, testNoNameGoblin){
    int level=1;
    string name="";
    EXPECT_DEATH(new Goblin(name, level), "Your name must not be empty!");
}

TEST(GoblinClassSuite, testInvalidLevelGoblin){
    int level=-1;
    string name="Ryan";
    EXPECT_DEATH(new Goblin(name, level), "Your level must not be less than 0!");
}
/*
TEST(GoblinClassSuite, testNormalAttack){
    //Arrange.
    Goblin *g=new Goblin("Jason",1);
    Character *c=new Character("Boyi");
    c->setHealth(100); //Setting the character's hp.
    //Act.
    g->normalAttack(c);
    //Assert.
    EXPECT_EQ(c->getHealth(),70);
}
*/
TEST(GoblinClassSuite, testLifeSwipe){
    //Arrange.
    Goblin *g=new Goblin("Ryan",1);
    Character *c=new Character("Aamir");
    c->setHealth(100); //Setting the character's hp.
    //Act.
    g->lifeSwipe(c);   //Steals 10 hp from the character.
    //Assert.
    EXPECT_EQ(c->getHealth(),90); //Character's hp decreases by 10.
    EXPECT_EQ(g->getHealth(),210); //Goblin's hp increases by 10.
}

#include "gtest/gtest.h"
#include "../src/Enemies/Bandit.cpp"
#include <sstream>

TEST(BanditClassSuite, testNewBandit){
    int level=1;
    string name="Aamir";
    EXPECT_NO_THROW(new Bandit(name, level));
}

TEST(BanditClassSuite, testNoNameBandit){
    int level=1;
    string name="";
    EXPECT_DEATH(new Bandit(name, level), "Your name must not be empty!");
}

TEST(BanditClassSuite, testInvalidLevelBandit){
    int level=-1;
    string name="Ryan";
    EXPECT_DEATH(new Bandit(name, level), "Your level must not be less than 0!");
}
/*
TEST(BanditClassSuite, testNormalAttack){
    //Arrange.
    Bandit *b=new Bandit("Aamir",1);
    Character *c=new Character("Ryan");
    c->setHealth(100); //Setting the character's hp.
    //Act.
    b->normalAttack(c);
    //Assert.
    EXPECT_EQ(c->getHealth(),75);
}
*/
TEST(BanditClassSuite, testStun){
    //Arrange.
    Bandit *b=new Bandit("Jason",1);
    Character *c=new Character("Boyi");
    //Act.
    b->stun(c);
    //Assert.
    EXPECT_TRUE(c->checkMovable() == false);
}
#include "gtest/gtest.h"
#include <ctime>
#include <cstdlib>
#include "../src/Enemies/Bandit.cpp"

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

TEST(BanditClassSuite, testDifferentLevel){
    //Arrange + Act.
    Bandit *b=new Bandit("Aamir",3);
    //Assert.
    EXPECT_EQ(b->getHealth(),160);
    EXPECT_EQ(b->getDefense(),90);
    EXPECT_EQ(b->getAttack(),35);
}

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

TEST(BanditClassSuite, testStun){
    //Arrange.
    Bandit *b=new Bandit("Jason",1);
    Character *c=new Character("Boyi");
    //Act.
    b->stun(c);
    //Assert.
    EXPECT_TRUE(c->checkMovable() == false);
}

TEST(BanditClassSuite, testSelectSkill){
    //Arrange.
    Bandit *b=new Bandit("Jason",1);
    //Act.
    int chosenSkill=b->selectSkill(cin);
    //Assert.
    EXPECT_TRUE((chosenSkill==1)||(chosenSkill==2));
}

TEST(BanditClassSuite, testUseSkillOn){
    //Arrange.
    Bandit *b=new Bandit("Boyi",1);
    Character *c=new Character("Aamir");
    c->setHealth(100);
    int chosenSkill=b->selectSkill(cin);
    //Act + Assert.
    EXPECT_NO_THROW(b->useSkillOn(chosenSkill,c));
}
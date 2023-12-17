#include "gtest/gtest.h"
#include <ctime>
#include <cstdlib>
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

TEST(GoblinClassSuite, testDifferentLevel){
    //Arrange + Act.
    Goblin *g=new Goblin("Aamir",3);
    //Assert.
    EXPECT_EQ(g->getHealth(),210);
    EXPECT_EQ(g->getDefense(),100);
    EXPECT_EQ(g->getAttack(),40);
}

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

TEST(GoblinClassSuite, testSelectSkill){
    //Arrange.
    Goblin *g=new Goblin("Jason",1);
    //Act.
    int chosenSkill=g->selectSkill(cin);
    //Assert.
    EXPECT_TRUE((chosenSkill==1)||(chosenSkill==2));
}

TEST(GoblinClassSuite, testUseSkillOn){
    //Arrange.
    Goblin *g=new Goblin("Jason",1);
    Character *c=new Character("Ryan");
    c->setHealth(100);
    int chosenSkill=g->selectSkill(cin);
    //Act + Assert.
    EXPECT_NO_THROW(g->useSkillOn(chosenSkill,c));
}


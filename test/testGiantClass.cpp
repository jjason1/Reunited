#include "gtest/gtest.h"
#include <ctime>
#include <cstdlib>
#include "../src/Enemies/Giant.cpp"

TEST(GiantClassSuite, testNewGiant){
    int level=1;
    string name="POP";
    EXPECT_NO_THROW(new Giant(name, level));
}

TEST(GiantClassSuite, testBaseStats){
    int level=1;
    string name="Boyi";
    Giant *g = new Giant(name, level);

    EXPECT_EQ(g->getHealth(),4000);
    EXPECT_EQ(g->getDefense(),1500);
    EXPECT_EQ(g->getAttack(),50);
}

TEST(GiantClassSuite, testNormalAttack){
    int level=1;
    string name="Boyi";
    Giant *g = new Giant(name, level);

    Character *p = new Character("Jason");
    p->setHealth(100);

    g->normalAttack(p);
    
    EXPECT_EQ(p->getHealth(),50);
}

TEST(GiantClassSuite, testRainOfHammers){
    int level=1;
    string name="Ryan";
    Giant *g = new Giant(name, level);

    Character *p1 = new Character("Jason");
    
    p1->setHealth(100);

    g->RainOfHammers(p1);
    
    EXPECT_EQ(p1->getHealth(),50);
}

TEST(GiantClassSuite, testHeavyBlow){
    int level=1;
    string name="Ryan";
    Giant *g = new Giant(name, level);

    Character *p1 = new Character("Jason");
    
    p1->setHealth(100);
    
    g->heavyBlow(p1);
    
    EXPECT_EQ(p1->getHealth(), 50);
    EXPECT_EQ(p1->checkMovable(), false);
}

TEST(GiantClassSuite, testSelectSkill){
    Giant *g=new Giant("Jason",1);
    
    int chosenSkill=g->selectSkill(cin);
    
    EXPECT_TRUE((chosenSkill==1)||(chosenSkill==2)||(chosenSkill==3));
}

TEST(GiantClassSuite, testUseSkillOn){
    Giant *g=new Giant("Jason",1);
    Character *p1 = new Character("Jason");
    
    p1->setHealth(100);

    int chosenSkill=g->selectSkill(cin);
    
    EXPECT_NO_THROW(g->useSkillOn(chosenSkill, p1));
}
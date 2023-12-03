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

    Player *p = new Player("Jason");
    p->setHealth(100);

    g->normalAttack(p);
    
    EXPECT_EQ(p->getHealth(),50);
}

TEST(GiantClassSuite, testRainOfHammers){
    int level=1;
    string name="Ryan";
    Giant *g = new Giant(name, level);

    Player *p1 = new Player("Jason");
    Player *p2 = new Player("Aamir");
    p1->setHealth(100);
    p2->setHealth(100);

    vector<Player*> team;
    team.push_back(p1);
    team.push_back(p2);

    g->RainOfHammers(team);
    
    EXPECT_EQ(p1->getHealth(),50);
    EXPECT_EQ(p2->getHealth(),50);
}

TEST(GiantClassSuite, testHeavyBlow){
    int level=1;
    string name="Ryan";
    Giant *g = new Giant(name, level);

    Player *p1 = new Player("Jason");
    
    p1->setHealth(100);
    

    vector<Player*> team;
    team.push_back(p1);
    
    g->heavyBlow(team);
    
    EXPECT_EQ(p1->getHealth(), 50);
    EXPECT_EQ(p1->checkMovable(), false);
}

TEST(GiantClassSuite, testSelectSkill){
    Giant *g=new Giant("Jason",1);
    
    int chosenSkill=g->selectSkill(cin);
    
    EXPECT_TRUE((chosenSkill==1)||(chosenSkill==2)||(chosenSkill==3)||(chosenSkill==4)||(chosenSkill==5));
}

TEST(GiantClassSuite, testUseSkillOn){
    Giant *g=new Giant("Jason",1);
    Player *p1 = new Player("Jason");
    Player *p2 = new Player("Aamir");
    p1->setHealth(100);
    p2->setHealth(100);

    vector<Player*> team;
    team.push_back(p1);
    team.push_back(p2);

    int chosenSkill=g->selectSkill(cin);
    
    EXPECT_NO_THROW(g->useSkillOn(chosenSkill, team));
}
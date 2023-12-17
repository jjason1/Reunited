#include "gtest/gtest.h"
#include "../src/Enemies/Golem.cpp"

TEST(GolemClassSuite, testNewGolem){
    int level = 1;
    string name="Boyi";
    EXPECT_NO_THROW(new Golem(name, level));
}

TEST(GolemClassSuite, testNoNameGolem){
    int level = 1;
    string name="";
    EXPECT_DEATH(new Golem(name, level), "Your name must not be empty!");
}

TEST(GolemClassSuite, testInvalidLevelGolem){
    int level = -1;
    string name="Aamir";
    EXPECT_DEATH(new Golem(name, level), "Your level must not be less than 0!");
}


TEST(GolemClassSuite, testNormalAttack){
    Golem *g = new Golem("Boyi" , 1);
    Character *c = new Character("Jason");
    c->setHealth(100);
    g->normalAttack(c);
    EXPECT_EQ(c->getHealth(), 50);
}

TEST(GolemClassSuite, testlazerBlaze){
    Golem *g = new Golem("Boyi" , 1);
    Character *c = new Character("Ryan");
    c->setHealth(300);
    g->lazerBlaze(c);
    EXPECT_EQ(c->getHealth(), 200);
}


TEST(GolemClassSuite, testShieldGen){
    Golem *g = new Golem("Boyi" , 1);
    g->shieldGen();
    EXPECT_EQ(g->getHealth(), 3500);
}

TEST(GolemClassSuite, testSelectSkill){
    Golem *g = new Golem("Ryan" , 1);
    int chosenSkill = g->selectSkill(cin);
    EXPECT_TRUE((chosenSkill==1)||(chosenSkill==2)||(chosenSkill==3)||(chosenSkill==4));
}

TEST(GolemClassSuite, testUseSkillOn){
    Golem *g = new Golem("Ryan" , 1);
    Character *c=new Character("Aamir");
    c->setHealth(100);

    int chosenSkill = g->selectSkill(cin);
    
    EXPECT_NO_THROW(g->useSkillOn(chosenSkill,c));
}
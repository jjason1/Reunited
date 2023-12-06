#include "gtest/gtest.h"
#include "../src/Characters/Warrior.cpp"
#include <sstream>

TEST(WarriorTestSuit, testNewWarrior){
    string name = "Boyi";
    EXPECT_NO_THROW(new Warrior(name));
}

TEST(WarriorTestSuit, testSetStats){
    Warrior *w = new Warrior("Boyi");
    EXPECT_EQ(w->getHealth(), 100);
    EXPECT_EQ(w->getAttack(), 100);
    EXPECT_EQ(w->getDefense(), 100);
}

TEST(WarriorTestSuit, testStatsIncrement){
    Warrior *w = new Warrior("Jason");
    w->levelUp();
    EXPECT_EQ(w->getHealth(), 110);
    EXPECT_EQ(w->getAttack(), 105);
    EXPECT_EQ(w->getDefense(), 110);
}

TEST(WarriorTestSuit, testStrike){
    Warrior *w = new Warrior("Aamir");
    Character *e = new Character("Boyi");
    e->setHealth(200);
    w->strike(e);

    EXPECT_EQ(e->getHealth(), 100);
}

TEST(WarriorTestSuit, testWarCry){
    Warrior *w = new Warrior("Ryan");
    w->warCry();
    
    EXPECT_EQ(w->getAttack(), 200);
}

TEST(WarriorTestSuit, testHeartOfAWarrior){
    Warrior *w = new Warrior("qq");
    w->heartOfAWarrior();
    
    EXPECT_EQ(w->getHealth(), 120);
}



TEST(WarriorTestSuit, testListSkills){
    string list = "Skills:\n"
    "--------------------------\n"
    "1: Strike\n"
    "2: Heavy Strike\n"
    "3: War Cry\n"
    "4: Storm Strike\n"
    "5: Heart of a Warrior\n"
    "\nSelect the skill you would like to use: \n";


    string name = "Ryan";
    Warrior *w = new Warrior(name);
    stringstream ss;
    w->listSkills(ss);
    EXPECT_EQ(ss.str(), list);
}

TEST(WarriorTestSuit, testSelectSkill){
    Warrior *w = new Warrior("Haha");
    string simulatedInput = "5\n";
    istringstream in(simulatedInput);

    int chosenSkill = w->selectSkill(in);

    EXPECT_TRUE((chosenSkill == 5));
}



TEST(WarriorTestSuit, testUseSkillOn){
    Warrior *w = new Warrior("XXX");
    Character *e = new Character("DDD");

    string simulatedInput = "4\n";
    istringstream in(simulatedInput);

    e->setHealth(250);
    int chosenSkill = w->selectSkill(in);

    EXPECT_NO_THROW(w->useSkillOn(chosenSkill, e));
    EXPECT_EQ(e->getHealth(), 50);
}

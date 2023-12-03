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
    Enemy *e = new Enemy("Boyi", 1);
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

TEST(WarriorTestSuit, testletTamBleed){
    Warrior *w = new Warrior("WoW");
    Enemy *e = new Enemy("Boyi", 1);
    e->setHealth(250);
    
    w->letTamBleed(e);
    
    EXPECT_EQ(e->getHealth(), 220);
}

TEST(WarriorTestSuit, testListSkills){
    string list = "Skills:\n"
    "--------------------------\n"
    "1: Strike\n"
    "2: Heavy Strike\n"
    "3: War Cry\n"
    "4: Storm Strike\n"
    "5: Heart of a Warrior\n"
    "6: Unstoppable Fury\n"
    "7: Let Them Bleed\n"
    "8: Doom of the Enemy\n"
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

TEST(WarriorTestSuit, testInvalidSkill){
    Warrior *w = new Warrior("Lol");
    string simulatedInput = "x\n1\n";
    istringstream in(simulatedInput);

    stringstream buffer;
    streambuf* prevCoutBuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    w->selectSkill(in);

    cout.rdbuf(prevCoutBuf);

    string error = "Select a skill number: Invalid input, please enter a valid skill number.\nSelect a skill number: ";

    EXPECT_EQ(error, buffer.str());
}

TEST(WarriorTestSuit, testUseSkillOn){
    Warrior *w = new Warrior("XXX");
    Enemy *e = new Enemy("DDD", 2);

    string simulatedInput = "4\n";
    istringstream in(simulatedInput);

    e->setHealth(250);
    int chosenSkill = w->selectSkill(in);

    EXPECT_NO_THROW(w->useSkillOn(chosenSkill, e));
    EXPECT_EQ(e->getHealth(), 50);
}

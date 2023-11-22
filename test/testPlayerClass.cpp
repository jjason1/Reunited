
#include "gtest/gtest.h"
#include "../src/Characters/Player.cpp"
#include <iostream>
#include <ostream>

TEST(TestPlayerClassSuite, TestNewPlayer){
    int level=1;
    string name = "Boyi";
    EXPECT_NO_THROW(new Player(name, level));
}

TEST(TestPlayerClassSuite, TestNoNamePlayer){
    int level=1;
    string name = "";
    EXPECT_DEATH(new Player(name, level), "Your name must not be empty!");
}

TEST(TestPlayerClassSuite, TestInvalidLevelPlayer){
    string name = "Boyi";
    int level=-1;
    EXPECT_DEATH(new Player(name, level), "Your level must not be less than 0!");
}

/* Need a mock test
TEST(TestPlayerClassSuite, TestPrintSkiils){
    Player *P = new Player("Aamir", 1);
    P->skills = {'Fireball', 'Icestorm'};
    P->listSkills;
    EXPECT_EQ();
}
*/
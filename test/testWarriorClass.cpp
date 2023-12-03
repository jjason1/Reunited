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
    Warrior *w = new Warrior("Boyi");
    EXPECT_EQ(w->getHealth(), 100);
    EXPECT_EQ(w->getAttack(), 100);
    EXPECT_EQ(w->getDefense(), 100);
}
#include "gtest/gtest.h"
#include "../src/Enemies/Goblin.cpp"
#include <sstream>

TEST(GoblinClassSuite, testNewGoblin){
    int level=1;
    string name="Aamir";
    EXPECT_NO_THROW(new Goblin(name, level));
}
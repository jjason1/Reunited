#include "gtest/gtest.h"
#include "../src/Enemies/Golem.cpp"

TEST(GolemClassSuite, testNewGolem){
    int level = 1;
    string name="Boyi";
    EXPECT_NO_THROW(new Golem(name, level));
}
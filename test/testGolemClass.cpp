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
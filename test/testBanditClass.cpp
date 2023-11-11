#include "gtest/gtest.h"
#include "../src/Enemies/Bandit.cpp"
#include <sstream>

TEST(BanditClassSuite, testNewBandit){
    int level=1;
    string name="Aamir";
    EXPECT_NO_THROW(new Bandit(name, level));
}

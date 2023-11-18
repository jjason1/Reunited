#include "gtest/gtest.h"
#include "../src/Characters/Player.cpp"
#include <sstream>

TEST(PlayerClassSuite, testNewPlayer){
    string name = "Jason";
    EXPECT_NO_THROW(new Player(name));
}


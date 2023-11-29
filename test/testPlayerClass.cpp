
#include "gtest/gtest.h"
#include "../src/Characters/Player.cpp"
#include <iostream>
#include <ostream>
#include <fstream>

TEST(TestPlayerClassSuite, TestNewPlayer){
    int level=1;
    string name = "Boyi";
    EXPECT_NO_THROW(new Player(name));
}

TEST(TestPlayerClassSuite, TestNoNamePlayer){
    int level=1;
    string name = "";
    EXPECT_DEATH(new Player(name), "Your name must not be empty!");
}

TEST(TestPlayerClassSuite, TestLevelUp){
    Player *P = new Player("Aamir");
    P->levelUp();
    EXPECT_EQ(P->getLevel(), 2);
}


TEST(TestPlayerClassSuite, testGetStatus){
    string name="Jason";
    string status="\nJason's Status: \n"
                  "--------------------------\n"
                  "Level   = 1\n"
                  "Health  = 0\n"
                  "Defense = 0\n"
                  "Attack  = 0\n\n";
    Player *P = new Player(name);
    stringstream ss;
    P->getStatus(ss);
    EXPECT_EQ(ss.str(), status); 
}

TEST(TestPlayerClassSuite, testSetAtkDstrbtn){
    Player *P = new Player("Ryan");
    int AtkDstrbtn = 2;
    P->setAtkDstrbtn(AtkDstrbtn);
    EXPECT_EQ(P->getAtkDstrbtn(), 2);
}
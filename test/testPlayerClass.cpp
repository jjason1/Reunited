
#include "gtest/gtest.h"
#include "../src/Characters/Player.cpp"
#include <iostream>
#include <ostream>
#include <fstream>

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

/*
TEST(TestPlayerClassSuite, TestLevelUp){
    Player *P = new Player("Aamir");
    P->levelUp();
    EXPECT_EQ(P->getlevel(), 2);
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

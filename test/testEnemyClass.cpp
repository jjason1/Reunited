#include "gtest/gtest.h"
#include "../src/Enemies/Enemy.cpp"

TEST(EnemyClassSuite, testNewEnemy){
    int level=1;
    string name="Aamir";
    EXPECT_NO_THROW(new Enemy(name, level));
}

TEST(EnemyClassSuite, testGetName){
    int level=1;
    string name="Jason";
    Enemy *e=new Enemy(name, level);
    EXPECT_EQ(e->getName(), "Jason");
}

TEST(EnemyClassSuite, testGetStatus){
    //Arrange.
    int level=1;
    string name="Boyi";
    string status="\nBoyi's Status: \n"
                  "--------------------------\n"
                  "Level   = 1\n"
                  "Health  = 0\n"
                  "Defense = 0\n"
                  "Attack  = 0\n\n";
    Enemy *e=new Enemy(name, level);
    stringstream ss;
    //Act.
    e->getStatus(ss);
    //Assert. (Checking to see if the statuses match.)
    EXPECT_EQ(ss.str(), status); 
}

TEST(EnemyClassSuite, testNoName){
    int level=1;
    string name="";
    EXPECT_DEATH(new Enemy(name, level), "Your name must not be empty!");
}

TEST(EnemyClassSuite, testInvalidLevel){
    int level=-1;
    string name="Ryan";
    EXPECT_DEATH(new Enemy(name, level), "Your level must not be less than 0!");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include "gtest/gtest.h"
#include "../src/Enemies/Enemy.cpp"
#include <sstream>

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

TEST(EnemyClassSuite, testCheckMovable){
    int level=1;
    string name="Aamir";
    Enemy *e=new Enemy(name, level);
    bool status=e->checkMovable();
    EXPECT_TRUE(status==true);
}

TEST(EnemyClassSuite, testGetHealth){
    int level=1;
    string name="Jason";
    Enemy *e=new Enemy(name, level);
    int hp=e->getHealth();
    EXPECT_EQ(hp,0);
}

TEST(EnemyClassSuite, testGetDefense){
    int level=1;
    string name="Boyi";
    Enemy *e=new Enemy(name, level);
    int def=e->getDefense();
    EXPECT_EQ(def,0);
}

TEST(EnemyClassSuite, testGetAttack){
    int level=1;
    string name="Ryan";
    Enemy *e=new Enemy(name, level);
    int atk=e->getAttack();
    EXPECT_EQ(atk,0);
}

TEST(EnemyClassSuite, testSetHealth){
    int level=1;
    string name="Aamir";
    Enemy *e=new Enemy(name, level);
    e->setHealth(10);
    EXPECT_EQ(e->getHealth(),10);
}

TEST(EnemyClassSuite, testSetDefense){
    int level=1;
    string name="Jason";
    Enemy *e=new Enemy(name, level);
    e->setDefense(10);
    EXPECT_EQ(e->getDefense(),10);
}

TEST(EnemyClassSuite, testSetAttack){
    int level=1;
    string name="Boyi";
    Enemy *e=new Enemy(name, level);
    e->setAttack(10);
    EXPECT_EQ(e->getAttack(),10);
}

TEST(EnemyClassSuite, testTakeDamage){
    //Arrange.
    int level=1;
    string name="Ryan";
    Enemy *e=new Enemy(name, level);
    e->setHealth(100);
    //Act.
    e->takeDamage(10);
    //Assert.
    EXPECT_EQ(e->getHealth(),90);
}

TEST(EnemyClassSuite, testNormalAttack){
    //Arrange.
    Enemy *e=new Enemy("Aamir", 1);
    Character *c=new Character("Ryan");
    e->setAttack(25);  //Setting the enemy's atk.
    c->setHealth(100); //Setting the character's hp.
    //Act.
    e->normalAttack(c);
    //Assert.
    EXPECT_EQ(c->getHealth(),75);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

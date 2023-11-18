#include "gtest/gtest.h"
#include "../src/Characters/Character.cpp"
#include <sstream>

TEST(CharacterClassSuite, testNewCharacter)
{
    string name = "Jason";
    EXPECT_NO_THROW(new Character(name));
}

TEST(CharacterClassSuite, testGetName)
{
    string name = "Jason";
    Character *c = new Character(name);
    EXPECT_EQ(c->getName(), "Jason");
}

TEST(CharacterClassSuite, testGetStatus)
{
    // Arrange.
    string name = "Boyi";
    string status = "\nBoyi's Status: \n"
                    "--------------------------\n"
                    "Level   = 1\n"
                    "Health  = 0\n"
                    "Defense = 0\n"
                    "Attack  = 0\n\n";
    Character *c = new Character(name);
    stringstream ss;
    // Act.
    c->getStatus(ss);
    // Assert. (Checking to see if the statuses match.)
    EXPECT_EQ(ss.str(), status);
}

TEST(CharacterClassSuite, testNoName)
{
    string name = "";
    EXPECT_DEATH(new Character(name), "Your name must not be empty!");
}

TEST(CharacterClassSuite, testCheckMovable)
{
    int level = 1;
    string name = "Aamir";
    Character *c = new Character(name);
    bool status = c->checkMovable();
    EXPECT_TRUE(status == true);
}

TEST(CharacterClassSuite, testGetHealth)
{
    string name = "Jason";
    Character *c = new Character(name);
    int hp = c->getHealth();
    EXPECT_EQ(hp, 0);
}

TEST(CharacterClassSuite, testGetDefense)
{
    string name = "Boyi";
    Character *c = new Character(name);
    int def = c->getDefense();
    EXPECT_EQ(def, 0);
}

TEST(CharacterClassSuite, testGetAttack)
{
    string name = "Ryan";
    Character *c = new Character(name);
    int atk = c->getAttack();
    EXPECT_EQ(atk, 0);
}

TEST(CharacterClassSuite, testSetHealth)
{
    string name = "Aamir";
    Character *c = new Character(name);
    c->setHealth(10);
    EXPECT_EQ(c->getHealth(), 10);
}

TEST(CharacterClassSuite, testSetDefense)
{
    string name = "Jason";
    Character *c = new Character(name);
    c->setDefense(10);
    EXPECT_EQ(c->getDefense(), 10);
}

TEST(CharacterClassSuite, testSetAttack)
{
    string name = "Boyi";
    Character *c = new Character(name);
    c->setAttack(10);
    EXPECT_EQ(c->getAttack(), 10);
}

TEST(CharacterClassSuite, testTakeDamage)
{
    // Arrange.
    string name = "Ryan";
    Character *c = new Character(name);
    c->setHealth(100);
    // Act.
    c->takeDamage(10);
    // Assert.
    EXPECT_EQ(c->getHealth(), 90);
}



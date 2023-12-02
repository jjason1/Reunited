#include "gtest/gtest.h"
#include "../src/Characters/Samurai.cpp"
#include <sstream>

TEST(SamuraiClassSuite, testNewSamurai)
{
    int level = 1;
    string name = "Aamir";
    EXPECT_NO_THROW(new Samurai(name));
}

TEST(SamuraiClassSuite, testNoNameSamurai)
{
    int level = 1;
    string name = "";
    EXPECT_DEATH(new Samurai(name), "Your name must not be empty!");
}

TEST(SamuraiClassSuite, testDirectStrike)
{
    // Arrange.
    Samurai *c = new Samurai("Jason");
    Enemy *e = new Enemy("John", 1);

    e->setHealth(200);
    // Act.
    c->directStrike(e);
    // Assert.
    EXPECT_EQ(e->getHealth(), 100);
}

TEST(SamuraiClassSuite, testSheathBlade)
{
    Samurai *c = new Samurai("Neal");
    Enemy *e = new Enemy("Bob", 1);

    e->setHealth(200);
    c->sheathBlade(e);

    EXPECT_EQ(e->getHealth(), 50);
}

TEST(SamuraiClassSuite, testWideRangeStrike)
{
    Samurai *s = new Samurai("Jason");
    Enemy *e = new Enemy("Neal", 1);

    e->setHealth(100);
    s->wideRangeStrike(e);

    EXPECT_EQ(e->getHealth(), 50);
}

TEST(SamuraiClassSuite, testShadowDegeneration)
{
    Samurai *s = new Samurai("Jason");
    Enemy *e = new Enemy("Neal", 1);

    e->setHealth(100);
    s->shadowDegeneration(e);

    EXPECT_EQ(e->getHealth(), 80);
}

TEST(SamuraiClassSuite, testSmokeBomb)
{

    bool status;

    Samurai *s = new Samurai("Jason");
    Enemy *e = new Enemy("John", 1);

    e->setHealth(100);
    s->smokeBomb(e);

    status = e->checkMovable();
    EXPECT_EQ(e->getHealth(), 50);
    EXPECT_TRUE(status == false);
}

TEST(SamuraiClassSuite, testListSkills)
{
    string name = "Jason";
    string status = "\nSkills\n"
                    "--------------------------\n"
                    "1. Direct strike\n"
                    "2. Sheath blade\n"
                    "3. Wide range strike\n"
                    "4. Shadow degeneration\n"
                    "5. Smoke bomb\n"
                    "\nSelect the skill you would like to use: \n";

    Samurai *s = new Samurai(name);
    stringstream ss;
    s->listSkills(ss);
    EXPECT_EQ(ss.str(), status);
}

TEST(SamuraiClassSuite, testSelectSkill)
{
    // Arrange.
    Samurai *s = new Samurai("Jason");
    // Act.
    string simulatedInput = "3\n"; // Change this to test different inputs
    istringstream in(simulatedInput);

    int chosenSkill = s->selectSkill(in);

    // Assert.
    EXPECT_TRUE((chosenSkill == 3));
}

TEST(SamuraiClassSuite, testUseSkillOn)
{
    // Arrange.
    Samurai *s = new Samurai("Jason");
    Enemy *e = new Enemy("Aamir", 1);
    e->setHealth(100);

    string simulatedInput = "3\n"; // Change this to test different inputs
    istringstream in(simulatedInput);
    
    int chosenSkill = s->selectSkill(in);
    // Act + Assert.
    EXPECT_NO_THROW(s->useSkillOn(chosenSkill, e));
    EXPECT_EQ(e->getHealth(), 50);
}

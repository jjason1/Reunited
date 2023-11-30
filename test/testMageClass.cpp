#include "gtest/gtest.h"
#include "../src/Characters/Mage.cpp"
#include <sstream>

TEST(MageClassSuite, testNewMage)
{
    int level = 1;
    string name = "Jason";
    EXPECT_NO_THROW(new Mage(name));
}

TEST(MageClassSuite, testNoNameMage)
{
    int level = 1;
    string name = "";
    EXPECT_DEATH(new Mage(name), "Your name must not be empty!");
}

TEST(MageClassSuite, testFireball)
{
    // Arrange.
    Mage *m = new Mage("Jason");
    Enemy *e = new Enemy("John", 1);

    e->setHealth(200);
    // Act.
    m->fireBall(e);
    // Assert.
    EXPECT_EQ(e->getHealth(), 100);
}

TEST(MageClassSuite, testSkillBoostFireball)
{
    // Arrange.
    Mage *m = new Mage("Jason");
    Enemy *e = new Enemy("John", 1);

    e->setHealth(300);
    // Act.
    m->skillBoost();
    m->fireBall(e);
    // Assert.
    EXPECT_EQ(e->getHealth(), 100);
}

TEST(MageClassSuite, testIceStorm)
{
    Mage *m = new Mage("Jason");
    Enemy *e = new Enemy("Neal", 1);

    e->setHealth(100);
    m->iceStorm(e);

    EXPECT_EQ(e->getHealth(), 50);
}

TEST(MageClassSuite, testSkillBoostIceStorm)
{
    Mage *m = new Mage("Jason");
    Enemy *e = new Enemy("Neal", 1);

    e->setHealth(200);
    m->skillBoost();
    m->iceStorm(e);

    EXPECT_EQ(e->getHealth(), 50);
}

TEST(MageClassSuite, testThunderBlast)
{
    Mage *m = new Mage("Jason");
    Enemy *e = new Enemy("Neal", 1);

    e->setHealth(200);
    m->thunderBlast(e);

    EXPECT_EQ(e->getHealth(), 50);
}
TEST(MageClassSuite, testSkillBoostThunderBlast)
{
    Mage *m = new Mage("Jason");
    Enemy *e = new Enemy("Neal", 1);

    e->setHealth(300);
    m->skillBoost();
    m->thunderBlast(e);

    EXPECT_EQ(e->getHealth(), 50);
}

TEST(MageClassSuite, testHealing)
{
    Mage *m = new Mage("Jason");

    m->healing();

    EXPECT_EQ(m->getHealth(), 150);
}

TEST(MageClassSuite, testSkillBoostHealing)
{
    Mage *m = new Mage("Jason");

    m->skillBoost();
    m->healing();

    EXPECT_EQ(m->getHealth(), 200);
}

TEST(MageClassSuite, testSkillBoost)
{
    Mage *m = new Mage("Jason");
    Enemy *e = new Enemy("Neal", 1);

    e->setHealth(300);
    m->skillBoost();
    m->thunderBlast(e);

    EXPECT_EQ(e->getHealth(), 50);
}

TEST(MageClassSuite, testListSkills)
{
    string name = "Jason";
    string status = "\nSkills\n"
                    "--------------------------\n"
                    "1. Direct strike\n"
                    "2. Sheath blade\n"
                    "3. Wide range strike\n"
                    "4. Shadow degeneration\n"
                    "5. Smoke bomb\n"
                    "Select the skill you would like to use: \n";

    Mage *m = new Mage(name);
    stringstream ss;
    m->listSkills(ss);
    EXPECT_EQ(ss.str(), status);
}

TEST(MageClassSuite, testSelectSkill)
{
    // Arrange.
    Mage *m = new Mage("Jason");
    // Act.
    int chosenSkill = m->selectSkill();
    // Assert.
    EXPECT_TRUE((chosenSkill == 1) || (chosenSkill == 2) || (chosenSkill == 3) || (chosenSkill == 4) || (chosenSkill == 5));
}

TEST(MageClassSuite, testUseSkillOn){
    //Arrange.
    Mage *m=new Mage("Jason");
    Enemy *e=new Enemy("Aamir", 1);
    e->setHealth(200);
    int chosenSkill=m->selectSkill();
    //Act + Assert.
    EXPECT_NO_THROW(m->useSkillOn(chosenSkill,e));
}
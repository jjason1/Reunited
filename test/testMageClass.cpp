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
    // Arrange.
    Mage *m = new Mage("Jason"); // Assuming Mage constructor does not require parameters
    stringstream output;

    // Act.
    m->listSkills(output);
    string outputStr = output.str();

    // Assert.
    string expectedOutput = "\nSkills\n--------------------------\n1. Fireball\n2. Heal\n3. Ice storm\n4. Thunder blast\n5. Skill boost\nSelect the skill you would like use: \n";
    EXPECT_EQ(outputStr, expectedOutput);
}

TEST(MageClassSuite, testSelectSkill)
{
    // Arrange.
    Mage *m = new Mage("Jason");
    // Act.

    string simulatedInput = "3\n"; // Change this to test different inputs
    istringstream in(simulatedInput);

    int chosenSkill = m->selectSkill(in);
    // Assert.
    EXPECT_TRUE(chosenSkill == 3);
}

TEST(MageClassSuite, testUseSkillOn)
{
    // Arrange.
    Mage *m = new Mage("Jason");
    Enemy *e = new Enemy("Aamir", 1);
    e->setHealth(100);

    string simulatedInput = "3\n"; // Change this to test different inputs
    istringstream in(simulatedInput);
    int chosenSkill = m->selectSkill(in);
    // Act + Assert.
    EXPECT_NO_THROW(m->useSkillOn(chosenSkill, e));
    EXPECT_EQ(e->getHealth(), 50);
}

TEST(MageClassSuite, testLevelUp){
    Mage *m = new Mage("Jason");
    m->levelUp();

    EXPECT_EQ(m->getHealth(), 110);
    EXPECT_EQ(m->getAttack(), 110);
    EXPECT_EQ(m->getDefense(), 105);
    EXPECT_EQ(m->getLevel(), 2);
}
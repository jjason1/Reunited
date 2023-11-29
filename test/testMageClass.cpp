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

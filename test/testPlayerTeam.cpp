#include "gtest/gtest.h"
#include <sstream>
#include <vector>
#include "../src/Characters/PlayerTeam.cpp"
#include "../src/Characters/CharacterTeam.cpp"
#include "../lib/Enemies/Enemy.hpp"

TEST(TestPlayerTeamSuite, testConstructer) {
  Player * tester1 = new Player("tester1");
  Player *tester2 = new Player("tester2");
  vector<Character *> team{tester1,tester2};
  EXPECT_NO_THROW(PlayerTeam* testTeam = new PlayerTeam(team, cout, cin));
}

TEST(TestPlayerTeamSuite, testGetSize){
    //Arrange.
    Player * tester1 = new Player("tester1");
    Player *tester2 = new Player("tester2");
    vector<Character *> team{tester1,tester2};
    PlayerTeam* testTeam = new PlayerTeam(team, cout, cin);
    //Act.
    int size=testTeam->getSize();
    //Assert.
    EXPECT_EQ(size,2);
}

TEST(TestPlayerTeamSuite, testAddPlayer){
    //Arrange.
    stringstream ss;
    string expOutput="Aamir has joined the team!\n";
    Player * tester1 = new Player("tester1");
    Player *tester2 = new Player("tester2");
    vector<Character *> team{tester1,tester2};
    PlayerTeam* testTeam = new PlayerTeam(team, ss, cin);
    //Act.
    testTeam->addPlayer(new Player("Aamir"));
    //Assert.
    EXPECT_EQ(ss.str(),expOutput);
    EXPECT_EQ(testTeam->getSize(),3);
}

TEST(TestPlayerTeamSuite, testChooseTargetWithCorrectTyping){
    //Arrange.
    stringstream outss;
    stringstream inss;
    stringstream expectedss;

    //set up playerTeam
    Player * tester1 = new Player("tester1");
    Player *tester2 = new Player("tester2");
    vector<Character *> team{tester1,tester2};
    PlayerTeam *testTeam = new PlayerTeam(team, outss, inss);

    //set up enemyTeam
    Enemy *enemyTester1 = new Enemy("enemyTest1", 1);
    Enemy *enemyTester2 = new Enemy("enemyTest2", 1);
    vector<Character *> enemyTeam{enemyTester1, enemyTester2};

    //set up expected output
    expectedss << "Enemy list:" << endl;
    expectedss << "1- enemyTest1 Hp: 0" << endl;
    expectedss << "2- enemyTest2 Hp: 0" << endl;
    expectedss << "Please choose a target:" << endl;
    inss << "1" << endl;
    //Act.
    
    Character * answer = testTeam->chooseTarget(enemyTeam);
    //Assert.
    EXPECT_EQ(outss.str(),expectedss.str());
    EXPECT_EQ(answer, enemyTester1);
}


TEST(TestPlayerTeamSuite, testChooseTargetWithWrongTyping){
    //Arrange.
    stringstream outss;
    stringstream inss;
    stringstream expectedss;

    //set up playerTeam
    Player * tester1 = new Player("tester1");
    Player *tester2 = new Player("tester2");
    vector<Character *> team{tester1,tester2};
    PlayerTeam *testTeam = new PlayerTeam(team, outss, inss);

    //set up enemyTeam
    Enemy *enemyTester1 = new Enemy("enemyTest1", 1);
    Enemy *enemyTester2 = new Enemy("enemyTest2", 1);
    vector<Character *> enemyTeam{enemyTester1, enemyTester2};

    //set up expected output
    expectedss << "Enemy list:" << endl;
    expectedss << "1- enemyTest1 Hp: 0" << endl;
    expectedss << "2- enemyTest2 Hp: 0" << endl;
    expectedss << "Please choose a target:" << endl;
    expectedss << "Please choose a target again:" << endl;
    inss << "5" << endl;
    inss << "2" << endl;
    //Act.
    Character * answer = testTeam->chooseTarget(enemyTeam);
    //Assert.
    EXPECT_EQ(outss.str(),expectedss.str());
    EXPECT_EQ(answer, enemyTester2);
}

TEST(TestPlayerTeamSuite, testGetCharacters){
    //Arrange.
    stringstream outss;
    stringstream inss;
    stringstream expectedss;
    Player * tester1 = new Player("tester1");
    Player *tester2 = new Player("tester2");
    vector<Character *> team{tester1,tester2};
    PlayerTeam *testTeam = new PlayerTeam(team, outss, inss);
    //Act.
    vector<Character *> members=testTeam->getCharacters();
    //Assert.
    EXPECT_EQ(members.size(),2);
    EXPECT_EQ(members[0]->getName(),"tester1");
    EXPECT_EQ(members[1]->getName(),"tester2");
}
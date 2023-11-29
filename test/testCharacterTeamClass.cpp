#include "gtest/gtest.h"
#include "../src/Characters/CharacterTeam.cpp"
#include <sstream>

TEST(CharacterTeamSuite, testNewCharacterTeam){
    //Arrange.
    Character *c1=new Character("Aamir");
    Character *c2=new Character("Ryan");
    vector<Character *> team{c1,c2};
    //Act + Assert.
    EXPECT_NO_THROW(new CharacterTeam(team,cout));
}

TEST(CharacterTeamSuite, testGetSize){
    //Arrange.
    Character *c1=new Character("Boyi");
    Character *c2=new Character("Jason");
    vector<Character *> team{c1,c2};
    CharacterTeam *characters=new CharacterTeam(team,cout);
    //Act.
    int size=characters->getSize();
    //Assert.
    EXPECT_EQ(size,2);
}

TEST(CharacterTeamSuite, testAddCharacter){
    //Arrange.
    stringstream ss;
    string expOutput="Aamir has joined the team!\n";
    Character *c1=new Character("Boyi");
    Character *c2=new Character("Jason");
    vector<Character *> team{c1,c2};
    CharacterTeam *characters=new CharacterTeam(team,ss);
    //Act.
    characters->addCharacter(new Character("Aamir"));
    //Assert.
    EXPECT_EQ(ss.str(),expOutput);
    EXPECT_EQ(characters->getSize(),3);
}

TEST(CharacterTeamSuite, testGetCharacters){
    //Arrange.
    Character *c1=new Character("Aamir");
    Character *c2=new Character("Jason");
    vector<Character *> team{c1,c2};
    CharacterTeam *characters=new CharacterTeam(team,cout);
    //Act.
    vector<Character *> members=characters->getCharacters();
    //Assert.
    EXPECT_EQ(members.size(),2);
    EXPECT_EQ(members[0]->getName(),"Aamir");
    EXPECT_EQ(members[1]->getName(),"Jason");
}

#include "gtest/gtest.h"
#include "../src/Characters/CharacterTeam.cpp"

TEST(CharacterTeamSuite, testNewCharacterTeam){
    //Arrange.
    Character *c1=new Character("Aamir");
    Character *c2=new Character("Ryan");
    vector<Character *> team{c1,c2};
    //Act + Assert.
    EXPECT_NO_THROW(new CharacterTeam(team));
}

TEST(CharacterTeamSuite, testGetSize){
    //Arrange.
    Character *c1=new Character("Boyi");
    Character *c2=new Character("Jason");
    vector<Character *> team{c1,c2};
    CharacterTeam *characters=new CharacterTeam(team);
    //Act.
    int size=characters->getSize();
    //Assert.
    EXPECT_EQ(size,2);
}

TEST(CharacterTeamSuite, testAddCharacter){
    //Arrange.
    Character *c1=new Character("Boyi");
    Character *c2=new Character("Jason");
    vector<Character *> team{c1,c2};
    CharacterTeam *characters=new CharacterTeam(team);
    //Act.
    characters->addCharacter(new Character("Aamir"));
    //Assert.
    EXPECT_EQ(characters->getSize(),3);
}
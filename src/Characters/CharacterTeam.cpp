#include "../lib/Characters/CharacterTeam.hpp"

CharacterTeam::CharacterTeam(vector<Character *> team){
    this->characters=team;
}

int CharacterTeam::getSize(){
    return this->characters.size();
}

void CharacterTeam::addCharacter(Character *c){
    this->characters.push_back(c);
    cout<<c->getName()<<" has joined the team!"<<endl;
}
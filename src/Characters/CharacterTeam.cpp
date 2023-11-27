#include "../../lib/Characters/CharacterTeam.hpp"

CharacterTeam::CharacterTeam(vector<Character *> team, ostream& outout):out(outout){
    this->characters=team;
}

int CharacterTeam::getSize(){
    return this->characters.size();
}

void CharacterTeam::addCharacter(Character *c){
    this->characters.push_back(c);
    out<<c->getName()<<" has joined the team!"<<endl;
}

vector<Character *>* CharacterTeam::getCharacters() {
    return &(this->characters);
}
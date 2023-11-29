#include "../../lib/Characters/PlayerTeam.hpp"
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

PlayerTeam::PlayerTeam(vector<Character *> team, ostream &outout, istream &inin)
    : CharacterTeam(team, outout), in(inin) {
  this->characters = team;
}

Character *PlayerTeam::chooseTarget(vector<Character *> enemies) {
  if(enemies.size()==0){
    out<<"No targets are available."<<endl;
    return nullptr;
  }
  out << "Enemy list:" << endl;
  auto it = enemies.begin();
  int count = 1; // for print options and denote the size of enemies
  for (auto enemy : enemies) {
    out << count << "- " << enemy->getName() << " Hp: " << enemy->getHealth()
        << endl;
    count++;
  }
  out << "Please choose a target:" << endl;
  string input;
  getline(in, input);
  if (in.fail()) {
    throw runtime_error("Input failure.");
  }
  bool checkInputCorrect = false;
  for (int i = 1; i < count; i++) { //check the input is correct or not
    if (input == to_string(i)) {
      checkInputCorrect = true;
      return enemies.at(i - 1);
    }
  }
  while (!checkInputCorrect) { // wrong outpur will go in here and input again
    out << "Please choose a target again:" << endl;
    getline(in, input);
    for (int i = 1; i < count; i++) {
      if (input == to_string(i)) {
        checkInputCorrect = true;
        return enemies.at(i - 1);
      }
    }
  }
  return NULL;
}

void PlayerTeam::addPlayer(Player *p) {
  this->characters.push_back(p);
  out << p->getName() << " has joined the team!" << endl;
}

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
  out << "Enemy list:" << endl;
  auto it = enemies.begin();
  int count = 1; // for print options
  for (auto enemy : enemies) {
    out << count << "- " << enemy->getName() << endl;
    count++;
  }
  out << "Please choose a target:" << endl;
  string input;
  getline(in, input);
  if (in.fail()) {
    throw runtime_error("Input failure.");
  }
  bool checkInputCorrect = false;
  for (int i = 1; i < count; i++) {
    if (input == to_string(i)) {
      checkInputCorrect = true;
      return enemies.at(i - 1);
    }
  }
  while (!checkInputCorrect) {
    cout << "Please choose a target:" << endl;
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

PlayerTeam
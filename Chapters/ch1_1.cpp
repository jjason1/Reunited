#include "../lib/Characters/Character.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../lib/Chapters/Chapter1_1.hpp"

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using std::ostream;
using std::string;

Chapter1_1::Chapter1_1(std::ostream &outout, std::istream &inin): out(outout), in(inin) {

}

void Chapter1_1::setMainCharacter(class Character * c) {
  this->mainCharacter = c;
}

void Chapter1_1::setInput(string input) { this->input = input; }

string Chapter1_1::getMainCharacterName() { return mainCharacter->getName(); }

string Chapter1_1::getInput() {
  return input;
    }

ostream& Chapter1_1::getOutput() {
  return out;
    }

void Chapter1_1::runChapter1_1() {
  runChapter1_1_1();
  runChapter1_1_2();  
    }
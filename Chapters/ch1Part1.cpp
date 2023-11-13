#include "../lib/Characters/Character.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../lib/Chapters/Chapter1Part1.hpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using std::ostream;
using std::string;

Chapter1Part1::Chapter1Part1(std::ostream &outout, std::istream &inin): out(outout), in(inin) {

}

void Chapter1Part1::setMainCharacter(class Character * c) {
  this->mainCharacter = c;
}

void Chapter1Part1::setInput(string input) { this->input = input; }

string Chapter1Part1::getMainCharacterName() { return mainCharacter->getName(); }

string Chapter1Part1::getInput() {
  return input;
    }

ostream& Chapter1Part1::getOutput() {
  return out;
    }

void Chapter1Part1::runChapter1Part1() {
  runChapter1Part1Sub1();
  runChapter1Part1Sub2();  
    }
#include "../lib/Characters/Character.h"
#include "../lib/Characters/Mage.h"
#include "../lib/Characters/Samurai.h"
#include "../lib/Characters/Warrior.h"
#include "ch1.1.1.cpp"
#include "ch1.1.2.cpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using std::ostream;
using std::string;

Character * chapter1_1(std::ostream &out, std::istream &in) {
  Character * mainCharacter;
  mainCharacter = chapter1_1_1(out, in);
  chapter1_1_2(out, in, mainCharacter);
  return mainCharacter;
}
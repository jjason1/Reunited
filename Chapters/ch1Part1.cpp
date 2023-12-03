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

Chapter1Part1::Chapter1Part1(Character *player, std::ostream &outout,
                             std::istream &inin)
    : SubChapter(player, outout, inin) {
  name = "Chapter1Part1";
  playerHp = 0;
}


void Chapter1Part1::runSubChapter() {
  runChapter1Part1Sub1();
  runChapter1Part1Sub2();
}

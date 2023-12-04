#include "../lib/Characters/Character.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../lib/Chapters/Chapter1.hpp"
#include "../lib/Chapters/Chapter1Part1.hpp"
#include "../lib/Chapters/Chapter1Part2.hpp"
#include "../lib/Chapters/Chapter1Part3.hpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>


Chapter1::Chapter1(Character *player, ostream &out, istream &in): Chapter(player,out,in) {
  name = "Chapter1";

  Chapter1Part1 *ch11 = new Chapter1Part1(player, out, in);
  Chapter1Part2 *ch12 = new Chapter1Part2(player, out, in);
  Chapter1Part3 *ch13 = new Chapter1Part3(player, out, in);

  subChapters = {ch11, ch12, ch13};
}

void Chapter1::runChapter() {
  Character * tempPlayer = player;
  for (auto smallChapter : subChapters) { //run the subchapters and pass the player down
    smallChapter->setPlayer(tempPlayer);
    smallChapter->runSubChapter();
    tempPlayer = smallChapter->getPlayer();
  }
}

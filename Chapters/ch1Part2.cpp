#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../lib/Chapters/Chapter1Part2.hpp"

Chapter1Part2::Chapter1Part2(Character *player, ostream &outout, istream &inin)
    : SubChapter(player, outout, inin) {
    name = "Chapter1Part2";
    playerHp=0;
}

void Chapter1Part2::runSubChapter(){
    runChapter1Part2Sub1();
    runChapter1Part2Sub2();
}

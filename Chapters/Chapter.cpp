#include "../lib/Chapters/Chapter.hpp"
#include <vector>

Chapter::Chapter(Character *player, 
                 ostream &out, istream &in)
    : player(player), out(out), in(in) {
    input = "";
    name = "Chapter";
    vector<SubChapter *> empty{};
    subChapters = empty;
}

void Chapter::runChapter() {}

void Chapter::setPlayer(Player *newPlayer) { player = newPlayer; }

string Chapter::getName() { return name; }

void Chapter::setPlayer(Character *newPlayer) { player = newPlayer; }

Character *Chapter::getPlayer() { return player; }
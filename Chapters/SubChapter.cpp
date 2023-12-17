#include "../lib/Chapters/SubChapter.hpp"
#include <string>

SubChapter::SubChapter(Character *player, ostream &out, istream &in)
    : player(player), out(out), in(in) {
  input = "";
  name = "SubChapter";
}


void SubChapter::runSubChapter() {}

void SubChapter::setInput(string input) { this->input = input; }

string SubChapter::getInput() { return input; }

string SubChapter::getName() { return name; }


void SubChapter::setPlayer(Character *newPlayer) { player = newPlayer; }

Character *SubChapter::getPlayer() { return player; }

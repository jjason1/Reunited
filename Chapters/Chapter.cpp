#include "../lib/Chapters/Chapter.hpp"

Chapter::Chapter(Player *player, vector<SubChapter *> subChapters, 
                 ostream &out, istream &in)
    : player(player), subChapters(subChapters), out(out), in(in) {
    input = "";
    name = "Chapter";
}

void Chapter::runChapter() {}

void Chapter::setPlayer(Player *newPlayer) { player = newPlayer; }

string Chapter::getName() { return name; }


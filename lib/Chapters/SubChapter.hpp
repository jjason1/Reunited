#ifndef SUBCHAPTER_HPP
#define SUBCHAPTER_HPP
#include "../Characters/Player.hpp"
#include <istream>
#include <ostream>
#include <string>

class SubChapter {
    private:
      ostream &out;
      istream &in;
      Player *player;
      string input;
      string name; // name of SubChapter
    public:
      SubChapter(Player *, ostream &, istream &);
      virtual void runSubChapter();
      void setInput(string);
      string getInput();
      string getName();
};

#endif

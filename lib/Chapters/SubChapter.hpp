#ifndef SUBCHAPTER_HPP
#define SUBCHAPTER_HPP
#include "../Characters/Character.hpp"
#include <istream>
#include <ostream>
#include <string>

class SubChapter {
    protected:
      ostream &out;
      istream &in;
      Character * player;
      string input;
      string name; // name of SubChapter
      int playerHp;
    public:
      SubChapter(Character *, ostream &, istream &);
      virtual void runSubChapter();
      void setInput(string);
      string getInput();
      string getName();
};

#endif

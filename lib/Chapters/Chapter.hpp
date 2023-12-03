#ifndef CHAPTER_HPP
#define CHAPTER_HPP
#include "../Characters/Player.hpp"
#include "SubChapter.hpp"
#include <istream>
#include <ostream>
#include <string>
#include <vector>

class Chapter {
    private:
      std::ostream &out;
      std::istream &in;
      Player *player;
      string input;
      string name;
      vector<SubChapter *> subChapters;
    
    public:
      Chapter(Player *, vector<SubChapter *>, ostream &, istream &);
      virtual void runChapter();
      void setPlayer(Player *);
      string getName();

};

#endif

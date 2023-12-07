#ifndef CHAPTER_HPP
#define CHAPTER_HPP
#include "../Characters/Player.hpp"
#include "SubChapter.hpp"
#include <istream>
#include <ostream>
#include <string>
#include <vector>

class Chapter {
    protected:
      std::ostream &out;
      std::istream &in;
      Character *player;
      string input;
      string name;
      vector<SubChapter *> subChapters;
    
    public:
      Chapter(Character *, ostream &, istream &);
      virtual void runChapter();
      string getName();
      void setPlayer(Character *);
      Character * getPlayer();

};

#endif

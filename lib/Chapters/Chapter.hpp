#ifndef CHAPTER_HPP
#define CHAPTER_HPP
#include "../Characters/Player.hpp"
#include <istream>
#include <ostream>
#include <string>

class Chapter {
    private:
      std::ostream &out;
      std::istream &in;
      Player *player;
      string input;
};

#endif

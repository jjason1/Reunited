#ifndef CHAPTER_HPP
#define CHAPTER_HPP
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
class Chapter {
private:
  std::ostream& out;
  std::istream& in;
  Character *player;
  string input;

public:
  Chapter(std::ostream& out, std::istream& in, Character *);
  virtual Character* runChapter() = 0;
};

#endif
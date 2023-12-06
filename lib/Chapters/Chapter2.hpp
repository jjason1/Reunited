#ifndef CHAPTER2_HPP
#define CHAPTER2_HPP
#include "Chapter.hpp"
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
class Chapter2: public Chapter{
private:

public:
  Chapter2(Character *, std::ostream& out, std::istream& in);
  Character *runChapter();
};

#endif
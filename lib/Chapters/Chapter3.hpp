#ifndef CHAPTER3_HPP
#define CHAPTER3_HPP
#include "Chapter.hpp"
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
class Chapter3: public Chapter{
private:

public:
  Chapter3(Character *, std::ostream& out, std::istream& in);
  Character *runChapter();
};

#endif
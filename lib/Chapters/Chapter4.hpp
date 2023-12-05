#ifndef CHAPTER4_HPP
#define CHAPTER4_HPP
#include "Chapter.hpp"
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
class Chapter4: public Chapter{
private:

public:
  Chapter4(Character *, std::ostream& out, std::istream& in);
  Character *runChapter();
};

#endif
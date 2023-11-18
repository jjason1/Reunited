#ifndef CHAPTER1_HPP
#define CHAPTER1_HPP
#include "Chapter.hpp"
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
class Chapter1: public Chapter{
private:

public:
  Chapter1(std::ostream& out, std::istream& in);
  Character* runChapter();
};

#endif
#ifndef CHAPTER1_H
#define CHAPTER1_H
#include <cstddef>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
#include "../Chapters/Chapter.hpp"
#include "../Chapters/Chapter1Part1.hpp"
#include "../Chapters/Chapter1Part2.hpp"
#include "../Chapters/Chapter1Part3.hpp"
#include "SubChapter.hpp"
using std::endl;
using std::ostream;
using std::string;

class Chapter1 : public Chapter {
public:
  Chapter1(Character *, ostream&, istream&);
  void runChapter() override;
};
#endif
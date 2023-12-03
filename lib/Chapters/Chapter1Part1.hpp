#ifndef CHAPTER1PART1_H
#define CHAPTER1PART1_H
#include <cstddef>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
#include "SubChapter.hpp"
using std::endl;
using std::ostream;
using std::string;

class Chapter1Part1: public SubChapter {
private:

public:
  Chapter1Part1(Character *,ostream &outout, std::istream &inin);
  void runChapter1Part1Sub1();
  void jobDescription();
  void chooseClass();
  void runSubChapter() override;
  void option1Part1Sub1();
  void runChapter1Part1Sub2();

};

#endif
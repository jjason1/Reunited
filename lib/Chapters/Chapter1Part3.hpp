#ifndef CHAPTER1PART3_H
#define CHAPTER1PART3_H
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

class Chapter1Part3 : public SubChapter {
public:
  Chapter1Part3(Character *, ostream &outout, std::istream &inin);
  void runSubChapter() override;
  void runChapter1Part3Sub1();
  void runChapter1Part3Sub2();
  void runChapter1Part3Sub3();
  
};
#endif
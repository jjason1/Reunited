#ifndef CHAPTER1_1_H
#define CHAPTER1_1_H
#include <cstddef>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
using std::endl;
using std::ostream;
using std::string;

class Chapter1Part1 {
private:
  ostream &out;
  std::istream &in;
  Character *mainCharacter;
  string input;
  string name;
public:
  Chapter1Part1(ostream &outout, std::istream &inin);
  void setMainCharacter(class Character*);
  void setInput(string input);
  string getMainCharacterName();
  string getInput();
  ostream& getOutput();
  void runChapter1Part1();
  void jobDescription();
  void chooseClass();
  void runChapter1Part1Part1();
  void option1Part1Part1();
  void option1Part1Part2();
  void runChapter1Part1Part2();

};

#endif
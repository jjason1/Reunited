#include "../lib/Chapters/Chapter1.hpp"
#include "../lib/Characters/Character.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../Chapters/ch1.cpp"

#include "gtest/gtest.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
using std::stringstream;


TEST(testChapter1Suite, testConstructor) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character *c = new Character("test");

  Chapter1 *ch1 = new Chapter1(c, testout, testin);
  EXPECT_NO_THROW(new Chapter1(c, testout, testin));

  EXPECT_EQ(ch1->getName(), "Chapter1");
}

TEST(testChapter1Suite, testrunChapter) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character *c = new Character("test");

  Chapter1 *ch1 = new Chapter1(c, cout, testin);

  testin << "tester"<< endl;
  testin << "m" << endl;

  for (int j = 0; j< 20; j++) {
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  testin << "1" << endl;
  }

  EXPECT_NO_THROW(ch1->runChapter());
}
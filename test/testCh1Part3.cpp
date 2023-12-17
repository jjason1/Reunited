#include "../lib/Chapters/Chapter1Part3.hpp"
#include "../lib/Characters/Character.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../Chapters/ch1Part3.cpp"
#include "gtest/gtest.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
using std::stringstream;

TEST(testChapter1Part3Suite, testConstructor) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character *c = new Character("test");
  Chapter1Part3 *ch13 = new Chapter1Part3(c, testout, testin);
  EXPECT_NO_THROW(new Chapter1Part3(c, testout, testin));

  EXPECT_EQ(ch13->getName(), "Chapter1Part3");
  EXPECT_EQ(ch13->getInput(), "");
}


TEST(testChapter1Part3Suite, testrunChapter1Part3Sub1) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Mage *c = new Mage("tester");
  for (int i = 0; i< 10; i ++) {
    c->levelUp();
  }
  Chapter1Part3 *ch13 = new Chapter1Part3(c, cout, testin);

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

  EXPECT_NO_THROW(ch13->runChapter1Part3Sub1());
}

TEST(testChapter1Part3Suite, testrunChapter1Part3Sub2) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Mage *c = new Mage("tester");
  for (int i = 0; i< 14; i ++) {
    c->levelUp();
  }
  Chapter1Part3 *ch13 = new Chapter1Part3(c, cout, testin);
  for(int i=0;i<5;i++){
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

  EXPECT_NO_THROW(ch13->runChapter1Part3Sub2());
}

TEST(testChapter1Part3Suite, testrunChapter1Part3Sub3) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Mage *c = new Mage("tester");
  for (int i = 0; i< 18; i ++) {
    c->levelUp();
  }
  Chapter1Part3 *ch13 = new Chapter1Part3(c, cout, testin);

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

  EXPECT_NO_THROW(ch13->runChapter1Part3Sub3());
}

TEST(testChapter1Part3Suite, testrunChapter1Part3Sub4) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Mage *c = new Mage("tester");
  for (int i = 0; i< 22; i ++) {
    c->levelUp();
  }
  Chapter1Part3 *ch13 = new Chapter1Part3(c, cout, testin);
  for(int i=0;i<5;i++){
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

  EXPECT_NO_THROW(ch13->runChapter1Part3Sub4());
}

TEST(testChapter1Part3Suite, testrunChapter1Part3Sub5) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Mage *c = new Mage("tester");
  for (int i = 0; i< 22; i ++) {
    c->levelUp();
  }
  Chapter1Part3 *ch13 = new Chapter1Part3(c, cout, testin);

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

  EXPECT_NO_THROW(ch13->runChapter1Part3Sub5());
}

TEST(testChapter1Part3Suite, testrunChapter) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Mage *c = new Mage("tester");
  for (int i = 0; i< 22; i ++) {
    c->levelUp();
  }
  Chapter1Part3 *ch13 = new Chapter1Part3(c, cout, testin);

  for (int j = 0; j< 5; j++) {
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
  

  EXPECT_NO_THROW(ch13->runSubChapter());
}

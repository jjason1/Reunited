#include "../lib/Chapters/Chapter1.hpp"
#include "../lib/Characters/Character.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../src/StartNewGame.cpp"

#include "gtest/gtest.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
using std::stringstream;

TEST(testStartNewGameSuite, testConstructor) {
  stringstream testout;
  stringstream testin;

  EXPECT_NO_THROW(new StartNewGame(cout, testin));
}

TEST(testStartNewGameSuite, testStart) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;

  StartNewGame * sng = new StartNewGame(cout , testin);

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

  EXPECT_NO_THROW(sng->start());
}
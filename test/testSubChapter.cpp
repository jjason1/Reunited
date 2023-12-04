#include "../Chapters/SubChapter.cpp"
#include "../lib/Characters/Player.hpp"
#include "gtest/gtest.h"

TEST(testSubChapterSuite, testConstructor) {
  Player *player1 = new Player("player1");
  SubChapter *sc = new SubChapter(player1, cout, cin);
  
  EXPECT_NO_THROW(new SubChapter(player1, cout, cin));

  
  EXPECT_EQ(sc->getName(), "SubChapter");
  EXPECT_EQ(sc->getInput(), "");
}

TEST(testSubChapterSuite, testRunChapter) {
  Player *player1 = new Player("player1");
  SubChapter *sc = new SubChapter(player1, cout, cin);

  EXPECT_NO_THROW(sc->runSubChapter());
}

TEST(testSubChapterSuite, testSetInput) {
  Player *player1 = new Player("player1");
  SubChapter *sc = new SubChapter(player1, cout, cin);
  sc->setInput("test");
  EXPECT_EQ(sc->getInput(), "test");
}


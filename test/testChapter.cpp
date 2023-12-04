#include "../Chapters/Chapter.cpp"
#include "gtest/gtest.h"
#include <vector>

TEST(testChapterSuite, testConstructor) {
  Player *player = new Player("tester");
  SubChapter *sc = new SubChapter(player, cout, cin);
  vector<SubChapter *> subChapters{sc};

  EXPECT_NO_THROW(new Chapter(player, cout, cin));
}

TEST(testChapterSuite, testRunChapter) {
  Player *player = new Player("tester");
  SubChapter *sc = new SubChapter(player, cout, cin);
  vector<SubChapter *> subChapters{sc};
  Chapter *c = new Chapter(player, cout, cin);

  EXPECT_NO_THROW(c->runChapter());
}

TEST(testChapterSuite, testSetPlayer) {
  Player *player1 = new Player("tester1");

  Player *player2 = new Player("tester2");
  SubChapter *sc = new SubChapter(player1, cout, cin);
  vector<SubChapter *> subChapters{sc};
  Chapter *c = new Chapter(player1, cout, cin);

  EXPECT_NO_THROW(c->setPlayer(player2));
}

TEST(testChapterSuite, testGetName) {
  Player *player = new Player("tester");
  SubChapter *sc = new SubChapter(player, cout, cin);
  vector<SubChapter *> subChapters{sc};
  Chapter *c = new Chapter(player, cout, cin);

  EXPECT_EQ(c->getName(), "Chapter");
}
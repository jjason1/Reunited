#include "../Chapters/Chapter.cpp"
#include "gtest/gtest.h"
#include <vector>

TEST(testChapterSuite, testConstructor) {
  Player *player = new Player("tester");
  SubChapter *sc = new SubChapter(player, cout, cin);
  vector<SubChapter *> subChapters{sc};

  EXPECT_NO_THROW(new Chapter(player, subChapters, cout, cin));
}
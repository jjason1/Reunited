#ifndef STARTNEWGAME_HPP
#define STARTNEWGAME_HPP

#include <istream>
#include <ostream>
#include <vector>
#include "../lib/Chapters/Chapter.hpp"

class StartNewGame {
  private:
    std::ostream& out;
    std::istream &in;
    vector<Chapter *> chapters;

  public:
    StartNewGame(std::ostream&, std::istream& in);
    ~StartNewGame(){};
    void start();
};

#endif
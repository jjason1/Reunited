#ifndef STARTNEWGAME_HPP
#define STARTNEWGAME_HPP

#include <istream>
#include <ostream>

class StartNewGame {
private:
  std::ostream& out;
  std::istream& in;

public:
  StartNewGame(std::ostream&, std::istream& in);

  void start();

};

#endif
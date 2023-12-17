#include "../lib/StartNewGame.hpp"
#include "../lib/Chapters/Chapter1.hpp"
//#include "../lib/Chapters/Chapter2.hpp"
//#include "../lib/Chapters/Chapter3.hpp"
//#include "../lib/Chapters/Chapter4.hpp"

StartNewGame::StartNewGame(std::ostream &outout, std::istream &inin)
    : out(outout), in(inin) {
    chapters = {};
}


void StartNewGame::start() {
  //Setting our character up.
  Character *mainCharacter = new Character("name");
  
  //Setting up and running Ch. 1:
  Chapter1 ch1 = Chapter1(mainCharacter, this->out, this->in);
  ch1.runChapter();
  mainCharacter = ch1.getPlayer();

  /*
  Chapter2 ch2 = Chapter2(mainCharacter, this->out, this->in);
  mainCharacter = ch2.runChapter();
  Chapter3 ch3 = Chapter3(mainCharacter, this->out, this->in);
  mainCharacter = ch3.runChapter();
  Chapter4 ch4 = Chapter4(mainCharacter, this->out, this->in);
  mainCharacter = ch4.runChapter();
  */

  delete mainCharacter;
}


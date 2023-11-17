#include "../lib/Help.hpp"
#include <cstring>
#include <ostream>
#include <stdexcept>
#include <string>
#include <sstream>
using std::endl;

Help::Help(std::istream &inin, std::ostream &outout) : out(outout), in(inin) {}

Help::~Help() {}

void Help::display() {
  std::string input;
  out << "Basic command instruction:" << endl;
  out << "It is common that you will see some options that allow you to "
         "interact with other NPCs and enemies. When the screen shows some "
         "options, like:"
      << endl;
  out << "1- <Option one>" << endl;
  out << "2- <Option two>" << endl;
  out << "3- <Option three>" << endl;
  out << "You should choose only one of these options each time you encounter "
         "them by using the numbers or alphabets before the dash sign. If you "
         "fail to do so, you will have a chance to choose again until you "
         "select one of the options."
      << endl;
  out << endl;
  out << "For more instructions, please choose the following options:" << endl;
  out << "1- Save file instruction" << endl;
  out << "2- Load file instruction" << endl;
  out << "3- Combat instruction" << endl;
  out << "4- Quit" << endl;
  std::getline(in, input);
  if (in.fail()) {
    throw std::runtime_error("Input failure.");
  }
  while (!(input == "1" || input == "2" || input == "3" || input == "4")) {
    out << "Please input again:" << endl;
    std::getline(in, input);
    if (in.fail()) {
      throw std::runtime_error("Input failure.");
    }
  }
  if (std::strcmp(input.c_str(), "1") == 0) {
    out << "Save file instruction:" << endl;
    out << "At the end of each chapter, you will be asked to select if you "
           "want to save a file. After you save it, your progress will appear "
           "in the save file folder. Next time you want to resume your game, "
           "just use the load file function to load the game."
        << endl;
  }
  else if (std::strcmp(input.c_str(), "2") == 0) {
    out << "Load file instruction:" << endl;
    out << "You will be required to input a save file directory or choose the "
           "file in the save file directory. If the save file is correct, you "
           "will only be able to continue a game from the start of the small "
           "chapter. For example, if you save a file in chapter 1.1, then you "
           "will only be able to start from the start of chapter 1.1."
        << endl;
  } else if (std::strcmp(input.c_str(), "3") == 0) {
    out << "Combat instruction:" << endl;
    out << "When you encounter a battle, your team will attack first. After "
           "your team\'s members have used some skills or attacks, the enemy "
           "team will start to attack. This battle only ends if you escape or "
           "one of the teams has been eliminated by another. When you use your "
           "character\'s skill, you need to specify a target if it is a single "
           "target skill. If it is an AOE skill, you do not need to specify "
           "and will automatically use the skill when you choose it."
        << endl;
  }
  else if (std::strcmp(input.c_str(), "4") == 0) { // back to menu will be implement in menu fuction call menu display again
    out << "Quitting the menu." <<endl;
  }
}
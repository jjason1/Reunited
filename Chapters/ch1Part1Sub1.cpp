#include "../lib/Characters/Character.hpp"
#include "../lib/Chapters/Chapter1Part1.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../lib/checkInput.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using std::endl;
using std::ostream;
using std::string;



void Chapter1Part1::jobDescription() {
  out << "w-Warrior" << endl;
  out << "Description: As a Warrior, your primary role is to be the stalwart \
    defender of your party, ensuring the safety of your comrades on the battlefield.\
     You are a master of defensive skills and tactics,\
      capable of withstanding even the most formidable foes.\
       Your unwavering dedication to protection makes you an \
       indispensable asset in any group."
      << endl;
  out << endl;
  out << "m-Mage" << endl;
  out << "Description: As a Mage, you possess a unique combination of magical prowess and balance in your abilities.\
     You harness the power of arcane energies to both damage enemies and support your allies.\
      Your adaptability and versatility in the arcane arts make you an invaluable addition\
       to any adventuring party."
      << endl;
  out << endl;
  out << "s-Samurai" << endl;
  out << "Description: The Samurai is a master of offense, wielding a blade with precision and skill.\
     As a Samurai, your primary focus is to unleash powerful and devastating attacks on your enemies.\
      Your offensive nature makes you a formidable force on the battlefield,\
       and your precision ensures that your strikes find their mark."
      << endl;
}

void Chapter1Part1::chooseClass() {
  out << "What kind of job class you want?" << endl;
  jobDescription();
  std::getline(in, input);
  checkInput(in);
  while (input != "w" && input != "m" && input != "s") {

    out << "Please input class again(w for Warrior, m for Mage, s for Samurai):";
    std::getline(in, input);
  }
  if (input == "w") { // warrior not complete yet
    //out << "You have choosed Warrior as your class." << endl;
    //Warrior *w = new Warrior(name);
    //player = w;
  } else if (input == "m") {
    out << "You have choosed Mage as your class." << endl;
    Mage *m = new Mage(name);
    player = m;
  } else {
    out << "You have choosed Samurai as your class." << endl;
    Samurai *s = new Samurai(name);
    player = s;
  }
}

void Chapter1Part1::runChapter1Part1Sub1() {
  string typedName;
  string cls;

  out << "Game start!" << endl;
  out << "Chapter1" << endl;
  out << "What is your character's name?(Do not contain your name with space)"
      << endl;
  std::getline(in, name);
  checkInput(in);
  

  chooseClass();

}

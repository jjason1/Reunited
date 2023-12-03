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
  out << "\nw-Warrior" << endl;
  out << "Description: As a Warrior, your primary role is to be the stalwart \n"
    "defender of your party, ensuring the safety of your comrades on the battlefield.\n"
     "You are a master of defensive skills and tactics,\n"
      "capable of withstanding even the most formidable foes.\n"
       "Your unwavering dedication to protection makes you an \n"
       "indispensable asset in any group."
      << endl;
  out << endl;
  out << "m-Mage" << endl;
  out << "Description: As a Mage, you possess a unique combination of magical prowess and balance in your abilities.\n"
     "You harness the power of arcane energies to both damage enemies and support your allies.\n"
      "Your adaptability and versatility in the arcane arts make you an invaluable addition\n"
       "to any adventuring party."
      << endl;
  out << endl;
  out << "s-Samurai" << endl;
  out << "Description: The Samurai is a master of offense, wielding a blade with precision and skill.\n"
     "As a Samurai, your primary focus is to unleash powerful and devastating attacks on your enemies.\n"
      "Your offensive nature makes you a formidable force on the battlefield,\n"
       "and your precision ensures that your strikes find their mark."
      << endl;
}

void Chapter1Part1::chooseClass() {
  out << "What character type would you like?" << endl;
  jobDescription();
  std::getline(in, input);
  checkInput(in);
  while (input != "w" && input != "m" && input != "s") {

    out << "Please input class again(w for Warrior, m for Mage, s for Samurai):";
    std::getline(in, input);
  }
  if (input == "w") { // warrior not complete yet
    //out << "\nYou have chosen Warrior as your class." << endl;
    //Warrior *w = new Warrior(name);
    //player = w;
  } else if (input == "m") {
    out << "\nYou have chosen Mage as your class." << endl;
    Mage *m = new Mage(name);
    player = m;
  } else {
    out << "\nYou have chosen Samurai as your class." << endl;
    Samurai *s = new Samurai(name);
    player = s;
  }
}

void Chapter1Part1::runChapter1Part1Sub1() {
  string typedName;
  string cls;

  out << "\nGame start!" << endl;
  out << "Chapter 1 Begins..." << endl;
  out << "\nWhat is your character's name? (Do not use any spaces within your name.)"
      << endl;
  std::getline(in, name);
  checkInput(in);
  

  chooseClass();

}

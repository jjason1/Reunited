#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "../src/Characters/Character.h"
using std::cout;
using std::endl;
using std::ostream;
using std::runtime_error;
using std::string;

void checkInput(std::istream &in)
{
  if (in.fail())
  {
    throw runtime_error("input failure.");
  }
}

void option1_1_1(std::ostream &out, std::istream &in, string input, Character *mainCharacter) // for choose to move forward to forest or first talk
{
  out << "[Select Option]" << endl;
  out << "1- Look around" << endl;
  out << "2- Talk to Isabella" << endl;
  out << "3- Move forward" << endl;
  in >> input;
  while (input != "1" && input != "2" && input != "3")
  {
    /* code */
  }
  
  if(in == "2")
  {
    out << "You turn to Isabella, who has been walking silently by your side,\
     and decide to strike up a conversation."
        << endl;
    out << "You: How are you holding up, Isabella? It's been a tough journey so far." << endl;
    out << "Isabella: I'm exhausted, " << mainCharacter->showCharacterName() << ", but we have to keep moving." << endl;
    out << "You:  I know it's been hard, but we'll find a new home soon, I promise." << endl;
    out << "You continue through the forest, determined to find a new home.\
     The dense trees seem to close in around you, making you acutely aware of the solitude of your journey."
        << endl;
  }
  else if (in == "1")
  {
    /* code */
  }
  
}

void chapter1_1_2(std::ostream &out, std::istream &in, Character *mainCharacter)
{
  string input;

  out << "[Forest Clearing]" << endl;
  out << "Your journey began in a land ravaged by the cruel hands of war, \
     and now you find yourself standing in the heart of a dense forest. \
     You,"
      << mainCharacter->showCharacterName() << ", have embarked on this quest alongside your sister, \
     Isabella, in search of a new home and a chance for redemption. \
     Your previous town was pillaged, and your hearts are heavy with \
     the memories of its destruction."
      << endl;
  
}
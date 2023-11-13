#include "../lib/Characters/Character.hpp"
#include "../lib/Chapters/Chapter1Part1.hpp"
#include "../lib/checkInput.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using std::endl;
using std::ostream;
using std::string;

void Chapter1Part1::option1Part1Sub1() {

  out << "[Select Option]" << endl;
  out << "1- Stay here Annie, I\'m going to help this poor guy." << endl;
  getline(in, input);
  checkInput(in);
  while (input != "1") {
    out << "input again" << endl;
    getline(in, input);
    checkInput(in);
  }

  if (std::strcmp(input.c_str(), "1") == 0) {
    out << "You: Stay here Anne, I\'m going to help this poor guy." << endl;
  }
}

void Chapter1Part1::option1Part1Sub2() // for choose to move forward to
                                           // forest or first talk
{
  out << "[Select Option]" << endl;
  out << "1- Stop right there, don’t touch that girl!" << endl;
  out << "2- (Silently approach)" << endl;
  std::getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "input again" << endl;
    getline(in, input);
    checkInput(in);
  }

  if (std::strcmp(input.c_str(), "1") == 0) {
    out << "Stop right there, don’t touch that girl!"
        << endl;
    
  } else if (std::strcmp(input.c_str(), "2") == 0) {
    out << "(Silently approach)" << endl;
  } 
}

void Chapter1Part1::runChapter1Part1Sub2() {
  out << "Chapter1.1" << endl;
  out << endl;
  out << "System: Our journey begins in a land ravaged by the cruel hands of war,\
and now you and your sister Annie are escaping from the war. After several days of running,\
you find yourself standing in the heart of a dense forest."
      << endl;
  out << endl;
  out << "Annie: Where are we going? Is there any town or city nearby?" << endl;
  option1Part1Sub1();
  out << "No one is going to help you hehe! (The bandit lick his blade and no "
         "one knows what he is going to do next)"
      << endl;
  option1Part1Sub2();
  out << "Bandit: What the hell you idiots doing? I gotto kill ya all." << endl;
  out << "System: You encounter with a bandit.";
  // need to implement combat start here
}
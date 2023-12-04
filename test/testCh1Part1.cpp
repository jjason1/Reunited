#include "../lib/Chapters/Chapter1Part1.hpp"
#include "../lib/Characters/Character.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../Chapters/ch1Part1Sub1.cpp"
#include "../Chapters/ch1Part1Sub2.cpp"
#include "../Chapters/ch1Part1.cpp"
#include "../Chapters/checkInput.cpp"
#include "gtest/gtest.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
using std::stringstream;

TEST(TestCH1Part1Suite, TestConstructer) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character *c = new Character("test");
  Chapter1Part1 *ch11 = new Chapter1Part1(c, testout, testin);
  EXPECT_NO_THROW(new Chapter1Part1(c, testout, testin));

  EXPECT_EQ(ch11->getName(), "Chapter1Part1");
  EXPECT_EQ(ch11->getInput(), "");
  
}

TEST(TestCH1Part1Suite, TestjobDescription) // test if output are equal
{
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character * c = new Character("test");
  Chapter1Part1 *ch11 = new Chapter1Part1(c, testout, testin);
  
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

  ch11->jobDescription();

  EXPECT_EQ( testout.str(), out.str());
}

TEST(TestCH1Part1Suite, testChooseClassMage) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character * c = new Character("test");
  Chapter1Part1 *ch11 = new Chapter1Part1(c, testout, testin);

  testin << "m" << endl; // choose mage

  out << "What character type would you like?" << endl;
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
  out << "\nYou have chosen Mage as your class." << endl;

  EXPECT_NO_THROW(ch11->chooseClass());
  EXPECT_EQ( testout.str(), out.str());
}

TEST(TestCH1Part1Suite, testChooseClassSamurai) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character * c = new Character("test");
  Chapter1Part1 *ch11 = new Chapter1Part1(c, testout, testin);

  testin << "s" << endl; // choose mage

  out << "What character type would you like?" << endl;
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
  out << "\nYou have chosen Samurai as your class." << endl;

  EXPECT_NO_THROW(ch11->chooseClass());
  EXPECT_EQ( testout.str(), out.str());
}

TEST(TestCH1Part1Suite, testrunChapter1Part1Sub1ChooseMageClass) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character * c = new Character("test");
  Chapter1Part1 *ch11 = new Chapter1Part1(c, testout, testin);

  testin << "tester"<< endl;
  testin << "m" << endl;

  out << "\nGame start!" << endl;
  out << "Chapter 1 Begins..." << endl;
  out << "\nWhat is your character's name? (Do not use any spaces within your name.)"
      << endl;
  out << "What character type would you like?" << endl;
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
  out << "\nYou have chosen Mage as your class." << endl;

  EXPECT_NO_THROW(ch11->runChapter1Part1Sub1());


  EXPECT_EQ( testout.str(), out.str()); 
}


TEST(TestCH1Part1Suite, testOption1) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character * c = new Character("test");
  Chapter1Part1 *ch11 = new Chapter1Part1(c, testout, testin);

  testin << "1" << endl;

  out << "[Select Option]" << endl;
  out << "1.  Stop right there, don\'t go anywhere near that girl!" << endl
      << "    (Silently approach the bandit.)" << endl;

  EXPECT_NO_THROW(ch11->option1Part1Sub1());
  EXPECT_EQ( testout.str(), out.str()); 
}

TEST(TestCH1Part1Suite, testrunChapter1Part1Sub2){
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character * mage = new Mage("test");
  Chapter1Part1 *ch11 = new Chapter1Part1(mage, cout, testin);

  testin << "1" << endl; // choose option
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; // choose first target

  EXPECT_NO_THROW(ch11->runChapter1Part1Sub2());
}

TEST(TestCH1Part1Suite, testrunChapterWithMage) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  Character * c = new Character("test");
  Chapter1Part1 *ch11 = new Chapter1Part1(c, cout, testin);

  testin << "tester"<< endl;
  testin << "m" << endl;

  testin << "1" << endl; // choose option
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; //choose first target
  testin << "1" << endl; // choose first skill
  testin << "1" << endl; // choose first target

  EXPECT_NO_THROW(ch11->runSubChapter());
}
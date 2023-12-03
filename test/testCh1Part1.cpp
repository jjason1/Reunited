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

  out << "What kind of job class you want?" << endl;
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
  out << "You have choosed Mage as your class." << endl;

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

  out << "What kind of job class you want?" << endl;
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
  out << "You have choosed Samurai as your class." << endl;

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

  out << "Game start!" << endl;
  out << "Chapter1" << endl;
  out << "What is your character's name?(Do not contain your name with space)"
      << endl;
  out << "What kind of job class you want?" << endl;
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
  out << "You have choosed Mage as your class." << endl;

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
      << "(Silently approach the bandit.)" << endl;

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
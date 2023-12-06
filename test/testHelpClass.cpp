#include "../src/Help.cpp"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <string>

TEST(testHelpClassSuite, testSaveFileInstruction) {
  std::stringstream testout;
  std::stringstream testin("1");
  std::stringstream out;
  std::cin.rdbuf(testin.rdbuf());
  Help *testHelp = new Help(std::cin, testout);
  testHelp->display();

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
  out << "Save file instruction:" << endl;
    out << "At the end of each chapter, you will be asked to select if you "
           "want to save a file. After you save it, your progress will appear "
           "in the save file folder. Next time you want to resume your game, "
           "just use the load file function to load the game."
        << endl;
  EXPECT_TRUE(testout.str() == out.str());
}

TEST(testHelpClassSuite, testLoadFileInstruction) {
  std::stringstream testout;
  std::stringstream testin("2");
  std::stringstream out;
  std::cin.rdbuf(testin.rdbuf());
  Help *testHelp = new Help(std::cin, testout);
  testHelp->display();

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
  out << "Load file instruction:" << endl;
    out << "You will be required to input a save file directory or choose the "
           "file in the save file directory. If the save file is correct, you "
           "will only be able to continue a game from the start of the small "
           "chapter. For example, if you save a file in chapter 1.1, then you "
           "will only be able to start from the start of chapter 1.1."
        << endl;
  EXPECT_TRUE(testout.str() == out.str());
}

TEST(testHelpClassSuite, testCombatInstruction) {
  std::stringstream testout;
  std::stringstream testin("3");
  std::stringstream out;
  std::cin.rdbuf(testin.rdbuf());
  Help *testHelp = new Help(std::cin, testout);
  testHelp->display();

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
  out << "Combat instruction:" << endl;
    out << "When you encounter a battle, your team will attack first. After "
           "your team\'s members have used some skills or attacks, the enemy "
           "team will start to attack. This battle only ends if you escape or "
           "one of the teams has been eliminated by another. When you use your "
           "character\'s skill, you need to specify a target if it is a single "
           "target skill. If it is an AOE skill, you do not need to specify "
           "and will automatically use the skill when you choose it."
        << endl;
  EXPECT_TRUE(testout.str() == out.str());
}

TEST(testHelpClassSuite, testQuit) {
  std::stringstream testout;
  std::stringstream testin("4");
  std::stringstream out;
  //std::cin.rdbuf(testin.rdbuf());
  Help *testHelp = new Help(testin, testout);
  testHelp->display();

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
  out << "Quitting the help menu." <<endl;
  EXPECT_TRUE(testout.str() == out.str());
}


TEST(testHelpClassSuite, testTypeWrongInputNumber) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  testin << "5" << endl;
  testin << "1";
  Help *testHelp = new Help(testin, testout);
  testHelp->display();

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
  out << "Please input again:" << endl;
  out << "Save file instruction:" << endl;
    out << "At the end of each chapter, you will be asked to select if you "
           "want to save a file. After you save it, your progress will appear "
           "in the save file folder. Next time you want to resume your game, "
           "just use the load file function to load the game."
        << endl;

  EXPECT_TRUE(testout.str() == out.str());
}

TEST(testHelpClassSuite, testTypeWrongInputAlphabet) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  testin << "abc efgh" << endl;
  testin << "1";
  Help *testHelp = new Help(testin, testout);
  testHelp->display();

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
  out << "Please input again:" << endl;
  out << "Save file instruction:" << endl;
    out << "At the end of each chapter, you will be asked to select if you "
           "want to save a file. After you save it, your progress will appear "
           "in the save file folder. Next time you want to resume your game, "
           "just use the load file function to load the game."
        << endl;

  EXPECT_TRUE(testout.str() == out.str());
}

TEST(testHelpClassSuite, testInputFail) {
  std::stringstream testout;
  std::stringstream testin;
  std::stringstream out;
  testin << "5";
  testin << "1";
  Help *testHelp = new Help(testin, testout);
  

  EXPECT_THROW(testHelp->display(),std::runtime_error);
}
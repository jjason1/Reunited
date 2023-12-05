#include "gtest/gtest.h"
#include "../src/Menu.cpp"

TEST(MenuClassSuite, testNewMenu){
    stringstream in;
    stringstream out;
    EXPECT_NO_THROW(new Menu(in, out));
}

TEST(MenuClassSuite, testMenuDisplay){
    stringstream in;
    stringstream out;

    string menu = "1. Start New Game\n"
    "2. Load Game\n"
    "3. Show Developers\n"
    "4. Help\n"
    "5. Quit\n"
    "Enter your choice: ";

    Menu myMenu(in, out);
    myMenu.displayMenu();

    EXPECT_EQ(out.str(), menu);
}

TEST(MenuClassSuite, testShowHelp){
    stringstream in;
    stringstream out;

    string menu = "1. Start New Game\n"
    "2. Load Game\n"
    "3. Show Developers\n"
    "4. Help\n"
    "5. Quit\n"
    "Enter your choice: ";

    Menu myMenu(in, out);
    myMenu.displayMenu();

    EXPECT_EQ(out.str(), menu);
}
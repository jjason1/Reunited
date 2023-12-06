#include "gtest/gtest.h"
#include "../src/Menu.cpp"

TEST(MenuClassSuite, testNewMenu){
    stringstream in;
    stringstream testout;
    EXPECT_NO_THROW(new Menu(in, testout));
}

TEST(MenuClassSuite, testMenuDisplay){
    stringstream in("5\n");
    stringstream testout;

    string expectedMenu = "1. Start New Game\n"
    "2. Load Game\n"
    "3. Show Developers\n"
    "4. Help\n"
    "5. Quit\n"
    "Enter your choice: quiting the game.\n";
    

    Menu *myMenu = new Menu(in, testout);
    myMenu->displayMenu();
   

    EXPECT_EQ(testout.str(), expectedMenu);
    EXPECT_TRUE(myMenu->isQuitCalled());
}


TEST(MenuClassSuite, testShowHelp){
    stringstream in("4\n");
    
    stringstream out;
    stringstream testout;
    cin.rdbuf(in.rdbuf());
    Menu *myMenu = new Menu(in, testout);
    myMenu->displayHelpMenu();
    delete myMenu;

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
    out << "Quitting the menu.\n";

  EXPECT_EQ(out.str(), testout.str());
}

TEST(MenuClassSuite, testShowDevelopers){
    stringstream in("x\n");
    stringstream testout;
    stringstream out;
    cin.rdbuf(in.rdbuf());

    Menu *myMenu = new Menu(in, testout);
    myMenu->showDevelopers();
    out << "Developer names:\n"
            "Jason Lin,\n"
            "Cheng-Shun Chuang,\n"
            "Aamir Khan,\n"
            "Boyi Li\n";
    delete myMenu;

    EXPECT_EQ(out.str(), testout.str());
}

TEST(MenuClassSuite, testStartNewGame) {
    stringstream testin;
    stringstream testout;
    
    testin << "tester"<< endl;
    testin << "m" << endl;
    for (int j = 0; j< 20; j++) {
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
    testin << "1" << endl;
  }

    Menu *myMenu = new Menu(testin, testout);
    EXPECT_NO_THROW(myMenu->startNewGame());
    
}

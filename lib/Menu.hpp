#ifndef MENU_HPP
#define MENU_HPP
using namespace std;

#include <iostream>
#include "Help.hpp"
#include "showDevelopers.h"
#include "StartNewGame.hpp"
#include "Chapters/Chapter.hpp"
class Menu {
    bool shouldQuit;
private:
    istream& in;
    ostream& out;
    int choice;
    
public:
    // Constructor
    Menu(istream& , ostream&);
    ~Menu();
    
    void displayHelpMenu();
    void showDevelopers();
    void startNewGame();
    void loadGameFile();
    void displayMenu();
    void quit();

    bool isQuitCalled() const { return shouldQuit; }
};

#endif // MENU_HPP
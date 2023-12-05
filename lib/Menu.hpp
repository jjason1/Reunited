#ifndef MENU_HPP
#define MENU_HPP
using namespace std;

#include <iostream>
#include "Help.hpp"
#include "showDevelopers.h"
#include "StartNewGame.hpp"
#include "Chapters/Chapter.hpp"
class Menu {
private:
    istream& in;
    ostream& out;
    int choice;
public:
    // Constructor
    Menu(istream& in, ostream& out);

    // Methods as per UML diagram
    void displayHelpMenu();
    void showDevelopers();
    void startNewGame();
    void loadGameFile();
    void displayMenu();
    void quit();
};

#endif // MENU_HPP
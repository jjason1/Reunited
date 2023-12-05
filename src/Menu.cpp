#include "../lib/Menu.hpp"
using namespace std;


Menu::Menu(istream& inStream, ostream& out) : in(in), out(out) {
    int choice = 0;

   
   
}



void Menu::displayHelpMenu() {
    Help help(in, out);
    help.display();
    
}

void Menu::showDevelopers() {
    // Implementation of showDevelopers
    showDevelopers();
}

void Menu::startNewGame() {
    // Implementation of startNewGame
    StartNewGame newGame(out, in);
    newGame.start();
}

void Menu::loadGameFile() {
    // Implementation of loadGameFile
}

void Menu::displayMenu() {
    // Implementation of displayMenu
   do {
    // Implementation of displayHelpMenu
    out << "1. Start New Game" << endl;
    out << "2. Load Game" << endl;
    out << "3. Show Developers" << endl;
    out << "4. Help" << endl;
    out << "5. Quit" << endl;
    out << "Enter your choice: ";
    in >> choice;

    switch (choice) {
        case 1:
            startNewGame();
            break;
        case 2:
            loadGameFile();
            break;
        case 3:
            showDevelopers();
            break;
        case 4:
            displayHelpMenu();
            break;
        case 5:
            quit();
            break;
        default:
            out << "Invalid option. Please try again." << endl;
            displayMenu();
            break;
    }
    } while (choice != 5);
}

void Menu::quit() {
    // Implementation of quit
}
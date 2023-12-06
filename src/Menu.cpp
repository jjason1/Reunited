#include "../lib/Menu.hpp"
using namespace std;


Menu::Menu(istream& in, ostream& out) : in(in), out(out), shouldQuit(false)  {}

Menu::~Menu() {};


void Menu::displayHelpMenu() {
    Help help(in, out);
    help.display();
    
}

void Menu::showDevelopers() {
    // Implementation of showDevelopers
    ::showDevelopers(out);
}

void Menu::startNewGame() {
    // Implementation of startNewGame
    out << "Starting a new game." << endl;
    StartNewGame* newGame = new StartNewGame(out, in);
    newGame->start();
    
}

void Menu::loadGameFile() {
    // Implementation of loadGameFile
}

void Menu::displayMenu() {
    string input;
    out << "1. Start New Game" << endl;
    out << "2. Load Game" << endl;
    out << "3. Show Developers" << endl;
    out << "4. Help" << endl;
    out << "5. Quit" << endl;
    out << "Enter your choice: ";
    getline(in, input);

    if (in.fail()) {
        throw runtime_error("Input failure.");
    }

    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5") {
        out << "Invalid option. Please input again:" << endl;
        in.clear(); 
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        getline(in, input);
        if (in.fail()) {
            throw runtime_error("Input failure.");
        }
    }

    if (input == "1") {
        startNewGame();
    } else if (input == "2") {
        loadGameFile();
    } else if (input == "3") {
        showDevelopers();
    } else if (input == "4") {
        displayHelpMenu();
    } else if (input == "5") {
        quit();
    }
}

void Menu::quit() {
    out << "quiting the game." << endl;
    shouldQuit = true;  
}

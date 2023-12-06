#include "../lib/Menu.hpp"
using namespace std;


Menu::Menu(istream& in, ostream& out) : in(in), out(out), shouldQuit(false)  {}

Menu::~Menu() {};

void Menu::displayHelpMenu() {
    Help *helpMenu=new Help(in, out);
    helpMenu->display();
    delete helpMenu;
}

void Menu::showDevelopers() {
    // Display developers.
    ::showDevelopers(out);
}

void Menu::startNewGame() {
    // Start a brand new game.
    out << "Starting a new game..." << endl;
    StartNewGame *newGame = new StartNewGame(out, in);
    newGame->start();
    delete newGame;
}

void Menu::displayMenu() {
    string input;
    out << "1. Start New Game" << endl;
    out << "2. Show Developers" << endl;
    out << "3. Help" << endl;
    out << "4. Quit" << endl;
    out << "Enter your choice: ";
    getline(in, input);

    if (in.fail()) {
        throw runtime_error("Input failure.");
    }

    while (input != "1" && input != "2" && input != "3" && input != "4") {
        out << "Invalid option. Please input again: " << endl;
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
        showDevelopers();
    } else if (input == "3") {
        displayHelpMenu();
    } else if (input == "4") {
        quit();
    }
}

void Menu::quit() {
    out << "\nQuiting the game..." << endl;
    shouldQuit = true;  
}

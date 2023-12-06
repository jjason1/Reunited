#include <ctime>
#include <cstdlib>
#include "../lib/Menu.hpp"

int main(int argv, char** argc) {
    //Set the random number seed.
    srand(static_cast<unsigned int>(time(0)));

    cout<<"\nReunited: Text-Based RPG"<<endl;
    cout<<"------------------------\n"<<endl;

    Menu *menu=new Menu(cin,cout);

    while(!menu->isQuitCalled()){
        menu->displayMenu();
    }
    
    delete menu;
}

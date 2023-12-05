#include <ctime>
#include <cstdlib>
#include "../lib/Chapters/Chapter1.hpp"
#include "../lib/StartNewGame.hpp"

int main(int argv, char** argc) {
    //Set the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    StartNewGame *sng=new StartNewGame(cout,cin);
    sng->start();
}
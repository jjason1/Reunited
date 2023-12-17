#ifndef CHAPTER1PART2_HPP
#define CHAPTER1PART2_HPP
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include "../Characters/Character.hpp"
#include "SubChapter.hpp"
using namespace std;

class Chapter1Part2: public SubChapter {
    public:
        Chapter1Part2(Character *, ostream &outout, istream &inin);
        void runChapter1Part2Sub1();
        void runChapter1Part2Sub2();
        void runSubChapter() override;
        void option1();
        void option2();
        void option3();
        void option4();
        void option5();
        void option6();
};

#endif
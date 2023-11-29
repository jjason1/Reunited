#ifndef GOLEM_HPP
#define GOLEM_HPP


#include <vector>
#include "../../lib/Enemies/Enemy.hpp"
using namespace std;

class Golem : public Enemy {

    private:
        int CD = 0;

    public:

        Golem(string name, int level);
        void lazerBlaze(Character *target);
        void earthquake(vector<Character *> &targets);
        void shieldGen();


};

#endif /* GOLEM_HPP */
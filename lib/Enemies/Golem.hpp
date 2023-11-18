#ifndef GOLEM_HPP
#define GOLEM_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "../../lib/Enemies/Enemy.hpp"
using namespace std;

class Golem : public Enemy {
public:

    Golem(string name);
    void lazerBlaze(Character *target);
    void earthquake(vector<Character *> &targets);
    void shieldGen();


    virtual void getStatus(ostream &out) override;
};

#endif /* GOLEM_HPP */
#ifndef GOLEM_HPP
#define GOLEM_HPP


#include <vector>
#include "../../lib/Enemies/Enemy.hpp"
using namespace std;

class Golem : public Enemy {


    public:
        int CD = 0;
        Golem(string name, int level);
        void lazerBlaze(Character *target);
        void earthquake(vector<Character *> &targets);
        void shieldGen();

        virtual int selectSkill(istream &);
        virtual void useSkillOn(int, vector<Character *> &targets);


};

#endif /* GOLEM_HPP */
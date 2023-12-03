#ifndef GOLEM_HPP
#define GOLEM_HPP


#include <vector>
#include "../../lib/Enemies/Enemy.hpp"
#include "../../lib/Characters/Character.hpp"
using namespace std;

class Golem : public Enemy {


    public:
        int CD = 0;
        Golem(string name, int level);
        void lazerBlaze(Character *);
        void earthquake(vector<Character *> &);
        void shieldGen();

        virtual int selectSkill(istream &);
        virtual void useSkillOn(int, vector<Character *> &);


};

#endif /* GOLEM_HPP */
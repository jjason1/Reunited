#ifndef CHARACTERTEAM_HPP
#define CHARACTERTEAM_HPP

#include <istream>
#include <ostream>
#include <vector>
#include "Character.hpp"
#include <fstream>

class CharacterTeam{
    protected:
        vector<Character *> characters;
        ostream &out;
    public:
        CharacterTeam(vector<Character *>, ostream &);
        ~CharacterTeam();
        void addCharacter(Character *);
        virtual Character *chooseTarget(vector<Character *>);
        int getSize();
        vector<Character *> getCharacters();
};

#endif /* CHARACTERTEAM_HPP */
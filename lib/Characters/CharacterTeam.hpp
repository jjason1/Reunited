#ifndef CHARACTERTEAM_HPP
#define CHARACTERTEAM_HPP

#include <vector>
#include "Character.hpp"
#include <fstream>

class CharacterTeam{
    protected:
        vector<Character *> characters;
        ostream &out;
    public:
        CharacterTeam(vector<Character *>, ostream &);
        void addCharacter(Character *);
        Character *chooseTarget(vector<Character *>);
        int getSize();
        vector<Character *> getCharacters();    
};

#endif /* CHARACTERTEAM_HPP */
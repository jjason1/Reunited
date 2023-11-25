#ifndef CHARACTERTEAM_HPP
#define CHARACTERTEAM_HPP

#include <vector>
#include "Character.hpp"

class CharacterTeam{
    protected:
        vector<Character *> characters;
    public:
        CharacterTeam(vector<Character *>);
        void addCharacter(Character *);
        int getSize();    
};

#endif /* CHARACTERTEAM_HPP */
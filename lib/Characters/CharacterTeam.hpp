#ifndef CHARACTERTEAM_HPP
#define CHARACTERTEAM_HPP

#include <istream>
#include <ostream>
#include <vector>
#include "Character.hpp"


class CharacterTeam{
    protected:
      vector<Character *> characters;
      ostream &out;
      istream &in;
    public:
        CharacterTeam(vector<Character *>, ostream&, istream&);
        void addCharacter(Character *);
        int getSize();
        vector<Character *>* getCharacters();
};

#endif /* CHARACTERTEAM_HPP */
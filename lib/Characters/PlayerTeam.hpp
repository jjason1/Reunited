#ifndef PLAYERTEAM_HPP
#define PLAYERTEAM_HPP

#include "CharacterTeam.hpp"

class PlayerTeam : public CharacterTeam {
private:
  istream &in;
public:
  PlayerTeam(vector<Character *>, ostream&, istream&);
  Character* chooseTarget(vector<Character *>* enemies);
  void addPlayer(Player * p);
};

#endif
#ifndef PLAYERTEAM_HPP
#define PLAYERTEAM_HPP

#include "CharacterTeam.hpp"
#include "Player.hpp"

class PlayerTeam : public CharacterTeam {
private:
  istream &in;

public:
  PlayerTeam(vector<Character *>, ostream &, istream &);
  ~PlayerTeam(){};
  Character *chooseTarget(vector<Character *> enemies) override;
};

#endif
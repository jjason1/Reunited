#include "../../lib/Enemies/EnemyTeam.hpp"

EnemyTeam::EnemyTeam(vector<Character *> enemies) : CharacterTeam::CharacterTeam(enemies){}

void EnemyTeam::addEnemy(Enemy *enemy){
    this->characters.push_back(enemy);
    cout<<enemy->getName()<<" has joined the enemy team!"<<endl;
}

Character * EnemyTeam::chooseTarget(vector<Character *> players){
    //Returning a random target from the vector of players.
    return players[rand()%players.size()];
}
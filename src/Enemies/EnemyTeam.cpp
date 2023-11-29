#include "../../lib/Enemies/EnemyTeam.hpp"

EnemyTeam::EnemyTeam(vector<Character *> enemies, ostream &out) : 
    CharacterTeam::CharacterTeam(enemies,out){}

Character *EnemyTeam::chooseTarget(vector<Character *> players){
    if(players.size()==0){
        out<<"No targets are available."<<endl;
        return nullptr;
    }
    //Selecting a random target.
    int target=rand()%players.size();
    //Displaying the player being targetted.
    out<<players[target]->getName()<<" is being targeted by the enemy team."<<endl;
    //Returning the target from the vector of players.
    return players[target];
}

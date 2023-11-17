#include "../../lib/Enemies/EnemyTeam.hpp"

EnemyTeam::EnemyTeam(vector<Enemy *> enemyList){
    this->enemyList=enemyList;
}

void EnemyTeam::setSize(int size){
    this->numEnemies=size;
}

int EnemyTeam::getSize(){
    return this->numEnemies;
}

void EnemyTeam::addEnemy(Enemy *e){
    this->enemyList.push_back(e);
}

Character * EnemyTeam::chooseTarget(vector<Character *> team,int indx){
    //If the provided team is empty...
    if(team.size()==0) return nullptr;
    //Returning a specific character ptr.
    if(indx>=0 && indx<team.size()){
        return team[indx];
    }
    else return nullptr;
}

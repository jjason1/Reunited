#include "../../lib/Enemies/EnemyTeam.hpp"

EnemyTeam::EnemyTeam(vector<Enemy *> enemyList){

}

void EnemyTeam::setSize(int size){

}

int EnemyTeam::getSize(){

}

void EnemyTeam::addEnemy(Enemy *e){
    this->enemyList.push_back(e);
}

Character * EnemyTeam::chooseTarget(vector<Character *> team,int indx){
    
}

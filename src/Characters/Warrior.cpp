#include "../../lib/Characters/Warrior.hpp"
using namespace std;
#include<iostream>
#include<string>

Warrior::Warrior(string name) : Player::Player(name){
    // Declare the increment
    int hpInc,defInc,atkInc;
    hpInc =  defInc = 10;
    atkInc = 5;

    // Declare the base stat(Hp, Def, Atk = 100 at LV1)
    this->setIncrmnts(hpInc, defInc, atkInc);

    int baseStats = 100;
    this->setHealth(baseStats);
    this->setDefense(baseStats);
    this->setAttack(baseStats);
}

    //Strike is normal attack.
void Warrior::strike(Enemy *e) {
    cout << this->getName() << " used strikee on " << e->getName() << "." << endl;
    e->takeDamage(this->getAttack());
}

void Warrior::heavyStrike(Enemy *e) {
    //Only bonus after strike(Not implemented)
    double multiplier = 1.5;
    cout << this->getName() << " used heavy strike on " << e->getName() << "." << endl;
    e->takeDamage(this->getAttack() * multiplier);
}

void Warrior::warCry() {
    int warCry = 2;
    this->setAttack(warCry * this->getAttack());
    cout << this->getName() << " used War Cry, you gained double attack in next three terms." << endl;
}

void Warrior::stormStrike(Enemy *e) {
    //Only bonus after heavy strike(Not implemented)
    int bonus = 2;
    cout << this->getName() << " used storm strike on " << e->getName() << "." << endl;
    e->takeDamage(this->getAttack() * bonus);
}

void Warrior::bloodDraining() {
    double drain = 0.2;
    //in next 6 turns(Not implemented):
    this->setHealth(this->getHealth() + drain * this->getAttack());
    cout << this->getName() << " used bloodDraining, you gained  health from your attack." << endl;
}

void Warrior::rageBurst() {
    //Only can when rage bar is half or above and cosume half of rage bar after using skill(Not implemented)

}

void Warrior::taunt(Enemy *e) {
    //Not implemented yet.
}

void Warrior::heartOfAWarrior() {
    //in 5 turns:
    this->setHealth(1.2 * (this->getHealth() + this->getLevel() * hpIncrmnt));
    cout << this->getName() << " used heart of a warrior, increase 20% hp limit and regenerate 5% of hp in battle for 5 turns." << endl;
    
}

void Warrior::unstoppableFury() {
    //in 5 turns:
    if(this->getHealth() <= 0){
        this->setHealth(1);
    }
    rageBar = 100;
    cout << this->getName() << " used unstoppable fury, you won't die in next 5 rounds and your rage bar is full." << endl;
}

void Warrior::letTamBleed(Enemy *e){
    //in 10 turns:
    double bleed = 0.3;
    e->takeDamage(this->getAttack() * bleed);
    cout << this->getName() << " used let them bleed, you will gain health from your attack." << endl;
}

void Warrior::doomOfTheEnemy(Enemy *e){
    int doom = 4;
    if(rageBar >= 99){
        e->takeDamage(this->getAttack() * doom);
        cout << this->getName() << " used let them doom of enemy on " << e->getName() << endl;
    }
    else{
        cout << "Don't have enough rage bar to use the skill." << endl;
    }
}

void Warrior::listSkills(ostream &){}

int Warrior::selectSkill(){
    return 1;
}

void Warrior::useSkillOn(int skill, Enemy *e){

}

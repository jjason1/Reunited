#include "../lib/Characters/Character.hpp"
#include "../lib/Chapters/Chapter1Part1.hpp"
#include "../lib/Combat.hpp"
#include "../lib/Enemies/Bandit.hpp"
#include "../lib/Characters/PlayerTeam.hpp"
#include "../lib/Enemies/EnemyTeam.hpp"
#include "../lib/checkInput.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <istream>
#include <ostream>
#include <pthread.h>
#include <string>
#include <vector>
using std::endl;
using std::ostream;
using std::string;

void Chapter1Part1::option1Part1Sub1() {

  out << "[Select Option]" << endl;
  out << "1.  Stop right there, don\'t go anywhere near that girl!" << endl
      << "(Silently approach the bandit.)"
      << endl;
  getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "Please input again" << endl;
    getline(in, input);
    checkInput(in);
  }
}




void Chapter1Part1::runChapter1Part1Sub2() {
  out << "Chapter1.1" << endl;
  out << endl;
  out << "System: Our journey begins in a land ravaged by the cruel hands of "
         "war. You and your sister, Annie, are currently escaping from the "
         "war-torn land. After several days of running, you find yourself "
         "standing in the heart of a dense forest."
      << endl;
  out << endl;
  out << "Annie: Where are we going? Is there any town or city nearby?" << endl;
  out << "You: Hopefully we can find a safer place for us to rest. There "
         "should be a town not too far away."
      << endl;
  out << endl;
  out << "System: Suddenly, you hear a strange voice calling out for help, "
         "deeper into the forest. The shouting gets louder..."
      << endl;
  out << endl;
  out << "You: Stay here Annie. I\'ll go check out where the shouting is coming "
         "from. They may be in danger."
      << endl;
  out << endl;
  out << "System: As you begin making your way towards the direction of the "
         "shouting, you\'re stopped in your tracks by a blurry figure. "
         "(Preventing you from going any further.)"
      << endl;
  out << "No one is going to help you hehe! (The bandit lick his blade and no "
         "one knows what he is going to do next)"
      << endl;
  out << endl;
  out << "Bandit: No one is going to help you this deep into the forest! Your "
         "curiosity will be the end of you! (The bandit licks his blade as he "
         "considers his next move.)"
      << endl;
  out << endl;
  out << "System: Just beyond the bandit, you make out the figure of a bruised "
         "girl in need of help."
      << endl;
  out << endl;

  option1Part1Sub1();

  out << endl;
  out << "Bandit: What the hell are you gonna do? I\'ll slaughter you all if "
         "it’s the last thing I do!"
      << endl;
  out << endl;
  out << "System: You encounter a bandit.";
  out << endl;

  playerHp = player->getHealth(); //  record the hp before fight
  vector<Character *> team{player};
  PlayerTeam * playerTeam = new PlayerTeam(team, out, in);

  Bandit *bandit = new Bandit("Bandit", player->getLevel());
  vector<Character *> enemies{bandit};
  EnemyTeam * enemyTeam = new EnemyTeam(enemies, out);


  Combat *c = new Combat(playerTeam, enemyTeam, out, in);
  c->startBattle();

  player->setHealth(playerHp); // restore health after fight

  for (int i = 0; i< 4; i++) { // level up four times to level 5
    player->levelUp();
  }
  
}
#include "../lib/Characters/Character.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../lib/Chapters/Chapter1Part3.hpp"
#include "../lib/Combat.hpp"
#include "../lib/Enemies/Bandit.hpp"
#include "../lib/Characters/PlayerTeam.hpp"
#include "../lib/Enemies/EnemyTeam.hpp"
#include "../lib/checkInput.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using std::ostream;
using std::string;

Chapter1Part3::Chapter1Part3(Character *player, std::ostream &outout,
                             std::istream &inin)
    : SubChapter(player, outout, inin) {
  name = "Chapter1Part3";
  playerHp = 0;
}

void Chapter1Part3::runChapter1Part3Sub1() {
  out << "System: The town\'s alarm bell rings. It only rings when enemies "
         "approach. You see Rosaline run towards you."
      << endl;
  out << endl;
  out << "Rosaline: We need to hurry! Our patrol soldier found some bandits "
         "that have infiltrated our town. We are shorthanded right now; could "
         "you help me and our town again? "
      << endl;
  out << endl;
  out << "Annie: Sure! My brother will definitely help you." << endl;
  out << endl;
  out << "You: 1. You can count on me. " << endl;
  out << "2.There seems to be no choice.We are surrounded by bandits right now."
      << endl;
  out << endl;
  getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "Please input again" << endl;
    getline(in, input);
    checkInput(in);
  }

  out << "Arrogant Bandit: Finished talking? Give me everything you have! "
         "Today I\'m in a good mood, so there\'s a chance I\'ll leave you "
         "alive."
      << endl;
  out << endl;
  out << "You: No, don\'t you dare touch my sister and friend." << endl;
  out << endl;
  out << "Arrogant Bandit: Now, you\'ve ruined my mood! Let this be your last "
         "lesson! Kill them, brothers."
      << endl;

  playerHp = player->getHealth(); //  record the hp before fight
  Mage *rosaline = new Mage("Rosaline");
  for (int i = 0; i < player->getLevel(); i++) {
    rosaline->levelUp();
  }

  vector<Character *> team{player, rosaline};
  PlayerTeam * playerTeam = new PlayerTeam(team, out, in);

  Bandit *Abandit = new Bandit("Arrogant Bandit", player->getLevel());
  Bandit *bandit2 = new Bandit("Bandit2", player->getLevel());
  Bandit *bandit3 = new Bandit("Bandit3", player->getLevel());
  vector<Character *> enemies{Abandit, bandit2, bandit3};
  EnemyTeam * enemyTeam = new EnemyTeam(enemies, out);


  Combat *c = new Combat(playerTeam, enemyTeam, out, in);
  c->startBattle();

  player->setHealth(playerHp); // restore health after fight

  for (int i = 0; i< 4; i++) { // level up four times
    player->levelUp();
  }
}

void Chapter1Part3::runChapter1Part3Sub2() {
  out << "Rosaline: We did it… I still can\'t believe it… We saved the town "
         "from these bandits."
      << endl;
  out << endl;
  out << "Town Mayor: Thank you so much. I can\'t imagine what would have "
         "happened had you all not been here."
      << endl;
  out << endl;
  out << "Patrol soldier: I\'ve got urgent news to share with you, Mayor. This "
         "seems to be just the beginning of their attacks; their main attack "
         "unit is on their way to our town as we speak."
      << endl;
  out << endl;
  out << "Annie: What should we do right now?" << endl;
  out << "Town Mayor: We should first improve our town\'s defense and gather "
         "our fighters to prepare for the incoming battle. Can we ask you for "
         "one last favor?"
      << endl;
  out << endl;
  out << "Rosaline: If I may, Mayor. I don\'t think we should stay here and "
         "wait for them to attack. I believe we\'d have better chances if we "
         "ambushed them. I\'m sure they\'re underestimating us townsfolk, so "
         "we "
         "can take advantage of their weakness."
      << endl;
  out << endl;
  out << "Town Mayor: That\'s a great idea; let\'s move forward with that plan "
         "then. After you finish helping build the town\'s defense, proceed "
         "with the others to attack their left flank."
      << endl;
  out << endl;
  out << "You: Understood." << endl;
  out << endl;
  out << "Rosaline: Sounds great. This is my hometown, and I don\'t want to "
         "lose it. Let\'s get moving, everyone! We have no time to waste."
      << endl;
  out << endl;
  out << "System: You reach the town\'s outermost walls and help strengthen "
         "the "
         "defense facility."
      << endl;
  out << endl;
  out << "Rosaline:  Our defense seems to be ready now. Annie, stay here in "
         "the town and " << player->getName() << ", come with me."
      << endl;
  out << endl;
  out << "You: 1. I\'m ready." << endl;
  out << "You: 2. I\'m not ready yet…" << endl;
  getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "Please input again" << endl;
    getline(in, input);
    checkInput(in);
  }
  out << endl;
  out << "System: You follow Rosaline through a concealed route, shrouded by "
         "trees and rubble. You can faintly hear some people talking in the "
         "distance."
      << endl;
  out << endl;
  out << "Bandit A: I can\'t wait to ravage the town. What are y\'all going to "
         "do after we murder their fighters?"
      << endl;
  out << endl;
  out << "Bandit B: Drink their alcohol and ransack their homes! It\'s time "
         "for "
         "some fun!"
      << endl;
  out << endl;
  out << "Bandit C: I\'m down! Let\'s lay this town to waste!" << endl;
  out << "Bandit D: Silence! This is war… we must move on and take this "
         "seriously."
      << endl;
  out << endl;
  out << "Rosaline: (Whispering) That must be their main attack unit. They\'re "
         "in for a surprise..."
      << endl;
  out << endl;
  out << "System: You silently approach one of the bandits and deal a critical "
         "blow to them."
      << endl;
  out << endl;
  out << "Unfortunate bandit: Ah! They\'re ambushing us!" << endl;
  out << endl;
  out << "Bandit D: What are you guys staring at! Attack!" << endl;
  out << endl;
  out << "System: You encounter a group of bandits." << endl;
  out << endl;

  playerHp = player->getHealth(); //  record the hp before fight
  Mage *rosaline = new Mage("Rosaline");
  for (int i = 0; i < player->getLevel(); i++) { // sync rosaline's level to player
    rosaline->levelUp();
  }

  vector<Character *> team{player, rosaline};
  PlayerTeam * playerTeam = new PlayerTeam(team, out, in);

  Bandit *banditA = new Bandit("Bandit A", player->getLevel());
  Bandit *banditB = new Bandit("Bandit B", player->getLevel());
  Bandit *banditC = new Bandit("Bandit C", player->getLevel());
  Bandit *banditD = new Bandit("Bandit D", player->getLevel());
  vector<Character *> enemies{banditA, banditB, banditC, banditD};
  EnemyTeam * enemyTeam = new EnemyTeam(enemies, out);


  Combat *c = new Combat(playerTeam, enemyTeam, out, in);
  c->startBattle();

  player->setHealth(playerHp); // restore health after fight

  for (int i = 0; i< 4; i++) { // level up four times
    player->levelUp();
  }
}

void Chapter1Part3::runChapter1Part3Sub3() {
  out << "Rosaline: … We finally won! It wouldn\'t have been as easy if we "
         "didn\'t plan ahead to ambush them. "
      << endl;
  out << endl;
  out << "You:" << endl;
  out << "1. They weren\'t much of a challenge. This couldn\'t have been their "
         "main attack unit…"
      << endl;
  out << "2. I think we should retreat and report back to the Mayor." << endl;
  getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "Please input again" << endl;
    getline(in, input);
    checkInput(in);
  }
  out << endl;
  out << "Bandit Captain: Where do you think you\'re going? This is just the "
         "beginning. Attack!"
      << endl;
  out << endl;
  out << "System: You turn around. In front of you lies another wave of "
         "bandits. You encounter a second wave of bandits."
      << endl;
  out << endl;


  playerHp = player->getHealth(); //  record the hp before fight
  Mage *rosaline = new Mage("Rosaline");
  for (int i = 0; i < player->getLevel(); i++) { // sync rosaline's level to player
    rosaline->levelUp();
  }

  vector<Character *> team{player, rosaline};
  PlayerTeam * playerTeam = new PlayerTeam(team, out, in);

  Bandit *banditA = new Bandit("Bandit A", player->getLevel());
  Bandit *banditB = new Bandit("Bandit B", player->getLevel());
  Bandit *banditC = new Bandit("Bandit C", player->getLevel());
  Bandit *banditD = new Bandit("Bandit D", player->getLevel());
  vector<Character *> enemies{banditA, banditB, banditC, banditD};
  EnemyTeam * enemyTeam = new EnemyTeam(enemies, out);


  Combat *c = new Combat(playerTeam, enemyTeam, out, in);
  c->startBattle();

  player->setHealth(playerHp); // restore health after fight

  for (int i = 0; i< 4; i++) { // level up four times
    player->levelUp();
  }
}

void Chapter1Part3::runChapter1Part3Sub4() {
  out << "System: You taste victory. However, the sounds of your fighting "
         "attracted more unwanted attention. You find yourself completely "
         "surrounded by bandits."
      << endl;
  out << endl;
  out << "Bandit Leader: Put down your weapon, and I\'ll consider giving you a "
         "painless death."
      << endl;
  out << endl;
  out << "Rosaline: We aren\'t going to give up that easily. Victory belongs "
         "to "
         "the last man standing, and that will be "
      << player->getName() << ". " << endl;
  out << endl;
  out << "You: " << endl;
  out << "1. Come at me! No matter how many bandits I face, we will still "
         "leave victorious!"
      << endl;
  out << "2. I\'ll see you all in Hell! It isn\'t my time just yet…" << endl;
  out << endl;
  out << "Bandit Leader: You don\'t seem to understand your current position. "
         "I "
         "am going to torture you until you surrender. You will wish you had "
         "begged me for a painless death earlier."
      << endl;
  out << endl;
  out << "System: You encounter a third group of bandits, led by a Bandit "
         "leader."
      << endl;
  out << endl;

  
  playerHp = player->getHealth(); //  record the hp before fight
  Mage *rosaline = new Mage("Rosaline");
  for (int i = 0; i < player->getLevel(); i++) { // sync rosaline's level to player
    rosaline->levelUp();
  }

  vector<Character *> team{player, rosaline};
  PlayerTeam * playerTeam = new PlayerTeam(team, out, in);

  Bandit *banditA = new Bandit("Bandit A", player->getLevel());
  Bandit *banditB = new Bandit("Bandit B", player->getLevel());
  Bandit *banditC = new Bandit("Bandit C", player->getLevel());
  Bandit *banditD = new Bandit("Bandit Boss", player->getLevel());
  vector<Character *> enemies{banditA, banditB, banditC, banditD};
  EnemyTeam * enemyTeam = new EnemyTeam(enemies, out);


  Combat *c = new Combat(playerTeam, enemyTeam, out, in);
  c->startBattle();

  player->setHealth(playerHp); // restore health after fight

  for (int i = 0; i< 4; i++) { // level up four times
    player->levelUp();
  }
}

void Chapter1Part3::runChapter1Part3Sub5() {
  
}

void Chapter1Part3::runSubChapter() {
  runChapter1Part3Sub1();
  runChapter1Part3Sub2();
  runChapter1Part3Sub3();
  runChapter1Part3Sub4();
  runChapter1Part3Sub5();
      
}
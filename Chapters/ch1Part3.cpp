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
  out<<"\nChapter 1.3:"<<endl<<endl;
  out << "System: The town\'s alarm bell rings. It only rings when enemies "
         "approach. You see Rosaline run towards you."
      << endl;
  out << endl;
  out << "Rosaline: We need to hurry! Our patrol soldier found some bandits "
         "that have infiltrated our town. We are shorthanded right now; could "
         "you help me and our town again? "
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
  getline(in,input);
  in.clear();
  out << "Annie: Sure! My brother will definitely help you." << endl;
  out << endl;
  out << "You:\n1. You can count on me. " << endl;
  out << "2.There seems to be no choice. We are surrounded by bandits right now."
      << endl;
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
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();

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
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
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
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
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
  out << "You:\n1. I\'m ready." << endl;
  out << "2. I\'m not ready yet…" << endl;
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
  out << "\nBandit D: Silence! This is war… we must move on and take this "
         "seriously."
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
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
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();

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
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
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
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
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
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
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
  getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "Please input again" << endl;
    getline(in, input);
    checkInput(in);
  }

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

  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
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
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "Frightened Bandit: Our boss isn\'t breathing… Is he dead? We\'re no "
         "match for them. Run!"
      << endl;
  out << endl;
  out << "Bandit: I don\'t want to die." << endl;
  out << endl;
  out << "System: Some bandits start to run away. After some bandits flee, the "
         "rest of the bandits follow in suit."
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "Rosaline: Seems like they\'ve all left. I am exhausted right now. We "
         "should report back to the Mayor and get some rest."
      << endl;
  out << endl;
  out << "You:" << endl;
  out << "1. I could use some food; I\'m starving from all of this action."
      << endl;
  out << "2. I want to go back and make sure my sister is fine." << endl;
  getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "Please input again" << endl;
    getline(in, input);
    checkInput(in);
  }
  out << endl;
  out << "Rosaline: Ok, let\'s go." << endl;
  out << endl;
  out << "System: You return back to Town Broco. The fight in town has also "
         "come to an end. Everyone rushes to you and Rosaline."
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "Mayor: Hey Rosaline and “Your Name”, how\'d it go? The bandits "
         "suddenly started fleeing after hearing about the death of their "
         "leader. They\'re boss never showed up; did you defeat their leader?"
      << endl;
  out << endl;
  out << "Rosaline: Yes, although we planned to attack their left flank, we "
         "ended up encountering the bandit leader and fought against them. And "
         "the rest is history!"
      << endl;
  out << endl;
  out << "Mayor: How did you even manage to fight them off, despite being "
         "outnumbered? You\'re both heroes of our town. We must celebrate your "
         "victory and let this town fill with the shouts of our freedom! I’ll "
         "share the wonderful news to the entire town. Head over to the bar to "
         "get this celebration started."
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "Rosaline: Ok, see you." << endl;
  out << endl;
  out << "You:  See you later." << endl;
  out << endl;
  out << "System: You go to the inn and wait for all of the townsfolk to "
         "arrive."
      << endl;
  out << endl;
  out << "Enthusiastic Adventurer: If it isn\'t our heroes? You are stronger "
         "than I could have imagined. Anyway, let\'s toast to OUR HEROES!"
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "System: The townsfolk all chug their drinks to show you their "
         "respect and appreciation."
      << endl;
  out << endl;
  out << "You:" << endl;
  out << "1. It wasn\'t a big deal. Let\'s cut the talking and start the "
         "celebration!"
      << endl;
  out << "2. You all did a great job in defending our town!" << endl;
  getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "Please input again" << endl;
    getline(in, input);
    checkInput(in);
  }
  out << endl;
  out << "Annie: You came back. Are you hurt at all?  I was worried about you "
         "the entire time, and I was praying for your victory. I didn\'t want "
         "to lose you after already losing everything."
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "You: Thank you Annie for always watching over me. I\'m not hurt at "
         "all, but we encountered more enemies than we could\'ve anticipated. "
         "Keeping you all safe pushed me to fight my best."
      << endl;
  out << endl;
  out << "Rosaline: "<<player->getName()<<" fights pretty well. He is the true hero of "
         "this town. I will forever be indebted to “Your Name” for keeping my "
         "treasure, my hometown, safe."
      << endl;
  out << endl;
  out << "Annie: You can always count on " << player->getName() << "." << endl;
  out << "System: You celebrate your victory throughout the night, talking and "
         "laughing with the townsfolk. Everything seems to be in order, or so "
         "it seems. As dawn approaches, a worrying message comes your way."
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "Soldier?: Report! Our city, Dicving, needs your town\'s support. The "
         "goblins surrounding our city are getting more aggressive, and we "
         "cannot hold them back any longer. Most of our soldiers are wounded "
         "or exhausted; our situation is looking dire."
      << endl;
  out << endl;
  out << "Mayor: Oh no! We need to address this immediately. From what I\'ve "
         "experienced, goblins are an atrocious species that only aims to "
         "destroy and ravage human society. We have to help them, or the "
         "goblins will only get stronger. If they destroy Dicving, our town "
         "might be next… Thankfully, I think the bandits have been weakened "
         "and are not going to attack our town for the time being. The people "
         "of Dicving need your help, just as much as we do."
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "Rosaline: What do you think, " << player->getName() << "?" << endl;
  out << endl;
  out << "You: " << endl;
  out << "1. I think we should help them. I don\'t want anyone to suffer from "
         "wars anymore."
      << endl;
  getline(in, input);
  checkInput(in);
  while (input != "1" && input != "2") {
    out << "Please input again" << endl;
    getline(in, input);
    checkInput(in);
  }
  out << endl;
  out << "Annie: " << player->getName()
      << " is this town\'s hero. And heroes always help those in need right?"
      << endl;
  out << endl;
  out << "Rosaline: We\'ve made our decision. We are going to leave this town "
         "tomorrow to save the city of Dicving."
      << endl;
  out << endl;
  out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();
  out << "Dicving Soldier: I sincerely thank you, heroes. I will lead you to "
         "our city tomorrow. Take the rest of the day to prepare for our "
         "journey."
      << endl;
  out << endl;
  out << "Rosaline: Ok, we\'ll meet back with you tomorrow." << endl;
  out << endl;
  out << "You: Bye." << endl;
  out << endl;
  out << "System: Chapter 1 has concluded." << endl;
  out << endl;
}

void Chapter1Part3::runSubChapter() {
  runChapter1Part3Sub1();
  runChapter1Part3Sub2();
  runChapter1Part3Sub3();
  runChapter1Part3Sub4();
  runChapter1Part3Sub5();
      
}
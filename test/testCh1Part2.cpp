#include "../lib/Chapters/Chapter1Part1.hpp"
#include "../Chapters/ch1Part2Sub1.cpp"
#include "../Chapters/ch1Part2Sub2.cpp"
#include "../Chapters/ch1Part2.cpp"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST(TestCH1Part2Suite, testConstructor){
    Character *c = new Character("test");
    EXPECT_NO_THROW(new Chapter1Part2(c, cout, cin));
    Chapter1Part2 *ch12 = new Chapter1Part2(c, cout, cin);
    
    EXPECT_EQ(ch12->getName(), "Chapter1Part2");
    EXPECT_EQ(ch12->getInput(), "");
}

TEST(TestCH1Part2Suite, testOption1){
    stringstream testIn;
    stringstream testOut;
    stringstream out;
    testIn<<"1"<<endl;
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;  
    out<<"1. Of course, you can count on me!\n";
    out<<"2. My strength doesn\'t come for free. Make sure you pay us well for our time.\n";
    out<<"\nSystem: You earn the favor of the townsfolk. As a result, you level up.\n"<<endl;

    ch12->option1();

    EXPECT_EQ(c->getLevel(),2);
    EXPECT_EQ(testOut.str(),out.str());
}

TEST(TestCH1Part2Suite, testOption2){
    stringstream testIn;
    stringstream testOut;
    stringstream out;
    testIn<<"1"<<endl;
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Walk up to the inn.)\n\n";

    ch12->option2();

    EXPECT_EQ(testOut.str(),out.str());
}

TEST(TestCH1Part2Suite, testOption3){
    stringstream testIn;
    stringstream testOut;
    stringstream out;
    testIn<<"1"<<endl;
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Enter the inn.)\n\n";

    ch12->option3();

    EXPECT_EQ(testOut.str(),out.str());
}

TEST(TestCH1Part2Suite, testOption4){
    stringstream testIn;
    stringstream testOut;
    stringstream out;
    testIn<<"1"<<endl;
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Feeling hungry yourself, you decide to try the corn soup.)\n\n";

    ch12->option4();

    EXPECT_EQ(testOut.str(),out.str());
}

TEST(TestCH1Part2Suite, testOption5){
    stringstream testIn;
    stringstream testOut;
    stringstream out;
    testIn<<"1"<<endl;
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. Can I please have one more serving?\n\n";

    ch12->option5();

    EXPECT_EQ(testOut.str(),out.str());
}

TEST(TestCH1Part2Suite, testOption6){
    stringstream testIn;
    stringstream testOut;
    stringstream out;
    testIn<<"2"<<endl;
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Call it a day.)\n";
    out<<"2. (Stay up a little longer before heading to bed.)\n";
    out<<"\nSystem: You stay up a little longer to train before bed. As a result, "
         "you level up one level.\n\n";

    ch12->option6();

    EXPECT_EQ(c->getLevel(),2);
    EXPECT_EQ(testOut.str(),out.str());
}

TEST(TestCH1Part2Suite, testCh1Part2Sub1WithOption1){
    stringstream testOut;
    stringstream testIn;
    testIn<<"1"<<endl;
    stringstream out;
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);

    out<<"\nChapter 1.2:"<<endl<<endl;
    out<<"Stranger: You were amazing! Thank you for saving my life.\n"<<endl;

    out<<"You: I\'m glad we could make it in time to help you. " 
         "Who are you, and where did you come from?\n"<<endl;

    out<<"Stranger: My name is Rosaline, and I\'m a student at the Magic Academy "
         "in the town close to this forest, Broco.\n"<<endl;

    out<<"Annie: What a coincidence! We were looking for a nearby town. " 
         "Would you be able to guide us to Town Broco?\n"<<endl;

    out<<"Rosaline: Absolutely, I can guide you both there and even give you two a tour " 
         "to thank you for your help!\n"<<endl;

    out<<"System: Guided by Rosaline, you find and safely enter Town Broco.\n"<<endl;

    out<<"Annie: Why does the town look so dead? What happened here?\n"<<endl;

    out<<"Rosaline: There is an abandoned castle that houses some bandits and serves "
         "as their base. They regularly raid the town. After the town\'s hero passed away "
         "a few years prior, most residents left, as they no longer had any protection "
         "from the bandits. This town can no longer maintain its defenses against the bandits.\n"<<endl;

    out<<"Annie: What a pity, is there anything we can do to help this town regain its life? " 
    "I\'d love to see this town filled with life and warmth again because it is dear to you and all of the other townsfolk.\n"<<endl;

    out<<"Rosaline: I\'d be happy to introduce you to some strong people who still live here. "
    "Maybe we could work together to figure out a plan to save my hometown.\n"<<endl;

    out<<"Annie: Sure, we can\'t wait to meet them.\n"<<endl;

    out<<"System: Rosaline brings you to an old bar.\n"<<endl;

    out<<"Rosaline: Here is the guild\'s bar, where you\'ll find the folks who chose to stay here. "
    "This is usually where you\'ll find the strongest individuals of our town talking amongst themselves.\n"<<endl;

    out<<"System: You step into the bar and find it to be nearly empty. Only one young guy is seated in the corner of the room.\n"<<endl;

    out<<"Enthusiastic Adventurer: We finally have some guests here! The drinks seem to be getting worse, " 
    "so I could use some company instead…\n"<<endl;

    out<<"You: Sorry, I\'m not here for a drink. I came to this bar to gather some intel and support. "
    "I\'d like to help Rosaline and the town out, but I\'ll need help from all of the townsfolk. "
    "Are there any others who are able to fight besides you?\n"<<endl;

    out<<"Enthusiastic Adventurer: It\'s obvious that everyone left already. Nobody wants to stay in a dangerous "
    "and miserable town. But… you may be in luck if you head to the mayor\'s house. "
    "He's the only one still organizing and trying to maintain the town\'s defense.\n"<<endl;

    out<<"Rosaline: Thank you for the information. We need all the help we can find! Would you be willing to join our team for our cause?\n"<<endl;

    out<<"Enthusiastic Adventurer: I\'d take you up on your invitation, but my knee was injured "
    "during my last fight. It seems I\'ll be sticking around until I heal my wounds. Good luck to you all. "
    "I really do hope that you find success in your journey. We may be able to share drinks one day… when hope returns back to this town.\n"<<endl;

    out<<"You: Take care!\n"<<endl;

    out<<"System: You all exit the bar and start planning your next destination.\n"<<endl;

    out<<"Rosaline: Where should we head now? Oh, maybe we should visit the mayor's house to let him "
    "know about our plan and to ask for help.\n"<<endl;

    out<<"Annie: What does the mayor look like? How will we recognize him?\n"<<endl;

    out<<"Rosaline: He is a short, old man with gray hair and a small beard. "
    "He\'s known for his radiating kindness. He isn\'t too difficult to spot, so I\'m sure we\'ll be able to recognize him right away.\n"<<endl;

    out<<"Annie: I think we\'re ready! Show us the way, Rosaline.\n"<<endl;

    out<<"You: I agree, let\'s make our way to the mayor\'s house now.\n"<<endl;

    out<<"Rosaline: Ok, follow me.\n"<<endl;

    out<<"System: After following Rosaline for some time, you finally reach the mayor\'s house. "
    "As you walk up to it, you see the mayor outside, watering his flowers. He notices your group approaching him.\n"<<endl;

    out<<"Mayor: If it isn\'t Rosaline. What brings you here? You even brought others with you. "
    "I don\'t think you came just to see me right?\n"<<endl;

    out<<"Rosaline: Don\'t say that. We are all grateful for your service to this town. "
    "I wanted to introduce you to our new guests. This is test and this is test's sister, Annie. "
    "test is really talented at fighting; I witnessed test's skill in person. After hearing about our situation, "
    "they insisted on helping you protect this town.\n"<<endl;

    out<<"System: Rosaline points to you and your sister as she introduces you to the mayor.\n"<<endl;

    out<<"Mayor: Oh, that would help out immensely as we no longer have the strength to guard and protect "
    "our town anymore. Could I really rely on you to defend our town? All you need to do is come to the center "
    "of this town when the tower bell rings. After that, I\'ll leave the rest to you.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;  
    out<<"1. Of course, you can count on me!\n";
    out<<"2. My strength doesn\'t come for free. Make sure you pay us well for our time.\n";
    out<<"\nSystem: You earn the favor of the townsfolk. As a result, you level up.\n"<<endl;

    EXPECT_NO_THROW(ch12->runChapter1Part2Sub1());
    EXPECT_EQ( testOut.str(), out.str());
}

TEST(TestCH1Part2Suite, testCh1Part2Sub2){
    stringstream testOut;
    stringstream testIn;
    stringstream out; 
    testIn<<"1"<<endl; //for option2
    testIn<<"1"<<endl; //for option3
    testIn<<"1"<<endl; //for option4
    testIn<<"1"<<endl; //for option5
    testIn<<"2"<<endl; //for option6
    
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);

     out<<"Mayor: Thank you on behalf of myself and all of the townsfolk! "
    "I still have some business to do after I finish watering my flowers. In the meantime, "
    "head over to the inn to get some rest. With nightfall coming, you need to rest to "
    "build up your strength before we put our plan into action.\n"<<endl;

    out<<"Rosaline: I will show them the way to the inn. Goodbye, Mayor. We\'ll meet again soon.\n"<<endl;

    out<<"System: You all leave the Mayor\'s house and start walking towards the "
    "inn. With every step you all take, the sky gets darker and your paths darken.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Walk up to the inn.)\n\n";

    out<<"System: You all reach the inn before midnight.\n"<<endl;

    out<<"Rosaline: Here is our town\'s only inn. Although it's "
    "shabby and on its last leg, the food and people are great, especially "
    "the soup here. Come on in!\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Enter the inn.)\n\n";

    out<<"System: You enter the inn and are welcomed in with warmth.\n"<<endl;

    out<<"Boss: Come in and have a seat! You all must be tired and hungry right now. "
    "Would any of you like some fresh corn soup our inn prepared?\n"<<endl;

    out<<"Annie: Absolutely! I am so hungry right now.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Feeling hungry yourself, you decide to try the corn soup.)\n\n";

    out<<"Boss: Coming right up!\n"<<endl;

    out<<"System: (You find out it tastes amazing, and you want one more serving.)\n"<<endl; 

    out<<"You: This soup tastes amazing! Thank you for your hospitality and kindness.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. Can I please have one more serving?\n\n";

    out<<"Rosaline: I knew you would like it. It fills you with energy immediately.\n"<<endl;

    out<<"Boss: If you\'d like more, let me know! There\'s more where that came from.\n"<<endl;

    out<<"System: You keep eating until you become full, and now it is time to get some rest.\n"<<endl;

    out<<"Boss: The mayor already paid me your fee and rent to live here. "
    "Your room is just up the stairs.\n"<<endl;

    out<<"Rosaline: Alright, it\'s been a pleasure guiding you both around town. "
    "I have to go home now to prepare for tomorrow. I can\'t thank you both enough "
    "for all that you\'ve done for me. Now\'s the time to rest, but we\'ll meet again tomorrow.\n"<<endl;

    out<<"System: Rosaline leaves the inn. Feeling exhausted from your trip, you "
    "and Annie also decide it\'s time to get some sleep.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Call it a day.)\n";
    out<<"2. (Stay up a little longer before heading to bed.)\n\n";
    out<<"System: You stay up a little longer to train before bed. As a result, "
         "you level up one level.\n\n";
 
    EXPECT_NO_THROW(ch12->runChapter1Part2Sub2());
    EXPECT_EQ(c->getLevel(),2);   
    EXPECT_EQ( testOut.str(), out.str());
}

TEST(TestCH1Part2Suite, testCh1Part2){
    stringstream testOut;
    stringstream testIn;
    stringstream out; 
    testIn<<"1"<<endl; //for option1
    testIn<<"1"<<endl; //for option2
    testIn<<"1"<<endl; //for option3
    testIn<<"1"<<endl; //for option4
    testIn<<"1"<<endl; //for option5
    testIn<<"2"<<endl; //for option6
    
    Character *c = new Character("test");
    Chapter1Part2 *ch12 = new Chapter1Part2(c, testOut, testIn);

    out<<"\nChapter 1.2:"<<endl<<endl;
    out<<"Stranger: You were amazing! Thank you for saving my life.\n"<<endl;

    out<<"You: I\'m glad we could make it in time to help you. " 
         "Who are you, and where did you come from?\n"<<endl;

    out<<"Stranger: My name is Rosaline, and I\'m a student at the Magic Academy "
         "in the town close to this forest, Broco.\n"<<endl;

    out<<"Annie: What a coincidence! We were looking for a nearby town. " 
         "Would you be able to guide us to Town Broco?\n"<<endl;

    out<<"Rosaline: Absolutely, I can guide you both there and even give you two a tour " 
         "to thank you for your help!\n"<<endl;

    out<<"System: Guided by Rosaline, you find and safely enter Town Broco.\n"<<endl;

    out<<"Annie: Why does the town look so dead? What happened here?\n"<<endl;

    out<<"Rosaline: There is an abandoned castle that houses some bandits and serves "
         "as their base. They regularly raid the town. After the town\'s hero passed away "
         "a few years prior, most residents left, as they no longer had any protection "
         "from the bandits. This town can no longer maintain its defenses against the bandits.\n"<<endl;

    out<<"Annie: What a pity, is there anything we can do to help this town regain its life? " 
    "I\'d love to see this town filled with life and warmth again because it is dear to you and all of the other townsfolk.\n"<<endl;

    out<<"Rosaline: I\'d be happy to introduce you to some strong people who still live here. "
    "Maybe we could work together to figure out a plan to save my hometown.\n"<<endl;

    out<<"Annie: Sure, we can\'t wait to meet them.\n"<<endl;

    out<<"System: Rosaline brings you to an old bar.\n"<<endl;

    out<<"Rosaline: Here is the guild\'s bar, where you\'ll find the folks who chose to stay here. "
    "This is usually where you\'ll find the strongest individuals of our town talking amongst themselves.\n"<<endl;

    out<<"System: You step into the bar and find it to be nearly empty. Only one young guy is seated in the corner of the room.\n"<<endl;

    out<<"Enthusiastic Adventurer: We finally have some guests here! The drinks seem to be getting worse, " 
    "so I could use some company instead…\n"<<endl;

    out<<"You: Sorry, I\'m not here for a drink. I came to this bar to gather some intel and support. "
    "I\'d like to help Rosaline and the town out, but I\'ll need help from all of the townsfolk. "
    "Are there any others who are able to fight besides you?\n"<<endl;

    out<<"Enthusiastic Adventurer: It\'s obvious that everyone left already. Nobody wants to stay in a dangerous "
    "and miserable town. But… you may be in luck if you head to the mayor\'s house. "
    "He's the only one still organizing and trying to maintain the town\'s defense.\n"<<endl;

    out<<"Rosaline: Thank you for the information. We need all the help we can find! Would you be willing to join our team for our cause?\n"<<endl;

    out<<"Enthusiastic Adventurer: I\'d take you up on your invitation, but my knee was injured "
    "during my last fight. It seems I\'ll be sticking around until I heal my wounds. Good luck to you all. "
    "I really do hope that you find success in your journey. We may be able to share drinks one day… when hope returns back to this town.\n"<<endl;

    out<<"You: Take care!\n"<<endl;

    out<<"System: You all exit the bar and start planning your next destination.\n"<<endl;

    out<<"Rosaline: Where should we head now? Oh, maybe we should visit the mayor's house to let him "
    "know about our plan and to ask for help.\n"<<endl;

    out<<"Annie: What does the mayor look like? How will we recognize him?\n"<<endl;

    out<<"Rosaline: He is a short, old man with gray hair and a small beard. "
    "He\'s known for his radiating kindness. He isn\'t too difficult to spot, so I\'m sure we\'ll be able to recognize him right away.\n"<<endl;

    out<<"Annie: I think we\'re ready! Show us the way, Rosaline.\n"<<endl;

    out<<"You: I agree, let\'s make our way to the mayor\'s house now.\n"<<endl;

    out<<"Rosaline: Ok, follow me.\n"<<endl;

    out<<"System: After following Rosaline for some time, you finally reach the mayor\'s house. "
    "As you walk up to it, you see the mayor outside, watering his flowers. He notices your group approaching him.\n"<<endl;

    out<<"Mayor: If it isn\'t Rosaline. What brings you here? You even brought others with you. "
    "I don\'t think you came just to see me right?\n"<<endl;

    out<<"Rosaline: Don\'t say that. We are all grateful for your service to this town. "
    "I wanted to introduce you to our new guests. This is test and this is test's sister, Annie. "
    "test is really talented at fighting; I witnessed test's skill in person. After hearing about our situation, "
    "they insisted on helping you protect this town.\n"<<endl;

    out<<"System: Rosaline points to you and your sister as she introduces you to the mayor.\n"<<endl;

    out<<"Mayor: Oh, that would help out immensely as we no longer have the strength to guard and protect "
    "our town anymore. Could I really rely on you to defend our town? All you need to do is come to the center "
    "of this town when the tower bell rings. After that, I\'ll leave the rest to you.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;  
    out<<"1. Of course, you can count on me!\n";
    out<<"2. My strength doesn\'t come for free. Make sure you pay us well for our time.\n";
    out<<"\nSystem: You earn the favor of the townsfolk. As a result, you level up.\n"<<endl;

    out<<"Mayor: Thank you on behalf of myself and all of the townsfolk! "
    "I still have some business to do after I finish watering my flowers. In the meantime, "
    "head over to the inn to get some rest. With nightfall coming, you need to rest to "
    "build up your strength before we put our plan into action.\n"<<endl;

    out<<"Rosaline: I will show them the way to the inn. Goodbye, Mayor. We\'ll meet again soon.\n"<<endl;

    out<<"System: You all leave the Mayor\'s house and start walking towards the "
    "inn. With every step you all take, the sky gets darker and your paths darken.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Walk up to the inn.)\n\n";

    out<<"System: You all reach the inn before midnight.\n"<<endl;

    out<<"Rosaline: Here is our town\'s only inn. Although it's "
    "shabby and on its last leg, the food and people are great, especially "
    "the soup here. Come on in!\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Enter the inn.)\n\n";

    out<<"System: You enter the inn and are welcomed in with warmth.\n"<<endl;

    out<<"Boss: Come in and have a seat! You all must be tired and hungry right now. "
    "Would any of you like some fresh corn soup our inn prepared?\n"<<endl;

    out<<"Annie: Absolutely! I am so hungry right now.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Feeling hungry yourself, you decide to try the corn soup.)\n\n";

    out<<"Boss: Coming right up!\n"<<endl;

    out<<"System: (You find out it tastes amazing, and you want one more serving.)\n"<<endl; 

    out<<"You: This soup tastes amazing! Thank you for your hospitality and kindness.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. Can I please have one more serving?\n\n";

    out<<"Rosaline: I knew you would like it. It fills you with energy immediately.\n"<<endl;

    out<<"Boss: If you\'d like more, let me know! There\'s more where that came from.\n"<<endl;

    out<<"System: You keep eating until you become full, and now it is time to get some rest.\n"<<endl;

    out<<"Boss: The mayor already paid me your fee and rent to live here. "
    "Your room is just up the stairs.\n"<<endl;

    out<<"Rosaline: Alright, it\'s been a pleasure guiding you both around town. "
    "I have to go home now to prepare for tomorrow. I can\'t thank you both enough "
    "for all that you\'ve done for me. Now\'s the time to rest, but we\'ll meet again tomorrow.\n"<<endl;

    out<<"System: Rosaline leaves the inn. Feeling exhausted from your trip, you "
    "and Annie also decide it\'s time to get some sleep.\n"<<endl;

    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Call it a day.)\n";
    out<<"2. (Stay up a little longer before heading to bed.)\n\n";
    out<<"System: You stay up a little longer to train before bed. As a result, "
         "you level up one level.\n\n";
 
    EXPECT_NO_THROW(ch12->runSubChapter());
    EXPECT_EQ(c->getLevel(),3); //leveled up from option 1 and 6.
    EXPECT_EQ( testOut.str(), out.str());
}


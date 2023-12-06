#include "../lib/Chapters/Chapter1Part2.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../lib/checkInput.h"

void Chapter1Part2::option1(){
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;  
    out<<"1. Of course, you can count on me!\n";
    out<<"2. My strength doesn\'t come for free. Make sure you pay us well for our time.\n";
    getline(in, input);
    checkInput(in);
    while (input != "1" && input != "2") {
        out << "Please input again:" << endl;
        getline(in, input);
        checkInput(in);
    }
    //If input=1, we level up the player. otherwise, we dont.
    if(input=="1"){
        out<<"\nSystem: You earn the favor of the townsfolk. As a result, you level up."<<endl;
        player->levelUp();
    }
    else out<<"\nSystem: You come off as arrogant and cause the townsfolk to worry more."<<endl;
    out<<endl;
}

void Chapter1Part2::runChapter1Part2Sub1(){
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

     out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();

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

     out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();

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
    "He\'s the only one still organizing and trying to maintain the town\'s defense.\n"<<endl;

     out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();

    out<<"Rosaline: Thank you for the information. We need all the help we can find! Would you be willing to join our team for our cause?\n"<<endl;

    out<<"Enthusiastic Adventurer: I\'d take you up on your invitation, but my knee was injured "
    "during my last fight. It seems I\'ll be sticking around until I heal my wounds. Good luck to you all. "
    "I really do hope that you find success in your journey. We may be able to share drinks one day… when hope returns back to this town.\n"<<endl;

    out<<"You: Take care!\n"<<endl;

    out<<"System: You all exit the bar and start planning your next destination.\n"<<endl;

    out<<"Rosaline: Where should we head now? Oh, maybe we should visit the mayor\'s house to let him "
    "know about our plan and to ask for help.\n"<<endl;

    out<<"Annie: What does the mayor look like? How will we recognize him?\n"<<endl;

     out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();

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
    "I wanted to introduce you to our new guests. This is "<<player->getName()<< " and this is "<<player->getName()<<"\'s sister, Annie. "
    <<player->getName()<<" is really talented at fighting; I witnessed "<<player->getName()<<"\'s skill in person. After hearing about our situation, "
    "they insisted on helping you protect this town.\n"<<endl;

    out<<"System: Rosaline points to you and your sister as she introduces you to the mayor.\n"<<endl;

     out<<"Press any key to continue...\n\n";
     getline(in,input);
     in.clear();

    out<<"Mayor: Oh, that would help out immensely as we no longer have the strength to guard and protect "
    "our town anymore. Could I really rely on you to defend our town? All you need to do is come to the center "
    "of this town when the tower bell rings. After that, I\'ll leave the rest to you.\n"<<endl;

    option1();

}
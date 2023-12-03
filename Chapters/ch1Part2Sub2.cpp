#include "../lib/Chapters/Chapter1Part2.hpp"
#include "../lib/Characters/Mage.hpp"
#include "../lib/Characters/Samurai.hpp"
#include "../lib/Characters/Warrior.hpp"
#include "../lib/checkInput.h"

void Chapter1Part2::option2(){
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Walk up to the inn.)\n";
    getline(in, input);
    checkInput(in);
    while (input != "1") {
        out << "Please input again:" << endl;
        getline(in, input);
        checkInput(in);
    }
    out<<endl;
}

void Chapter1Part2::option3(){
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Enter the inn.)\n";
    getline(in, input);
    checkInput(in);
    while (input != "1") {
        out << "Please input again:" << endl;
        getline(in, input);
        checkInput(in);
    }
    out<<endl;
}

void Chapter1Part2::option4(){
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Feeling hungry yourself, you decide to try the corn soup.)\n";
    getline(in, input);
    checkInput(in);
    while (input != "1") {
        out << "Please input again:" << endl;
        getline(in, input);
        checkInput(in);
    }
    out<<endl;
}

void Chapter1Part2::option5(){
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. Can I please have one more serving?\n";
    getline(in, input);
    checkInput(in);
    while (input != "1") {
        out << "Please input again:" << endl;
        getline(in, input);
        checkInput(in);
    }
    out<<endl;
}

void Chapter1Part2::option6(){
    out << "[Select Option]" << endl;
    out<<"You:"<<endl;
    out<<"1. (Call it a day.)\n";
    out<<"2. (Stay up a little longer before heading to bed.)\n";
    getline(in, input);
    checkInput(in);
    while (input != "1" && input != "2") {
        out << "Please input again:" << endl;
        getline(in, input);
        checkInput(in);
    }
    //If input=2, train a little and level up. Otherwise, we remain same level.
    if(input=="2"){
        out<<"\nSystem: You stay up a little longer to train before bed. As a result, "
             "you level up one level.\n";
        player->levelUp();
    }
    out<<endl;
}

void Chapter1Part2::runChapter1Part2Sub2(){
    out<<"Mayor: Thank you on behalf of myself and all of the townsfolk! "
    "I still have some business to do after I finish watering my flowers. In the meantime, "
    "head over to the inn to get some rest. With nightfall coming, you need to rest to "
    "build up your strength before we put our plan into action.\n"<<endl;

    out<<"Rosaline: I will show them the way to the inn. Goodbye, Mayor. We’ll meet again soon.\n"<<endl;

    out<<"System: You all leave the Mayor’s house and start walking towards the "
    "inn. With every step you all take, the sky gets darker and your paths darken.\n"<<endl;

    option2();

    out<<"System: You all reach the inn before midnight.\n"<<endl;

    out<<"Rosaline: Here is our town’s only inn. Although it's "
    "shabby and on its last leg, the food and people are great, especially "
    "the soup here. Come on in!\n"<<endl;

    option3();

    out<<"System: You enter the inn and are welcomed in with warmth.\n"<<endl;

    out<<"Boss: Come in and have a seat! You all must be tired and hungry right now. "
    "Would any of you like some fresh corn soup our inn prepared?\n"<<endl;

    out<<"Annie: Absolutely! I am so hungry right now.\n"<<endl;

    option4();

    out<<"Boss: Coming right up!\n"<<endl;

    out<<"System: (You find out it tastes amazing, and you want one more serving.)\n"<<endl; 

    out<<"You: This soup tastes amazing! Thank you for your hospitality and kindness.\n"<<endl;

    option5();

    out<<"Rosaline: I knew you would like it. It fills you with energy immediately.\n"<<endl;

    out<<"Boss: If you’d like more, let me know! There’s more where that came from.\n"<<endl;

    out<<"System: You keep eating until you become full, and now it is time to get some rest.\n"<<endl;

    out<<"Boss: The mayor already paid me your fee and rent to live here. "
    "Your room is just up the stairs.\n"<<endl;

    out<<"Rosaline: Alright, it’s been a pleasure guiding you both around town. "
    "I have to go home now to prepare for tomorrow. I can’t thank you both enough "
    "for all that you’ve done for me. Now’s the time to rest, but we’ll meet again tomorrow.\n"<<endl;

    out<<"System: Rosaline leaves the inn. Feeling exhausted from your trip, you "
    "and Annie also decide it’s time to get some sleep.\n"<<endl;


    option6();

}
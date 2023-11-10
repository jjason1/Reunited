#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "../src/Characters/Character.h"
#include "../src/Characters/Warrior.h"
#include "../src/Characters/Mage.h"
#include "../src/Characters/Samurai.h"
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::runtime_error;



void checkInput(std::istream &in)
{
    if (in.fail())
    {
        throw runtime_error("input failure.");
    }
}

void jobDescription(std::ostream &out)
{
    out << "w-Warrior" << endl;
    out << "Description: As a Warrior, your primary role is to be the stalwart \
    defender of your party, ensuring the safety of your comrades on the battlefield.\
     You are a master of defensive skills and tactics,\
      capable of withstanding even the most formidable foes.\
       Your unwavering dedication to protection makes you an \
       indispensable asset in any group."
        << endl;
    out << endl;
    out << "m-Mage" << endl;
    out << "Description: As a Mage, you possess a unique combination of magical prowess and balance in your abilities.\
     You harness the power of arcane energies to both damage enemies and support your allies.\
      Your adaptability and versatility in the arcane arts make you an invaluable addition\
       to any adventuring party."
        << endl;
    out << endl;
    out << "s-Samurai" << endl;
    out << "Description: The Samurai is a master of offense, wielding a blade with precision and skill.\
     As a Samurai, your primary focus is to unleash powerful and devastating attacks on your enemies.\
      Your offensive nature makes you a formidable force on the battlefield,\
       and your precision ensures that your strikes find their mark."
        << endl;
}

Character *chooseClass(string &cls, const string name, std::ostream& out, std::istream& in)
{
    out << "What kind of job class you want?" << endl;
    jobDescription(out);
    in >> cls;
    checkInput(in);
    while (cls != "w" && cls != "m" && cls != "s")
    {
        in.clear();
        in.ignore(256, '\n');
        // fix buffer just in case non-numeric choice entered
        // also gets rid of newline character

        out << "Please input class again(w for Warrior, m for Mage, s for Samurai)";
        in >> cls;
    }
    if (cls == "w")
    {
        Warrior *w = new Warrior(name);
        return w;
    }
    else if (cls == "m")
    {
        Mage *m = new Mage(name);
        return m;
    }
    else
    {
        Samurai *s = new Samurai(name);
        return s;
    }
}

Character* chapter1_1_1(std::ostream &out, std::istream &in)
{
    string name;
    string cls;
    try
    {
        
        out << "Game start!" << endl;
        out << "What is your character's name?(Do not contain your name with space)" << endl;
        in >> name;
        checkInput(in);
        
        return chooseClass(cls, name, out, in);
    }
    catch (const runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    return chooseClass(cls, name, out, in);
}






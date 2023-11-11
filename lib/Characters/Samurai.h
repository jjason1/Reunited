#ifndef SAMURAI_H
#define SAMURAI_H
#include <string>
#include "Character.h"
using std::string;

class Samurai: public Character
{
private:
    

public:
    Samurai(const string& name);
    ~Samurai();
};

#endif
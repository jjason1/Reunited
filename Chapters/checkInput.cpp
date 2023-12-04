#include <cstdio>
#include <cstring>
#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "../lib/checkInput.h"
using std::runtime_error;

void checkInput(std::istream &in)
{
  if (in.fail())
  {
    throw runtime_error("input failure.");
  }
}
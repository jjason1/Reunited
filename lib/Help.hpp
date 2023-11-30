#ifndef HELP_HPP
#define HELP_HPP

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <fstream>

class Help {
  std::istream& in;
  std::ostream& out;
public:
  Help(std::istream&, std::ostream&);
  ~Help();
  void display();
};

#endif

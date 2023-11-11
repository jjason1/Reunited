#include "gtest/gtest.h"
#include "../src/showDeveloper.cpp"
#include <sstream>
#include <iostream>
#include <ostream>

TEST(testDeveloper, testDeveloperOutput) {

  std::stringstream testOut;
  std::stringstream confirmOut;
  showDeveloper(testOut);
  confirmOut << "Developer's name:\n"
                "Jason Lin,\n"
                "Cheng-Shun Chuang,\n"
                "Aamir Khan,\n"
                "Boyi Li\n";

  EXPECT_EQ(testOut.str(), confirmOut.str());
      
  
}

#include "gtest/gtest.h"
#include "../src/showDevelopers.cpp"
#include <sstream>
#include <iostream>
#include <ostream>

TEST(testshowDevelopers, testshowDevelopersOutput) {

  std::stringstream testOut;
  std::stringstream confirmOut;
  showDevelopers(testOut);
  confirmOut << "Developer names:\n"
                "Jason Lin,\n"
                "Cheng-Shun Chuang,\n"
                "Aamir Khan,\n"
                "Boyi Li\n";

  EXPECT_EQ(testOut.str(), confirmOut.str());
      
  
}

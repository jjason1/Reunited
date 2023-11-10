#include <iostream>
#include <ostream>
#include <istream>
#include <gtest/gtest.h>
#include <sstream>
#include "../Chapters/ch1.1.1.cpp"
using std::stringstream;

TEST(TestCH1_1_1, TestjobDescription) // test if output are equal
{
    std::stringstream ss;
    ss <<  "w-Warrior" << endl;
    ss << "Description: As a Warrior, your primary role is to be the stalwart \
    defender of your party, ensuring the safety of your comrades on the battlefield.\
     You are a master of defensive skills and tactics,\
      capable of withstanding even the most formidable foes.\
       Your unwavering dedication to protection makes you an \
       indispensable asset in any group."
        << endl;
    ss << endl;
    ss << "m-Mage" << endl;
    ss << "Description: As a Mage, you possess a unique combination of magical prowess and balance in your abilities.\
     You harness the power of arcane energies to both damage enemies and support your allies.\
      Your adaptability and versatility in the arcane arts make you an invaluable addition\
       to any adventuring party."
        << endl;
    ss << endl;
    ss << "s-Samurai" << endl;
    ss << "Description: The Samurai is a master of offense, wielding a blade with precision and skill.\
     As a Samurai, your primary focus is to unleash powerful and devastating attacks on your enemies.\
      Your offensive nature makes you a formidable force on the battlefield,\
       and your precision ensures that your strikes find their mark."
        << endl;

    std::stringstream testss;
    jobDescription(testss);

    EXPECT_TRUE(testss.str() == ss.str());
}


int runTests(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
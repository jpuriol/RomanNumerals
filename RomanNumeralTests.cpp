#include "RomanNumeral.h"
#include "gtest/gtest.h"
#include<string>

namespace 
{
  TEST(RomanNumeral, Basic) 
  {
    const int arabToCheck = 100;
    const std::string expectedRoman = "C";

    RomanNumeral romanNumeral(arabToCheck);
    const std::string actualRoman = romanNumeral.get();

    EXPECT_EQ(expectedRoman, actualRoman);
  }

  TEST(RomanNumeral, Add) 
  {
    const int arabToCheck = 1001;
    const std::string expectedRoman = "MI";
    
    RomanNumeral romanNumeral(arabToCheck);
    const std::string actualRoman = romanNumeral.get();

    EXPECT_EQ(expectedRoman, actualRoman);
  }

  TEST(RomanNumeral, Substract) 
  {
    const int arabToCheck = 90;
    const std::string expectedRoman = "XC";

    RomanNumeral romanNumeral(arabToCheck);
    const std::string actualRoman = romanNumeral.get();
    
    EXPECT_EQ(expectedRoman, actualRoman);
  }

  TEST(RomanNumeral, SubstractAndAdd) 
  {
    const int arabToCheck = 91;
    const std::string expectedRoman = "XCII";

    RomanNumeral romanNumeral(arabToCheck);
    const std::string actualRoman = romanNumeral.get();
    
    EXPECT_EQ(expectedRoman, actualRoman);
  }
}  // namespace

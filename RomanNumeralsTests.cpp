#include <string>

#include "RomanNumerals.h"
#include "gtest/gtest.h"

namespace {
  TEST(YellowBelt, OneToI) {
    const int arab = 1;

    const std::string actualRoman = toRoman(arab);

    const std::string expectedRoman = "I";
    EXPECT_EQ(expectedRoman, actualRoman);
  };
}  // namespace

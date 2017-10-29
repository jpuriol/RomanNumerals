#ifndef GTEST_SAMPLES_SAMPLE1_H_
#define GTEST_SAMPLES_SAMPLE1_H_
#include <string>
#include <map>

class RomanNumeral
{
  public:
    std::string get();
    RomanNumeral(int);
  private:
    int arabNumeral;
    const std::map<int, char> symbols 
    {
      {1, 'I'}, 
      {5, 'V'}, 
      {10, 'X'},
      {50, 'L'},
      {100, 'C'},
      {500, 'D'},
      {1000, 'M'}
    };
    std::string basicAlgorithm(int);
};

#endif  // GTEST_SAMPLES_SAMPLE1_H_

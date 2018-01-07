#include "RomanNumerals.h"
#include <string>
#include <map>
#include <iostream>

RomanNumeral::RomanNumeral(int arabNumeral)
{ this->arabNumeral = arabNumeral; }


std::string RomanNumeral::get()
{
  return RomanNumeral::basicAlgorithm(this->arabNumeral / 1000 % 10 * 1000) // Millones
    + RomanNumeral::basicAlgorithm(this->arabNumeral / 100 % 10 * 100) // Centenas
    + RomanNumeral::basicAlgorithm(this->arabNumeral / 10 % 10 * 10)  // Decenas
    + RomanNumeral::basicAlgorithm(this->arabNumeral % 10);
}

/**
 * Works for al cases except for: SubstractingAndAdding
 */
std::string RomanNumeral::basicAlgorithm(int arabNumeral) 
{
  std::string roman = "";
  int remainigArab = arabNumeral;  

  // Basic & Adding
  while(remainigArab > 0)
  {
    auto it = symbols.lower_bound(remainigArab);
    if( (it == symbols.cend()) || (remainigArab - it->first < 0) ) 
      --it;
    roman += it->second;
    remainigArab -= it->first;
  } 

  // Substracting & 
  for(auto iter : symbols)
  {
    std::string toFind = "";
    for(int i = 1; i <= 4; i++)
      toFind += iter.second; 
    auto foundRepeated = roman.find(toFind);
    if (foundRepeated != std::string::npos) // Si encuentra más de tres carácteres seguidos
    {
      roman = iter.second;
      roman += symbols.lower_bound(arabNumeral)->second;
    }
  }
  
  return roman;
}

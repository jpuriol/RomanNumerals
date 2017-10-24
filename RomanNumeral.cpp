#include "RomanNumeral.h"
#include <string>
#include <map>
#include <iostream>

RomanNumeral::RomanNumeral(int arabNumeral)
{ this->arabNumeral = arabNumeral; }

std::string RomanNumeral::get() 
{
  std::string roman = "";
  int remainigArab = this->arabNumeral;  

  // Basic & Adding
  do 
  {
    auto it = symbols.lower_bound(remainigArab);
    if( (it == symbols.cend()) || (remainigArab - it->first < 0) ) 
      --it;
    roman += it->second;
    remainigArab -= it->first;
  } 
  while(remainigArab > 0);

  // Substracting & SubstractingAndAdding
  for(auto iter : symbols)
  {
    std::string toFind = "";
    for(int i = 1; i <= 4; i++)
      toFind += iter.second; 
    auto foundRepeated = roman.find(toFind);
    if (foundRepeated != std::string::npos) // Si encuentra más de tres carácteres seguidos
    {
      roman = iter.second;
      roman += symbols.lower_bound(this->arabNumeral)->second;
    }
  }
  
  return roman;
}

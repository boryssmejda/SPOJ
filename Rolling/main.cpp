#include <iostream>
#include <memory>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "roll.hpp"

void splitString(std::string stringToBeSplitted, int* numbersToEnter, int* rollByKnumbers);

int main(){

  std::string firstLine;
  int numbersToEnter = 0, rollByKnumbers = 0;
  getline(std::cin ,firstLine);
  splitString(firstLine , &numbersToEnter , &rollByKnumbers);

  //std::cin.ignore();
  std::string numbersSequence;
  getline(std::cin , numbersSequence);
  RollNumbers roll(numbersSequence , numbersToEnter);

  roll.rollNumbers(rollByKnumbers);

  std::cout<<roll;
  return 0;
}



void splitString(std::string stringToBeSplitted, int* numbersToEnter, int* rollByKnumbers){

  std::istringstream tokenStream(stringToBeSplitted);
  std::string tmp;
  std::vector<std::string> tokens;

  while(getline( tokenStream , tmp , ' ') ){
    tokens.push_back(tmp);
  }

  *numbersToEnter = stoi(tokens.at(0));
  *rollByKnumbers = stoi(tokens.at(1));
}

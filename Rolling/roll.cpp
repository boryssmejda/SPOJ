#include "roll.hpp"


RollNumbers::RollNumbers(std::string num , int numbersToEnter){
  this->numberLine = num;
  length = numbersToEnter;
  numbersToRoll    = new int[numbersToEnter];
  finalResult      = new int[numbersToEnter];
}

RollNumbers::~RollNumbers(){

  delete[] numbersToRoll;
  delete[] finalResult;
}


void RollNumbers::split(){

  std::istringstream tokenStream(numberLine);
  std::string tmp;
  std::vector<std::string> tokens;

  while(getline(tokenStream , tmp , ' ') ){
    tokens.push_back(tmp);
  }


  for(int i = 0; i < length; i++){
    numbersToRoll[i] = stoi(tokens.at(i));
  }

}

void RollNumbers::rollNumbers(int rollBy){

  split();

  for(int i = 0; i < length; i++){
    int newIndex = i - rollBy;
    if(newIndex < 0){
      newIndex = length + newIndex;
    }
    finalResult[newIndex] = numbersToRoll[i];
  }

}


std::ostream& operator << (std::ostream & os , const RollNumbers & rl){

  for(int i = 0; i < rl.length; i++){
    os<<rl.finalResult[i];
    if(i + 1 < rl.length){
      os<<" ";
    }else{
      os<<"\n";
    }
  }

  return os;
}

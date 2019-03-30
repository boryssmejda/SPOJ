#include <iostream>

using namespace std;
bool isPESELcorrect(std::string pesel){


  int coefficients[] = {1 , 3 , 7 , 9 , 1 , 3 , 7 , 9 , 1 , 3 , 1};

  int sum = 0;
  for(int i = 0; i < (int)pesel.length(); i++){
    sum += ((pesel.at(i) - '0') * coefficients[i]) ;
  }

  if(sum <= 0){
    return false;
  }

  if(sum % 10 == 0){
    return true;
  }else{
    return false;
  }
}



#include "pesel.hpp"
#include <iostream>

Pesel::Pesel() : coefficients{1 , 3 , 7 , 9 , 1 , 3 , 7 , 9 , 1 , 3 , 1}{
}

bool Pesel::isPESELcorrect(){

  int sum = 0;
  for(int i = 0; i < (int)pesel.length(); i++){
    sum += ((pesel.at(i) - '0') * coefficients[i]) ;
  }

  cout<<sum<<endl;

  if(sum <= 0){
    return false;
  }

  if(sum % 10 == 0){
    return true;
  }else{
    return false;
  }
}

void Pesel::setPesel(std:: string pesel){
  this->pesel = pesel;
}

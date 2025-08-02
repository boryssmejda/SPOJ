#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "pesel.hpp"

using namespace std;

#define INCORRECT_PESEL "N\n"
#define CORRECT_PESEL   "D\n"


int main(){

  int nrOfPeselToBeEntered;
  cin>>nrOfPeselToBeEntered;
  cin.ignore();

  Pesel* pesel = new Pesel[nrOfPeselToBeEntered];
  for(int i = 0; i < nrOfPeselToBeEntered; i++){
    string tmp;
    getline(cin , tmp);
    pesel[i].setPesel(tmp);
  }

  for(int i = 0; i < nrOfPeselToBeEntered; i++){
    if(pesel[i].isPESELcorrect() ){
      std::cout<<CORRECT_PESEL;
    }else{
      cout<<INCORRECT_PESEL;
    }
  }

  delete[]  pesel;
  return 0;
}

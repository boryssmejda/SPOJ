#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "threePoints.hpp"

using namespace std;

#define SIZE 100

void split(int* output, int size, string input , char delimiter);
int main(){

  int N;
  cin>>N;
  cin.ignore();

  string* txt = new string [N];
  int** points = new int*[N];

  for(int i = 0; i < N; i++){
    getline(cin , txt[i]);
    points[i] = new int[2*NR_POINTS];
    split(points[i] , 2*NR_POINTS , txt[i] , '\t');
    if(isOnLine(points[i]) == true){
      cout<<"TAK\n";
    }else{
      cout<<"NIE\n";
    }
  }

  for(int i = 0; i < N; i++){
    delete[] points[i];
  }
  delete[] points;
  delete[] txt;
  return 0;
}

void split(int* output, int size, string input , char delimiter){

  std::istringstream tokenStream(input);
  std::string tmp;
  std::vector<std::string> tokens;

  while(getline( tokenStream , tmp , delimiter) ){
    tokens.push_back(tmp);
  }

  for(int i = 0; i < size; i++){
    output[i] = stoi(tokens.at(i) );
  }


}

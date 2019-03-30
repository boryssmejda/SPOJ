#include <iostream>
#include <memory>
using namespace std;

#define SIZE 150

void countTheLetters(std::unique_ptr<string[]> & txt, int size);

int main(){


  int N;
  cin>>N;
  unique_ptr<string[]> txt (new string[N]);

  if(N > SIZE){
    return 0;
  }

  cin.ignore();
  for(int i = 0; i < N; i++){
    getline(cin , txt[i]);
  }

  countTheLetters(txt , N);
  cout<<"Hello and Bye !\n";
  return 0;
}

void countTheLetters(std::unique_ptr<string[]> & txt, int size){

  char letter = 'a';
  int freq = 0;
    while(letter != 'Z' + 1){
      freq = 0;
      for(int i = 0; i < size; i++){

        for(unsigned int j = 0; j < txt[i].length(); j++){
          if(txt[i].at(j) == letter )
          freq++;
        }
      }
      if(freq){
          cout<<letter<<" "<<freq<<endl;
      }

      letter++;
      if(letter == 'z' + 1){
        letter = 'A';
      }
    }
}

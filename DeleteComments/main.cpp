#include <iostream>
#include "fileReader.h"


int main(){

  FileReader fr("code1.txt");
  fr.openFile();
  fr.loadLines();
  
  return 0;
}

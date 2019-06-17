#include <iostream>
#include "fileReader.h"


int main(){

  FileReader fr("code2.txt");
  fr.openFile();
  fr.loadLines();
  fr.deleteComments();
  fr.saveToFile("output.txt");

  return 0;
}

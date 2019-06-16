#include "fileReader.h"
/*PRIVATE METHODS=====================================*/
int FileReader::countTheLines(){

  if(!inFile.is_open()){
    return -1;
  }

  std::string line;
  int number_of_lines = 0;

  while (std::getline(inFile, line))
        ++number_of_lines;

        inFile.clear();
        inFile.seekg(0);
        return number_of_lines;
}



/*PUBLIC METHODS ====================================*/
FileReader::FileReader(std::string filename){

    this->filename = filename;
}

FileReader::~FileReader(){

  if(inFile.is_open()){
    inFile.close();
  }
}


void FileReader::openFile(){

  inFile.open(filename);

  if (!inFile) {
    std::cerr << "Unable to open";
    std::exit(1);   // call system to stop
  }

  nrLinesInTheFile = countTheLines();
}


void FileReader::loadLines(){

  std::unique_ptr<std::string[]> tmp(new std::string[nrLinesInTheFile]);
  sourceCode = std::move(tmp);

  int currentLine = 0;
  while(std::getline(inFile, sourceCode[currentLine])){
    sourceCode[currentLine++] += "\n";
  }

}

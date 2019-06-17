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

int FileReader::deleteSingleLineComments(){

  int commentsDeleted = 0;

    for(int i = 0; i < nrLinesInTheFile; i++){

      size_t found = sourceCode[i].find("//");
      if (found != std::string::npos){
          sourceCode[i].erase(sourceCode[i].begin()+ found, sourceCode[i].end()-1);
          commentsDeleted++;
      }

    }

    return commentsDeleted;
}

int FileReader::deleteMultiLineComments(){

    return 0;
}

void FileReader::convertStringArrayToVector(){

  for(int row = 0; row < nrLinesInTheFile; row++){

    for(int indexElement = 0; indexElement < sourceCode[row].length(); indexElement++){
      std::string toAdd(1,sourceCode[row].at(indexElement));
      finalSourceCode.push_back(toAdd);
    }
  }

  for(std::string s : finalSourceCode){
    std::cout << s;
  }

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

int FileReader::deleteComments(){

  int deletedComments = 0;

  deletedComments += deleteSingleLineComments();

  convertStringArrayToVector();

  deletedComments += deleteMultiLineComments();

  return deletedComments;
}

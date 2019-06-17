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

  while(true){
    size_t foundBegin = sourceCodeToBeProcessed.find("/*");
    if (foundBegin != std::string::npos)
      std::cout << "First occurrence is " << foundBegin << std::endl;
    else
      break;

    int counter = 0;
    while(true){

      if(sourceCodeToBeProcessed.at(foundBegin) == '*'){
        if(sourceCodeToBeProcessed.at(foundBegin+1) == '/'){
          sourceCodeToBeProcessed.erase(sourceCodeToBeProcessed.begin() + foundBegin, sourceCodeToBeProcessed.begin() + foundBegin+2);
          break;
        }
      }

      sourceCodeToBeProcessed.erase(sourceCodeToBeProcessed.begin() + foundBegin);
    }
  }

    std::cout<<sourceCodeToBeProcessed<<std::endl;
    return 0;
}

void FileReader::convertStringArrayToString(){

  for(int row = 0; row < nrLinesInTheFile; row++){

    for(int indexElement = 0; indexElement < sourceCode[row].length(); indexElement++){
      std::string toAdd(1,sourceCode[row].at(indexElement));
      sourceCodeToBeProcessed += toAdd;
    }
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

  convertStringArrayToString();

  deletedComments += deleteMultiLineComments();

  return deletedComments;
}

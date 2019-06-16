#include <iostream>
#include <fstream>
#include <memory>
#include <iterator>
#include <algorithm>

class FileReader{


  private:
    std::string filename;
    std::ifstream inFile;
    int nrLinesInTheFile;
    std::unique_ptr<std::string[]> sourceCode;
    int countTheLines();

  public:
    FileReader(std::string filename);
    ~FileReader();

    void openFile();
    void loadLines();

};

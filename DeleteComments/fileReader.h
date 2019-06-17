#include <iostream>
#include <fstream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <vector>

class FileReader{


  private:
    std::string filename;
    std::ifstream inFile;
    int nrLinesInTheFile;
    std::unique_ptr<std::string[]> sourceCode;
    std::string sourceCodeToBeProcessed;
    //std::vector<std::string> finalSourceCode;
    int countTheLines();
    int deleteSingleLineComments();
    int deleteMultiLineComments();
    void convertStringArrayToString();

  public:
    FileReader(std::string filename);
    ~FileReader();

    void openFile();
    void loadLines();
    int deleteComments();
    void saveToFile(std::string filename);
};

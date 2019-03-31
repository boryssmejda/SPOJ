#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

class RollNumbers{

  private:
    std::string numberLine;
    int* numbersToRoll;
    int* finalResult;
    int  length;
    void split();
  public:
    RollNumbers(std::string num , int numbersToEnter);
    ~RollNumbers();
    void rollNumbers(int placesToRoll);

    friend std::ostream& operator << (std::ostream & os , const RollNumbers & rl);
};

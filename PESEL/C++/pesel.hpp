#include <string>
#include <iostream>
#define PESEL_SIZE 11

using namespace std;

class Pesel{

    private:
      int coefficients[PESEL_SIZE];
      std::string pesel;
    public:
      Pesel();
      bool isPESELcorrect();
      void setPesel(std::string pesel);
};

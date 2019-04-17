#include <iostream>
#include "MessageTrimmer.h"

#define MAX_NUMBER_OF_STRING 10
#define ERROR -1

using namespace std;


int main() {


	std::string filename;
	std::cout << "Enter the file which you want to open:";
	std::cin >> filename;


	MessageTrimmer trimmer(filename);
	if (trimmer.openSMSmessage() == ERROR) {
		std::cout << "Incorrect filename, try again\n";
		return ERROR;
	}

	std::cout << trimmer;
	trimmer.trimAllSpaces();
	trimmer.saveSMSmessage("result.txt");

	std::cout << trimmer;

}
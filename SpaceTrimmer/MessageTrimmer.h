#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#pragma once

#define ERROR -1
#define SUCCESS 1

class MessageTrimmer {

	private:
		std::vector<std::string> messageLines;
		std::ifstream fileToRead;
		std::ofstream fileToWrite;
		std::string filename;
		int loadLinesToVector();
		std::string trimCurrentLine(std::string line);

	public:
		
		MessageTrimmer(std::string filename);
		~MessageTrimmer();
		int openSMSmessage();
		int setFilename(std::string filename);
		std::string getFilename() const;
		int trimAllSpaces();
		int saveSMSmessage(std::string filename);


		friend std::ostream& operator << (std::ostream& os, const MessageTrimmer& trimmer);
};
#include "MessageTrimmer.h"

MessageTrimmer::MessageTrimmer(std::string filename) {

	this->filename = filename;
}

MessageTrimmer::~MessageTrimmer()
{

	if (fileToWrite.is_open()) {
		fileToWrite.close();
	}
	
	fileToRead.close();
}

int MessageTrimmer::setFilename(std::string filename)
{
	if (filename.empty()) {
		return ERROR;
	}
	
	this->filename = filename;
	return SUCCESS;
}

std::string MessageTrimmer::getFilename() const
{
	return filename;
}

int MessageTrimmer::openSMSmessage()
{
	fileToRead.open(filename, std::ios::in);
	if (fileToRead.is_open()) {
		loadLinesToVector();
		return SUCCESS;
	}
	else {
		return ERROR;
	}

}

int MessageTrimmer::loadLinesToVector()
{
	std::string lineFromFile;
	while (std::getline(fileToRead, lineFromFile)) {
		messageLines.push_back(lineFromFile);
	}

	return SUCCESS;
}

std::string  MessageTrimmer::trimCurrentLine(std::string line)
{
	for (unsigned currentPos = 0; currentPos < line.length(); currentPos++) {

		if (isspace(line[currentPos])) {
			int beginning = currentPos;
			int end = 0;
			for (unsigned newIndex = currentPos; newIndex < line.length(); newIndex++) {
				if (isspace(line[newIndex])) {
					continue;
				}

				line[newIndex] = toupper(line[newIndex]);
				end = newIndex;
				currentPos = newIndex;
				break;
			}

			line.erase(line.begin()+beginning, line.begin()+ end);
		}
		
	}
	return line;
}

int MessageTrimmer::trimAllSpaces()
{

	for (auto &line : messageLines) {
		line = trimCurrentLine(line);
	}


	return SUCCESS;
}

int MessageTrimmer::saveSMSmessage(std::string filename)
{
	fileToWrite.open(filename, std::ios::out);
	if (fileToWrite.is_open() == false) {
		return ERROR;
	}

	for (auto line : messageLines) {
		fileToWrite << line;
	}

	return SUCCESS;
}

std::ostream& operator<<(std::ostream& os, const MessageTrimmer& trimmer)
{
	for (auto line : trimmer.messageLines) {
		os << line<<std::endl;
	}

	return os;
}

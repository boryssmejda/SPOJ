#include "..\include\floatRepresentation.hpp"

FloatRepresentation::FloatRepresentation(float num): number(num), completeFloatRepresentation(""){}

std::string FloatRepresentation::getFloatHexRepresentation()
{
	for (int i = size - 1; i >= 0; i--) {

		std::stringstream ss;
		ss << std::hex << (unsigned int)hexRepresentationOfFloat[i];
		completeFloatRepresentation += (ss.str() + " ");
	}

	completeFloatRepresentation = completeFloatRepresentation.substr(0, completeFloatRepresentation.length()-1);

	return completeFloatRepresentation;
}


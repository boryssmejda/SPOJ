#ifndef  FLOAT_REPRESENTATION
#define  FLOAT_REPRESENTATION

#include <iostream>
#include <string>
#include <sstream>

constexpr int size = sizeof(float);

class FloatRepresentation {

private:
	union
	{
		float number;
		unsigned char hexRepresentationOfFloat[size];
	};

	std::string completeFloatRepresentation;
public:
	FloatRepresentation(float num);
	FloatRepresentation() {}
	std::string getFloatHexRepresentation();
};

#endif // ! FLOAT_REPRESENTATION

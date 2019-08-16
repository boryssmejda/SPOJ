#ifndef  FLOAT_REPRESENTATION
#define  FLOAT_REPRESENTATION

class FloatRepresentation {

private:
	union
	{
		float number;
		char hexRepresentationOfFloat[4];
	};

public:
	FloatRepresentation(float num);
	void printFloatHexRepresentation();
};

#endif // ! FLOAT_REPRESENTATION

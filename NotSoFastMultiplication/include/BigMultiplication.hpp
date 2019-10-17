#include <thread>
#include <string>
#include <iostream>

class BigMultiplier {

private:
	std::string m_number;

public:
	explicit BigMultiplier(const std::string& t_givenNumber): m_number{t_givenNumber}{}
	explicit BigMultiplier(const char* t_givenNumber) : m_number{ t_givenNumber } {}

	friend const BigMultiplier operator * (const BigMultiplier& t_numA, const BigMultiplier& t_numB);
	friend std::ostream& operator<<(std::ostream& os, const BigMultiplier& dt);
};
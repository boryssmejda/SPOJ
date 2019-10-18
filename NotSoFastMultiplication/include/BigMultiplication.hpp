#include <chrono>
#include <iostream>
#include <string>
#include <vector>

class BigMultiplier {

protected:
	std::string m_number;
	static std::string multiplyBySingleDigit(const std::string& number,const char multiplyBy);
	static void shiftLeftBy(std::string& number ,int shiftBy);
	static BigMultiplier addAllElements(const std::vector<std::string>& allElements);
	static std::string add(const std::string& a, const std::string& b);

public:
	explicit BigMultiplier(const std::string& t_givenNumber): m_number{t_givenNumber}{}
	explicit BigMultiplier(const char* t_givenNumber) : m_number{ t_givenNumber } {}

	friend const BigMultiplier operator * (const BigMultiplier& t_numA, const BigMultiplier& t_numB);
	friend bool operator == (const BigMultiplier& t_numA, const BigMultiplier& t_numB);
	friend std::ostream& operator<<(std::ostream& os, const BigMultiplier& dt);
};

class Timer {
	using Clock = std::chrono::high_resolution_clock;

public:
	Timer() 
	{
		m_startTimePoint = Clock::now();
	}

	~Timer()
	{
		stop();
	}

private:
	std::chrono::time_point<Clock> m_startTimePoint;
	void stop()
	{
		auto endPoint = Clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
		auto end  = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

		auto duration = end - start;
		std::cout << duration << "us" << "\n";

	}
};
#ifndef TIME_CLASS_H
#define TIME_CLASS_H
#include<chrono>





class Time {

public:
	Time();
	void Reset();
	float GetElapsedTime();
	float GetTotalElapsedTime();


private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};




#endif
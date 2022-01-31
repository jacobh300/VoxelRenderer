#include"Time.h"


Time::Time() {

	Reset();

};

//Resets the clocks start time
void Time::Reset() {
	startTime = std::chrono::high_resolution_clock::now();
};



float Time::GetElapsedTime() {

	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - startTime).count() * 0.001f * 0.001f * 0.001f;

}


//Gets Elapsed Time of the runtime since the start of the program
float Time::GetTotalElapsedTime() {

	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - startTime).count() * 0.001f * 0.001f * 0.001f;

}

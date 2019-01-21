#include "Timer.h"

void System::Timer::start()
{
	timeStart = std::chrono::system_clock::now();
	isRunning = true;
}

void System::Timer::stop()
{
	timeEnd = std::chrono::system_clock::now();
	isRunning = false;
}

double System::Timer::elapsedMilliseconds()
{
	std::chrono::time_point<std::chrono::system_clock> endTime;

	if (isRunning)
	{
		endTime = std::chrono::system_clock::now();
	}
	else
	{
		endTime = timeEnd;
	}

	return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - timeStart).count();
}

double System::Timer::elapsedSeconds()
{
	return elapsedMilliseconds() / 1000.0;
}



#pragma once
//#include <chrono>
#include <string>
namespace System
{
	class Timer
	{
	private:
	//	std::chrono::time_point<std::chrono::system_clock> timeStart;
	//	std::chrono::time_point<std::chrono::system_clock> timeEnd;
		bool  isRunning = false;

	public:
		void start();

		void stop();

		double elapsedMilliseconds();

		double elapsedSeconds();

	};
};
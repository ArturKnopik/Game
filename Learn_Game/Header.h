#pragma once
#include <stdint.h>
#include <chrono>
namespace TCG
{
	namespace UtilityTools
	{
		class UID
		{
			static std::size_t uid = 0;
			size_t id;
		public:
			UID() { id = uid; uid++ };
			size_t getID() { return id; };
		};

		auto getCurrentTime()
		{
			return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		}
	}
}
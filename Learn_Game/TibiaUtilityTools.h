#pragma once
#include <stdint.h>
#include <chrono>
#include <string>

namespace TGC
{
	namespace UtilityTools
	{
		class UniqueIDGenerator
		{
		public:
			static UniqueIDGenerator& getInstance()
			{
				static UniqueIDGenerator Generator;
				return Generator;
			};
			size_t next();
		private:
			UniqueIDGenerator();
			size_t id;
		};
	}
}
/*
int64_t getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
*/


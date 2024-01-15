#pragma once 
#include <spdlog/spdlog.h>

namespace gvsx {

	namespace core {

		void LogInfo(const char* msg);
		void LogDebug(const char* msg);
		void LogWarn(const char* msg);
		void LogError(const char* msg);
		void LogCritical(const char* msg);
	}
}
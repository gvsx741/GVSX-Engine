#pragma once 
#include <spdlog/spdlog.h>

namespace gvsx {

	namespace core {

		template<typename... Args>
		void LogInfo(Args&&... args);

		template<typename... Args>
		void LogDebug(Args&&... args);

		template<typename... Args>
		void LogWarn(Args&&... args);
		
		template<typename... Args>
		void LogError(Args&&... args);

		template<typename... Args>
		void LogCritical(Args&&... args);


		void LogInfo(const char* msg);
		void LogDebug(const char* msg);
		void LogWarn(const char* msg);
		void LogError(const char* msg);
		void LogCritical(const char* msg);
	}
}
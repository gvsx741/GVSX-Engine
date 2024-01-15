#include <core/logger.h>

namespace gvsx {

	namespace core {

		void LogInfo(const char* msg)
		{
			spdlog::info(msg);
		}

		void LogDebug(const char* msg)
		{
			spdlog::debug(msg);
		}

		void LogWarn(const char* msg)
		{
			spdlog::warn(msg);
		}

		void LogError(const char* msg)
		{
			spdlog::error(msg);
		}

		void LogCritical(const char* msg)
		{
			spdlog::critical(msg);
		}
	}
}
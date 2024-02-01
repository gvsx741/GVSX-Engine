#include <core/logger.h>

namespace gvsx {

	namespace core {

		template<typename... Args>
		void LogInfo(Args&&... args)
		{
			spdlog::info(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		void LogDebug(Args && ...args)
		{
			spdlog::debug(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		void LogWarn(Args && ...args)
		{
			spdlog::warn(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		void LogError(Args && ...args)
		{
			spdlog::error(std::forward<Args>(args)...);
		}

		template<typename ...Args>
		void LogCritical(Args && ...args)
		{
			spdlog::critical(std::forward<Args>(args)...);
		}

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
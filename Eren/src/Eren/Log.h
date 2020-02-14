#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Eren {
	class EREN_API Log
	{
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return mCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return mClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> mCoreLogger;
		static std::shared_ptr<spdlog::logger> mClientLogger;

	};
}

//Core log macros
#define EREN_CORE_FATAL(...) ::Eren::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define EREN_CORE_ERROR(...) ::Eren::Log::getCoreLogger()->error(__VA_ARGS__)
#define EREN_CORE_WARN(...) ::Eren::Log::getCoreLogger()->warn(__VA_ARGS__)
#define EREN_CORE_INFO(...) ::Eren::Log::getCoreLogger()->info(__VA_ARGS__)
#define EREN_CORE_TRACE(...) ::Eren::Log::getCoreLogger()->trace(__VA_ARGS__)

//Client log macros
#define EREN_FATAL(...) ::Eren::Log::getClientLogger()->fatal(__VA_ARGS__)
#define EREN_ERROR(...) ::Eren::Log::getClientLogger()->error(__VA_ARGS__)
#define EREN_WARN(...) ::Eren::Log::getClientLogger()->warn(__VA_ARGS__)
#define EREN_INFO(...) ::Eren::Log::getClientLogger()->info(__VA_ARGS__)
#define EREN_TRACE(...) ::Eren::Log::getClientLogger()->trace(__VA_ARGS__)

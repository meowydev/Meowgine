#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Meowgine {
	class MG_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Macros for core logs 
#define MG_CORE_FATAL(...) ::Meowgine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define MG_CORE_ERROR(...) ::Meowgine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MG_CORE_WARN(...)  ::Meowgine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MG_CORE_INFO(...)  ::Meowgine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MG_CORE_TRACE(...) ::Meowgine::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Same for client
#define MG_FATAL(...) ::Meowgine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define MG_ERROR(...) ::Meowgine::Log::GetClientLogger()->error(__VA_ARGS__)
#define MG_WARN(...)  ::Meowgine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MG_INFO(...)  ::Meowgine::Log::GetClientLogger()->info(__VA_ARGS__)
#define MG_TRACE(...) ::Meowgine::Log::GetClientLogger()->trace(__VA_ARGS__)
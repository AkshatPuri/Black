#pragma once
#include"Core.h"
#include<spdlog/spdlog.h>
#include "bpch.h"
#include<spdlog/fmt/ostr.h>
namespace Black
{
	class BLACKAPI Log
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

//Core log macros
#define BLACK_LOG_INFO(...)  Black ::Log::GetCoreLogger()->info(__VA_ARGS__);
#define BLACK_LOG_ERROR(...)  Black ::Log::GetCoreLogger()->error(__VA_ARGS__);
#define BLACK_LOG_WARN(...)  Black ::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define BLACK_LOG_TRACE(...)  Black ::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define BLACK_LOG_FATAL(...)  Black ::Log::GetCoreLogger()->fatal(__VA_ARGS__);

//Client log macros
#define BLACK_LOG(...)  Black ::Log::GetClientLogger()->info(__VA_ARGS__);
#define BLACK_ERROR(...)  Black ::Log::GetClientLogger()->error(__VA_ARGS__);
#define BLACK_WARN(...)  Black ::Log::GetClientLogger()->warn(__VA_ARGS__);
#define BLACK_TRACE(...)  Black ::Log::GetClientLogger()->trace(__VA_ARGS__);
#define BLACK_FATAL(...)  Black ::Log::GetClientLogger()->fatal(__VA_ARGS__);
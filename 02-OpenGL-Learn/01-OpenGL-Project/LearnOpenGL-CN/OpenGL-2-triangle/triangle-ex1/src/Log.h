#pragma once

#include <memory>

#include "spdlog/spdlog.h"

namespace SandboxEngine {
	class Log
	{
	public:
		static void Init();
		inline static std::shared_ptr <spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr <spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;
	};
}

#define ENGINE_DEBUG

#ifdef ENGINE_DEBUG
// Core log macros
#define SANDBOXENGINE_CORE_TRACE(...)    SandboxEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SANDBOXENGINE_CORE_INFO(...)     SandboxEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SANDBOXENGINE_CORE_WARN(...)     SandboxEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SANDBOXENGINE_CORE_ERROR(...)    SandboxEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SANDBOXENGINE_CORE_CRITICAL(...) SandboxEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
							   
// Client log macros		   
#define SANDBOX_TRACE(...)         SandboxEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SANDBOX_INFO(...)          SandboxEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SANDBOX_WARN(...)          SandboxEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SANDBOX_ERROR(...)         SandboxEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SANDBOX_CRITICAL(...)      SandboxEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
#else
// Core log macros
#define SANDBOXENGINE_CORE_TRACE(...)   
#define SANDBOXENGINE_CORE_INFO(...)    
#define SANDBOXENGINE_CORE_WARN(...)    
#define SANDBOXENGINE_CORE_ERROR(...)   
#define SANDBOXENGINE_CORE_CRITICAL(...)

// Client log macros		 
#define SANDBOX_TRACE(...)        
#define SANDBOX_INFO(...)         
#define SANDBOX_WARN(...)         
#define SANDBOX_ERROR(...)        
#define SANDBOX_CRITICAL(...)     
#endif // ENGINE_DEBUG

#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace SandboxEngine {

	std::shared_ptr <spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr <spdlog::logger> Log::s_ClientLogger;

	void SandboxEngine::Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("SandboxEngine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Sandbox");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
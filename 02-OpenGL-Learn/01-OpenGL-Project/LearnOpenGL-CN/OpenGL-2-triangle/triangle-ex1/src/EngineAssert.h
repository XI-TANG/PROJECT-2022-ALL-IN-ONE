#pragma once
#include <string>
#include "Log.h"
namespace SandboxEngine {
	class Assert
	{
	public:
		inline static void SandboxAssert(const std::string& e, const std::string& file, int line) {
			SANDBOX_ERROR("err info" + e + file + std::to_string(line));
		}
		inline static void SandboxEngineAssert(const std::string& e, const std::string& file, int line) {
			SANDBOXENGINE_CORE_ERROR("err info" + e + file + std::to_string(line));
		};
	};
} 


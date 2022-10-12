#pragma once
#include <string>

namespace SandboxEngine {
	class Assert
	{
	public:
		inline static void SandboxAssert(const std::string& e, const std::string& file, int line);
		inline static void SandboxEngineAssert(const std::string& e, const std::string& file, int line);
	};
} 
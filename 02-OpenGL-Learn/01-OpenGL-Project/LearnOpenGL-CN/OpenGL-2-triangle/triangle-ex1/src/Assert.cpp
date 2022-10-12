#include "Assert.h"
#include "Log.h"

inline void SandboxEngine::Assert::SandboxAssert(const std::string& e, const std::string& file, int line)
{
	SANDBOX_ERROR("err info" + e + file + std::to_string(line));
}

inline void SandboxEngine::Assert::SandboxEngineAssert(const std::string& e, const std::string& file, int line)
{
	SANDBOXENGINE_CORE_ERROR("err info");
}

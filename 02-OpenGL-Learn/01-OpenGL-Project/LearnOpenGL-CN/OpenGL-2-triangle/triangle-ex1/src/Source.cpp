#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <iostream>

#include "SysInfo.h"
#include "Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() 
{
	//WCHAR - 16bit
	//char - 8bit
	WCHAR path[512];
	SysInfo::GetExePath(path);
	SysInfo::CreateLogPath(path,"ERR INFO");

	SandboxEngine::Log::Init();
	SANDBOXENGINE_CORE_TRACE("test logging");
	SANDBOX_ERROR("err info");

	while (true)
	{
	
	}
	return 0;
}
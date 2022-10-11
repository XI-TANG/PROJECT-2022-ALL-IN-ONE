#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <iostream>

#include "SysInfo.h"


int main() 
{
	//WCHAR - 16bit
	//char - 8bit
	WCHAR path[512];
	SysInfo::GetExePath(path);
	SysInfo::CreateLogPath(path,"");

	while (true)
	{
	
	}
	return 0;
}
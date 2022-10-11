#pragma once
#include <Windows.h>
#include <string>
class SysInfo
{
public:
	SysInfo();
	static bool GetExePath(WCHAR* filepath);
	static bool CreateLogPath(const WCHAR* pathdir, const std::string& errinfo);
	static bool CreateAnyPath(const WCHAR* pathdir, const WCHAR* filename, const std::string& errinfo);
};


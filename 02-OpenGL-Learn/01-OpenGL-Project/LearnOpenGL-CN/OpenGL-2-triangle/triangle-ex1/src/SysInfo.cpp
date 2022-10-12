#include <stdio.h>
#include <iostream>

#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include "SysInfo.h"
#include "FileOperation.h"

SysInfo::SysInfo()
{
}

bool SysInfo::GetExePath(WCHAR* filepath)
{
	if (!GetModuleFileName(nullptr, filepath, 512)) {
		return false;
	}
	
	PathRemoveFileSpec(filepath);
	//printf("%ls\n", filepath);
	return true;
}

bool SysInfo::CreateLogPath(const WCHAR* pathdir, const std::string& errinfo)
{
	WCHAR logpath[] = L"\\log";
	
	if (!FileOperation::MakeDirection(pathdir, logpath)) {
		//std::cout << errinfo << "sss" << std::endl;
		return false;
	}
	return true;
}

bool SysInfo::CreateAnyPath(const WCHAR* pathdir, const WCHAR* filename, const std::string& errinfo)
{
	if (!FileOperation::MakeDirection(pathdir, filename)) {
		//std::cout << errinfo << std::endl;
		return false;
	}
	return true;
}

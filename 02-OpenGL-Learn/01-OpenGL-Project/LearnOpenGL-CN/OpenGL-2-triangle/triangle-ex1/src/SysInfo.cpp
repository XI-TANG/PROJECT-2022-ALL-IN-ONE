#include <stdio.h>

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
	//WCHAR logpath[10] = { '\0' };
	//wcscpy_s(logpath, L"log");
	WCHAR logpath[] = L"\\log";
	
	if (!FileOperation::MakeDirection(pathdir, logpath)) {
		return false;
	}
	return true;
}

bool SysInfo::CreateAnyPath(const WCHAR* pathdir, const WCHAR* filename, const std::string& errinfo)
{
	if (!FileOperation::MakeDirection(pathdir, filename)) {
		return false;
	}
	return true;
}

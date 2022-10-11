#pragma once
#include <Windows.h>
#include <string>
#include <Shlwapi.h>
class FileOperation
{
public:
	static bool MakeDirection(const WCHAR* pathdir, const WCHAR* filename);
};


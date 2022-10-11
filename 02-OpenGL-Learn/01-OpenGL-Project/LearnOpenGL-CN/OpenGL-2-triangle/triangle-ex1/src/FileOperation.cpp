#include "FileOperation.h"


bool FileOperation::MakeDirection(const WCHAR* pathdir, const WCHAR* filename)
{

	//the type of fullpath.c_str() is wchar_t/WCHAR
	std::wstring fullpath(std::wstring(pathdir) + std::wstring(filename));

	//WCHAR fullpath[];
	//PathCombineW(fullpath, pathdir, filename);

	if (CreateDirectory(fullpath.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory created or already existed.
	}
	else
	{
		// Failed to create directory.
	}
	return false;
}

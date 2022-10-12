#include "FileOperation.h"


bool FileOperation::MakeDirection(const WCHAR* pathdir, const WCHAR* filename)
{
	std::wstring fullpath(std::wstring(pathdir) + std::wstring(filename));

	if (CreateDirectory(fullpath.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory created or already existed.
	}
	else
	{
		// Failed to create directory.
		return false;
	}
	return true;
}

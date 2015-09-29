#ifndef windows_mkdir_h__
#define windows_mkdir_h__

#if defined(_WINDOWS) || defined(_MSC_VER)

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#undef STRICT

inline int mkdir(const char *path, int /*mode*/)
{
	BOOL success = CreateDirectoryA(path, NULL);
	return success ? 0 : -1;
}

#endif

#endif //windows_mkdir_h__

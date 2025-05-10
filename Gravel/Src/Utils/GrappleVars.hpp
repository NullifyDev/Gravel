#pragma once

#include <Windows.h>
#include <string>
#include <cstring>

namespace Gravel {
	typedef int(*main)(int, char **);
	typedef HANDLE(WINAPI* PfnCreateFileW)(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate);
	inline PfnCreateFileW pfnCreateFileW;

	inline HRESULT COINITIALIZED = NULL;
	inline std::wstring MOD_FILES_PATH = L"";
	inline std::wstring APP_LOCATION = L"";
};

#pragma once

#include <Windows.h>
#include <string>
#include <cstring>

namespace Gravel {
	namespace Grapple {
		typedef HANDLE(WINAPI* PfnCreateFileW)(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate);
		static PfnCreateFileW pfnCreateFileW;

		static std::wstring MOD_FILES_PATH;
		static std::wstring APP_LOCATION;
	};
};
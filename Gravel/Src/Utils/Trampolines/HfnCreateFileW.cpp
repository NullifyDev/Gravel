#include "HfnCreateFileW.hpp"

namespace Gravel {
	HANDLE WINAPI HfnCreateFileW(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate)
	{
		std::wstring filePath(lpFilename);

		printf("HfnCreateFileW: %s\n", lpFilename);
		if (filePath.find(APP_LOCATION) != filePath.npos)
		{
			std::wstring newPath(MOD_FILES_PATH);

			newPath += filePath.substr(filePath.find(L"\\", APP_LOCATION.size()) + 1, filePath.size());

			if (PathFileExists(newPath.c_str()) && !PathIsDirectory(newPath.c_str()))
				return pfnCreateFileW(lpFilename, dwAccess, dwSharing, saAttributes, dwCreation, dwAttributes, hTemplate);
		}
		return pfnCreateFileW(lpFilename, dwAccess, dwSharing, saAttributes, dwCreation, dwAttributes, hTemplate);
	}
}
#include "gravel.h"

namespace Gravel {
    namespace Grapple {
        HANDLE WINAPI HfnCreateFileW(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate)
        {
            std::wstring filePath(lpFilename);

            if (filePath.find(Gravel::Grapple::APP_LOCATION) != filePath.npos)
            {
                std::wstring newPath(Gravel::Grapple::MOD_FILES_PATH);

                newPath += filePath.substr(filePath.find(L"\\", Gravel::Grapple::APP_LOCATION.size()) + 1, filePath.size());

                if (PathFileExists(newPath.c_str()) && !PathIsDirectory(newPath.c_str()))
                    return Gravel::Grapple::pfnCreateFileW(newPath.c_str(), dwAccess, dwSharing, saAttributes, dwCreation, dwAttributes, hTemplate);
            }

            return Gravel::Grapple::pfnCreateFileW(lpFilename, dwAccess, dwSharing, saAttributes, dwCreation, dwAttributes, hTemplate);
        }
    }
}
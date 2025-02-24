#include "Initialize.hpp"

namespace Gravel {
    namespace Grapple {
        BOOL Initialize()
        {
            if (MH_Initialize() != MH_OK) return FALSE;

            TCHAR szPath[MAX_PATH];
            if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath)))
            {
                std::wstring appData(szPath);
                appData = appData.substr(0, appData.rfind(L"AC"));
                appData += L"LocalState\\mods\\";

                Gravel::Grapple::MOD_FILES_PATH = appData;
            }
            else return FALSE;

            BOOL hook = TRUE;
            hook &= Attach((LPWSTR)L"KernelBase.dll", "CreateFileW", (LPVOID*)&Gravel::Grapple::HfnCreateFileW, (LPVOID*)(&(Gravel::Grapple::pfnCreateFileW)));

            return hook;
        }
    }
}
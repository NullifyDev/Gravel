#include "Initialize.hpp"

namespace Spade {
    namespace Grapple {
        BOOL Initialize(std::wstring app)
        {
            printf("Initialize: hit!\n");
            if (MH_Initialize() != MH_OK) return FALSE;

            CoInitialize(nullptr);

            TCHAR szPath[MAX_PATH];
            if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath))) {

                size_t firstUnderscore = app.find('_'), lastUnderscore = app.rfind('_');

                std::wstringstream wss;
                wss << szPath << L"\\Packages\\" << app.substr(0, firstUnderscore) + L"_" + app.substr(lastUnderscore + 1) << L"\\LocalState\\mods\\";
                Spade::Grapple::MOD_FILES_PATH = wss.str().c_str();

                Grapple::APP_LOCATION = L"C:\\Program Files\\WindowsApps\\" + app;

            }
            else return FALSE;

            BOOL grapple = TRUE;
            grapple &= Attach((LPWSTR)L"KernelBase.dll", "CreateFileW", (LPVOID*)&Spade::Grapple::HfnCreateFileW, (LPVOID*)(&(Spade::Grapple::pfnCreateFileW)));
            printf("Initialize: grapple: %d\n", grapple);
            return grapple;
        }
    }
}
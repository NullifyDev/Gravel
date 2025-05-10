#include "Initialize.hpp"

namespace Gravel {

    BOOL Initialize(HANDLE thread, std::wstring app, std::wstring modfolder)
    {
        TCHAR szPath[MAX_PATH];
        if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath)))
        {

            size_t firstUnderscore = app.find('_'), lastUnderscore = app.rfind('_');
            std::wstringstream wss;

            if (modfolder.empty()) 
                 wss << szPath << L"\\Packages\\" << app.substr(0, firstUnderscore) + L"_" + app.substr(lastUnderscore + 1) << L"\\LocalState\\mods\\";
            else wss << (modfolder.ends_with(L"\\") ? modfolder : (modfolder + L"\\"));

            Gravel::MOD_FILES_PATH = wss.str().c_str();
        }

        Gravel::APP_LOCATION = L"C:\\Program Files\\WindowsApps\\" + app;

        if (MH_Initialize() != MH_OK) return FALSE;

        
        BOOL grapple = TRUE;
        grapple &= Attach((LPWSTR)L"KernelBase.dll", "CreateFileW", (LPVOID*)&Gravel::HfnCreateFileW, (LPVOID*)(&(Gravel::pfnCreateFileW)));
        
        
        while (ResumeThread(thread) > 0);

        return grapple;
    }
}
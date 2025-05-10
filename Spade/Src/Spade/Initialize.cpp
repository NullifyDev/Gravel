#include "Initialize.hpp"

namespace Spade {
    void Initialize(std::wstring app, std::wstring modfolder) {
        TCHAR szPath[MAX_PATH];
        if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath)))
        {
            std::wstringstream wss;

            if (modfolder.empty())
                 wss << szPath << L"\\Packages\\" << app.substr(0, app.find('_')) + L"_" + app.substr(app.rfind('_') + 1) << L"\\LocalState\\mods\\";
            else wss << (modfolder.ends_with(L"\\") ? modfolder : (modfolder + L"\\"));

            Spade::MOD_FILES_PATH = wss.str().c_str();
        }
    }
}
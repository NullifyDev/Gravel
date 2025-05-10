#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <Shlobj.h>
#include <string>
#include <roapi.h>

#include "Spade/Initialize.hpp"
#include "Spade/Spade.hpp"
#include "Spade/Grapple.hpp"
#include "Spade/GrappleVars.hpp"
#include "Spade/Util.hpp"

#define EXPORT __declspec(dllexport)

EXPORT void sout_info() {
    printf("sout is Spade's terminal output");
}
EXPORT void sout(const char *msg) {
    printf(msg);
}
EXPORT void soutln(const char* msg) {
    printf("%s\n", msg);
}


int wmain(int argc, wchar_t *argv[])
{
    using namespace Spade;
    printf("CoInitialize: %d\n", Spade::COINITIALIZED);

    //int argc = __argc;
    //wchar_t** argv = __wargv;

    HWND hwnd = 0;
    DWORD pid = 0;
    std::wstring mods = L"", launch = L"";
    LPCWSTR app = L"";

    for (int i = 1; i < argc; i++)
    {
        std::wstring flag = std::wstring(argv[i]).c_str();

        if (wstr_cmp(flag.c_str(), L"mods"))
            mods = argv[++i];

        else if (wstr_cmp(std::wstring(argv[i]).c_str(), L"start"))
            app = argv[++i];
    }  

    if (app != NULL) {
        Spade::Initialize(app, mods);
        printf("LaunchSuspended: ret %d ", Spade::LaunchSuspended(app, &pid));
    }

    CoUninitialize();
    return S_OK;
}


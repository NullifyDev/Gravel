
/* DLL INJECTOR - Inject DLLs during the suspension of the target software */

#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <Shlobj.h>
#include <string>

#include "Utils/Spade.hpp"
#include "Utils/Grapple.hpp"
#include "Utils/GrappleVars.hpp"
#include "Utils/Initialize.hpp"
//#include "Utils/Grapple/Init.hpp"
//#include "Utils/Grapple/Initialize.hpp"

int wmain(int argc, wchar_t *argv[])
{
    //int argc = __argc;
    //wchar_t** argv = __wargv;

    HWND hwnd = 0;
    DWORD pid = 0;

    //std::wstring path(L"C:\\Users\\Saturn\\source\\repos\\Gravel\\x64\\Debug\\Gravel.dll");

    for (int i = 1; i < argc; i++)
    {
        if (std::wcscmp(std::wstring(argv[i]).c_str(), L"start"))
        {
            Spade::Initialize(argv[i]);
            Spade::LaunchSuspended(argv[i], &pid);
        }
    }

    

    // Can do additional error checking to make sure the app is active and not tombstoned

    //ModImporter::InjectMods(dwProcessId);
    //ProcessUtils::ResumeProcess(dwProcessId); // Uses NtResumeProcess

    CoUninitialize();
    return S_OK;
}
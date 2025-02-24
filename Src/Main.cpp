
/* DLL INJECTOR - Inject DLLs during the suspension of the target software */

#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <Shlobj.h>

#include "Gravel/Gravel.hpp"

#define IMPORT extern __declspec(dllimport)

//IMPORT int __argc;
//IMPORT char** __argv;
//IMPORT wchar_t** __wargv;

// Turning this into a normal Windows program so it's invisible when run
int main(int argc, wchar_t *argv[]) // CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Gravel::Init();

    HWND hwnd = 0;
    for (int i = 1; i < argc; i++)
    {
        if (std::wcscmp(argv[i], L"start")) {

            Gravel::LaunchSuspended(hwnd, argv[++i]);
        }
    }

    if (hwnd == 0) return E_FAIL;

    //Gravel::LaunchSuspended(Gravel::GetPkgFullName());


    // Can do additional error checking to make sure the app is active and not tombstoned

    //ModLoader::InjectMods(dwProcessId);
    //ProcessUtils::ResumeProcess(dwProcessId); // Uses NtResumeProcess

    return S_OK;
}
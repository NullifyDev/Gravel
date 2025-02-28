#include "LaunchSuspended.hpp"

namespace Spade {
    HRESULT LaunchSuspended(LPCWSTR appFullName, PDWORD pid)
    {
        printf("LaunchSuspended: hit!\n");

        Spade::Grapple::Initialize(appFullName);

        //appFullName = appFullName == NULL ? Spade::GetPkgFullName(hWnd) : appFullName;
        HRESULT hResult = S_OK;

        // Create a new instance of IPackageDebugSettings
        ATL::CComQIPtr<IPackageDebugSettings> debugSettings;



        hResult = debugSettings.CoCreateInstance(CLSID_PackageDebugSettings, NULL, CLSCTX_ALL);
        if (hResult != S_OK) return hResult;

        hResult = Spade::Launch(appFullName, pid);
        if (hResult != S_OK) return hResult;
        
        

        std::wstringstream wss;
        wss << L"C:\\Users\\Saturn\\source\\repos\\Gravel\\x64\\Debug\\Gravel.exe -p " << *pid << L" mods " << Spade::Grapple::MOD_FILES_PATH;
        LPCWSTR p = wss.str().c_str();

        wprintf(p);
        printf("\n");

        hResult = debugSettings->EnableDebugging(appFullName, p, NULL);
        if (hResult != S_OK) {
            printf("[ERROR]: LaunchSuspended - EnableDebugging: %d", hResult);
            return hResult;
        }
        printf("[DEBUG]: ENABLED!\n");

        // HMODULE hmod = LoadLibraryW(L"C:\\Users\\Saturn\\source\\repos\\Gravel\\x64\\Debug\\Gravel.dll");
        // Spade::Grapple::main gmain = (Spade::Grapple::main)GetProcAddress(hmod, "main");

        /* INJECTION SECTION INJECTION SECTION INJECTION SECTION INJECTION SECTION 
         * INJECTION SECTION INJECTION SECTION INJECTION SECTION INJECTION SECTION
         * INJECTION SECTION INJECTION SECTION INJECTION SECTION INJECTION SECTION */

        hResult = debugSettings->DisableDebugging(appFullName);
        if (hResult != S_OK) return hResult;

        return S_OK;
    }
}
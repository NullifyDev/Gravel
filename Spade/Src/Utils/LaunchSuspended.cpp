#include "LaunchSuspended.hpp"

namespace Spade {
    HRESULT LaunchSuspended(LPCWSTR appFullName, PDWORD pid)
    {
        printf("LaunchSuspended: hit!\n");

        //appFullName = appFullName == NULL ? Spade::GetPkgFullName(hWnd) : appFullName;
        HRESULT hResult = S_OK;

        // Create a new instance of IPackageDebugSettings
        ATL::CComQIPtr<IPackageDebugSettings> debugSettings;



        hResult = debugSettings.CoCreateInstance(CLSID_PackageDebugSettings, NULL, CLSCTX_ALL);
        if (hResult != S_OK) return hResult;

        hResult = Spade::Launch(appFullName, pid);
        if (hResult != S_OK) return hResult;

        std::wstringstream wss;

        wchar_t buffer[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, buffer, MAX_PATH);
        
        std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
        wss << std::wstring(buffer).substr(0, pos).c_str() << L"\\Gravel.exe -p " << *pid << L" mods " << Spade::Grapple::MOD_FILES_PATH;
        std::wstring p = wss.str().c_str();

        wprintf(wss.str().c_str());
        printf("\n");

        hResult = debugSettings->EnableDebugging(appFullName, wss.str().c_str(), NULL);
        printf("LaunchSuspended: hResult: %d\n", hResult);
        if (hResult != S_OK) {
            printf("[ERROR]: LaunchSuspended - EnableDebugging: %d", hResult);
            return hResult;
        }
        printf("[DEBUG]: ENABLED!\n");

        Spade::Grapple::Initialize();

        hResult = debugSettings->DisableDebugging(appFullName);
        if (hResult != S_OK) return hResult;
        printf("[DEBUG]: DISABLED! %d\n", hResult);

        Spade::Grapple::Uninitialize();
        return S_OK;
    }
}
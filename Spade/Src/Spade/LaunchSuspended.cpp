#include "LaunchSuspended.hpp"

namespace Spade
{
    HRESULT LaunchSuspended(LPCWSTR appFullName, PDWORD pid)
    {
        LUID privReq;

        if (COINITIALIZED == NULL)
            COINITIALIZED = CoInitializeEx(NULL, COINIT_MULTITHREADED);

        HRESULT hResult = S_OK;
        ATL::CComQIPtr<IPackageDebugSettings> debugSettings;
        hResult = debugSettings.CoCreateInstance(CLSID_PackageDebugSettings, NULL, CLSCTX_ALL);
        if (hResult != S_OK) return hResult;

        std::wstringstream wss;
        wchar_t buffer[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");

        wss << std::wstring(buffer).substr(0, pos).c_str() << L"\\Gravel.exe modfolder " << Spade::MOD_FILES_PATH;

        hResult = debugSettings->EnableDebugging(appFullName, wss.str().c_str(), NULL);
        if (hResult != S_OK) return hResult;

        hResult = Launch(appFullName, pid);
        if (hResult != S_OK)
            printf("Launch (HMODULE: %d)\n", hResult);

        hResult = debugSettings->DisableDebugging(appFullName);
        printf("LaunchSuspended: debug disabled (%d)\n", hResult);
        if (hResult != S_OK) return hResult;

        return S_OK;
    }
}
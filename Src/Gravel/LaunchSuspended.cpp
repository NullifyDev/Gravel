#include "gravel.h"

namespace Gravel {
    HRESULT LaunchSuspended(HWND hWnd, LPCWSTR appFullName/*, PDWORD pdwProcessId*/)
    {
        using namespace Gravel;

        //appFullName = appFullName == NULL ? Gravel::GetPkgFullName(hWnd) : appFullName;

        HRESULT hResult = S_OK;

        // Create a new instance of IPackageDebugSettings
        ATL::CComQIPtr<IPackageDebugSettings> debugSettings;
        hResult = debugSettings.CoCreateInstance(CLSID_PackageDebugSettings, NULL, CLSCTX_ALL);
        if (hResult != S_OK) return hResult;

        // Enable debugging
        hResult = debugSettings->EnableDebugging(appFullName, NULL, NULL);
        if (hResult != S_OK) return hResult;

        // Launch the application using the function discussed in the Launching a UWP App section
        DWORD dwProcessId = 0;
        hResult = Gravel::Launch(appFullName, &dwProcessId);
        if (hResult != S_OK) return hResult;



        hResult = debugSettings->DisableDebugging(appFullName);
        if (hResult != S_OK) return hResult;

        return S_OK;
    }
}
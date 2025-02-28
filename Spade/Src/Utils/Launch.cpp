#include "Launch.hpp"
#include <string>
#include <iostream>

namespace Spade {
    HRESULT Launch(LPCWSTR packageFullName, PDWORD pdw_pid)
    {
        printf("Launch: hit!\n");
        CComPtr<IApplicationActivationManager> spAppActivationManager;
        HRESULT result = E_INVALIDARG;
        
        result = CoCreateInstance(CLSID_ApplicationActivationManager,
            NULL,
            CLSCTX_LOCAL_SERVER,
            IID_IApplicationActivationManager,
            (LPVOID*)&spAppActivationManager);
        if (!SUCCEEDED(result)) return result;

        result = CoAllowSetForegroundWindow(spAppActivationManager, NULL);
        if (!SUCCEEDED(result)) return result;
        
        DWORD pid = 1;
        std::wstring originalString = std::wstring(packageFullName);


        size_t firstUnderscore = originalString.find('_');
        size_t lastUnderscore = originalString.rfind('_');

        // Extract the needed parts

        // Form the new string
        std::wstring newString = originalString.substr(0, firstUnderscore) + L"_" + originalString.substr(lastUnderscore + 1) + L"!App";
        LPCWSTR t = newString.c_str();

        printf("Launching UWP Software (");
        wprintf(t);
        printf(")\n");
        result = spAppActivationManager->ActivateApplication(t, NULL, AO_NONE, pdw_pid);
        printf("Done! Launch.ActivateApplication: result: %d\n", result);

        return result;
    }
}
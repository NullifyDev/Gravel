#include "Launch.hpp"
#include <string>
#include <iostream>

namespace Spade 
{
    HRESULT Launch(LPCWSTR packageFullName, PDWORD pid)
    {
        if (COINITIALIZED == NULL && COINITIALIZED != S_OK)
            COINITIALIZED =  CoInitializeEx(NULL, COINIT_MULTITHREADED);

        CComPtr<IApplicationActivationManager> spAppActivationManager;
        HRESULT result = S_OK;

        result = CoCreateInstance(CLSID_ApplicationActivationManager, NULL, CLSCTX_LOCAL_SERVER, IID_IApplicationActivationManager, (LPVOID*)&spAppActivationManager);
        if (!SUCCEEDED(result)) return result;

        result = CoAllowSetForegroundWindow(spAppActivationManager, NULL);


        if (!SUCCEEDED(result)) return result;

        std::wstring originalString = std::wstring(packageFullName);
        // std::wstring newString = originalString.substr(0, originalString.find('_')) + L"_" + originalString.substr(originalString.rfind('_') + 1) + L"!App";

        result = spAppActivationManager->ActivateApplication((originalString.substr(0, originalString.find('_')) + L"_" + originalString.substr(originalString.rfind('_') + 1) + L"!App").c_str(), NULL, AO_NONE, pid);
        return result;
    }
}
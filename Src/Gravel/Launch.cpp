#include "Launch.hpp"

namespace Gravel {
    HRESULT Launch(HWND hWnd, LPCWSTR fullname, PDWORD pdwProcessId)
    {
        fullname = fullname == NULL ? Gravel::GetPkgFullName(hWnd) : fullname;

        CComPtr<IApplicationActivationManager> spAppActivationManager;
        HRESULT result = E_INVALIDARG;

        result = CoCreateInstance(CLSID_ApplicationActivationManager, NULL, CLSCTX_LOCAL_SERVER, IID_IApplicationActivationManager, (LPVOID*)&spAppActivationManager);

        if (!SUCCEEDED(result)) return result;
        result = CoAllowSetForegroundWindow(spAppActivationManager, NULL);


        if (!SUCCEEDED(result)) return result;
        result = spAppActivationManager->ActivateApplication(fullname, NULL, AO_NONE, pdwProcessId);

        return result;
    }
}
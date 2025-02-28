#include "GetPkgFullName.hpp"
#include <iostream>

namespace Spade {
    LPCWSTR GetPkgFullName(HWND hWnd) {
        printf("GetPkgFullName: hit!\n");

        UINT32 len = 0;
        PWSTR fullName = (PWSTR)malloc(len * sizeof(*fullName));
        LONG res = GetCurrentPackageFullName(&len, fullName);

        while (res != ERROR_SUCCESS) {
            switch (res) {
            case ERROR_INSUFFICIENT_BUFFER:
                len++;
                GetCurrentPackageFullName(&len, fullName);
                break;
            case APPMODEL_ERROR_NO_PACKAGE:
                MessageBoxW(hWnd, _T("APPMODEL_ERROR_NO_PACKAGE"), _T("There is no package name for this softawre - aborting"), 0x00000000L);
                return NULL;
            default:
                return NULL;
            }
        }
        return NULL;
    }
}
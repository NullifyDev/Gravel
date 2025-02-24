#pragma once

#include <Windows.h>
#include <atlbase.h>

#include "../gravel.hpp"

namespace Gravel {
    namespace Grapple {
        HANDLE HfnCreateFileW(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate);
    }
}
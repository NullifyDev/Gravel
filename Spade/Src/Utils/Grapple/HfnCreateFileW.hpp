#pragma once

#include <Windows.h>
#include <atlbase.h>

#include "../Spade.hpp"
#include "../GrappleVars.hpp"

namespace Spade {
    namespace Grapple {
        HANDLE WINAPI HfnCreateFileW(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate);
    }
}
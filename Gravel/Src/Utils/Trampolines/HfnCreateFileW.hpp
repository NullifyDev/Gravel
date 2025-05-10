#pragma once

#include <Windows.h>
#include <atlbase.h>

#include "../GrappleVars.hpp"

namespace Gravel {
    HANDLE WINAPI HfnCreateFileW(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate);
}
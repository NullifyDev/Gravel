#pragma once

#include <windows.h>

#include "Set.hpp"

namespace Gravel {
    BOOL Attach(LPWSTR wstrModule, LPCSTR strFunction, LPVOID* grapple, LPVOID* original);
}
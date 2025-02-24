#pragma once

#include <windows.h>
#include <MinHook.h>
#include <cstring>

#include "../GrappleVars.hpp"
#include "HfnCreateFileW.hpp"

namespace Gravel {
    namespace Grapple {
        BOOL Initialize();
    }
}
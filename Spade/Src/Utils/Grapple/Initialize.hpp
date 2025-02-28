#pragma once

#include <windows.h>
#include <MinHook.h>
#include <cstring>

#include "../GrappleVars.hpp"
#include "HfnCreateFileW.hpp"
#include "Attach.hpp"

namespace Spade {
    namespace Grapple {
        BOOL Initialize(std::wstring app);
    }
}
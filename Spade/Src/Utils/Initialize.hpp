#pragma once

#include <windows.h>
#include <cstring>

#include "GrappleVars.hpp"
#include "Grapple/HfnCreateFileW.hpp"
#include "Grapple/Attach.hpp"

namespace Spade {
    BOOL Initialize(std::wstring app);
}
#pragma once

#include <Windows.h>
#include <MinHook.h>
#include <cstring>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <tchar.h>
#include <ShlObj.h>

#include "GrappleVars.hpp"
#include "Util.hpp"

namespace Spade {
    void Initialize(std::wstring app, std::wstring modfolder);
}
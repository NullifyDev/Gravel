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
#include "Trampolines/HfnCreateFileW.hpp"
#include "Trampolines/IGPLib.hpp"
#include "Attach.hpp"
#include "Util.hpp"

namespace Gravel {
    inline HMODULE igplib;
    BOOL Initialize(HANDLE thread, std::wstring app, std::wstring modfolder);
}
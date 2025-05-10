#pragma once

#include <Windows.h>
#include <MinHook.h>
#include <ShlObj.h>
#include <string>
#include <sstream>
#include <winuser.h>

#include "Launch.hpp"
#include "GrappleVars.hpp"

namespace Spade 
{
    HRESULT LaunchSuspended(LPCWSTR appFullName, PDWORD pid);
}
#pragma once

#include <Windows.h>
#include <MinHook.h>
#include <ShlObj.h>

#include "Launch.hpp"

namespace Gravel {
    HRESULT LaunchSuspended(HWND hWnd, LPCWSTR appFullName/*, PDWORD pdwProcessId*/);
}
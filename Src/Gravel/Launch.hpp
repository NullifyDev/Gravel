#pragma once

#include <windows.h>
#include <ShlObj.h>
#include <cstringt.h>

#include "GetPkgFullName.hpp"

namespace Gravel 
{
    HRESULT Launch(HWND hWnd, LPCWSTR fullname, PDWORD pdwProcessId);
}

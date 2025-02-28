#pragma once

#include <windows.h>
#include <ShlObj.h>
#include <cstringt.h>
#include <string>
#include <iostream>

#include "GetPkgFullName.hpp"

namespace Spade 
{
    HRESULT Launch(LPCWSTR packageFullName, PDWORD pid);
}

#pragma once

#include <Windows.h>
#include <cstring>
#include <string>
#include <sddl.h>
#include <accctrl.h>
#include <aclapi.h>

DWORD SetPermToPath(std::wstring wstrFilePath);
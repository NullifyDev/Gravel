#include <iostream>
#include <windows.h>
#include <wrl/client.h>
#include <wchar.h>
#include <string.h>

#include "gravel.h"

using namespace Microsoft::WRL;
// using namespace Gravel;


//std::string GetAppFullName(wchar_t *packageName)
//{
//    UINT32 ui = static_cast<UINT32>(wcslen(packageName));
//    GetPackageFullName(0, &ui, PWSTR(packageName));
//    return std::string(.begin(), fullWideName.end());
//}
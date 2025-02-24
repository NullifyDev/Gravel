#pragma once 

#include <windows.h>
#include <string>

namespace Gravel {
	namespace Grapple {
		void _Cleanup(PWSTR* fullNames, PWSTR buffer, UINT32* properties);
		std::wstring PackageFullNameFromFamilyName(std::wstring familyName);
	}
}
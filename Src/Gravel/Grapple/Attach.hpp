#pragma once

#include <windows.h>

#include "Set.hpp"

namespace Gravel {
	namespace Grapple {
		BOOL Attach(LPWSTR wstrModule, LPCSTR strFunction, LPVOID* hook, LPVOID* original);
	}
}
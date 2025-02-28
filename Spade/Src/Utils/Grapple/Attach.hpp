#pragma once

#include <windows.h>

#include "Set.hpp"

namespace Spade {
	namespace Grapple {
		BOOL Attach(LPWSTR wstrModule, LPCSTR strFunction, LPVOID* hook, LPVOID* original);
	}
}
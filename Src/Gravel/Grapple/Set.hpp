#pragma once

#include <windows.h>
#include <MinHook.h>

namespace Gravel {
	namespace Grapple {
		BOOL Set(LPVOID* origAddress, LPVOID* hookFunction, LPVOID* trampFunction);
	}
}
#pragma once

#include <windows.h>
#include <MinHook.h>

namespace Spade {
	namespace Grapple {
		BOOL Set(LPVOID* origAddress, LPVOID* hookFunction, LPVOID* trampFunction);
	}
}
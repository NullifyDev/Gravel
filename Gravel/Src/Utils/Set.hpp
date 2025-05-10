#pragma once

#include <windows.h>
#include <MinHook.h>
#include <iostream>

namespace Gravel {
	BOOL Set(LPVOID* origAddress, LPVOID* grappleFunction, LPVOID* trampFunction);
}
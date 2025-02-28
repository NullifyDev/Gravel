#pragma once

#include <Windows.h>
#include <tchar.h>
#include <iostream>

namespace Spade {
	namespace Grapple {
		BOOL CALLBACK EnumWindowsProcMy(HWND hwnd, LPARAM lParam);
		void GetHwndByProcessId(DWORD processId, HWND hwnd);
	}
}
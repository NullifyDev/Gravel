#include "GetHwndByProcessId.hpp"

namespace Spade {
	namespace Grapple {

        BOOL CALLBACK EnumWindowsProcMy(HWND hwnd, LPARAM lParam)
        {
            DWORD lpdwProcessId;
            GetWindowThreadProcessId(hwnd, &lpdwProcessId);
            return !(lpdwProcessId == lParam);
        }

        void GetHwndByProcessId(DWORD processId, HWND hwnd)
        {
            EnumWindows(EnumWindowsProcMy, processId);
        }
	}
}
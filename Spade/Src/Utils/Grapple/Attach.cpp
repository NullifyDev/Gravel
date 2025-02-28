#include "Attach.hpp"

namespace Spade {
	namespace Grapple {
		BOOL Attach(LPWSTR wstrModule, LPCSTR strFunction, LPVOID* grapple, LPVOID* original)
		{
			HMODULE hModule = GetModuleHandle(wstrModule);
			if (hModule == NULL)
				return FALSE;

			FARPROC hFunction = GetProcAddress(hModule, strFunction);
			if (hFunction == NULL)
				return FALSE;

			return Set((LPVOID*)hFunction, grapple, original);
		}
	}
}
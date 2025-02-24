#include "Attach.hpp"

namespace Gravel {
	namespace Grapple {
		BOOL Attach(LPWSTR wstrModule, LPCSTR strFunction, LPVOID* hook, LPVOID* original)
		{
			HMODULE hModule = GetModuleHandle(wstrModule);
			if (hModule == NULL) return FALSE;

			FARPROC hFunction = GetProcAddress(hModule, strFunction);
			if (hFunction == NULL) return FALSE;

			return Set((LPVOID*)hFunction, hook, original);
		}
	}
}
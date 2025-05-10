#include "Attach.hpp"

namespace Gravel {
	BOOL Attach(LPWSTR wstrModule, LPCSTR strFunction, LPVOID* grapple, LPVOID* original)
	{		
		HMODULE hModule = GetModuleHandle(wstrModule);
		if (hModule == NULL) {
			printf("Gravel::Grapple::Attach(%s): GetModuleHandle(): hmodule is not found (NULL)\n", wstrModule);
			return FALSE;
		}
		FARPROC hFunction = GetProcAddress(hModule, strFunction);
		if (hFunction == NULL) return FALSE;

		return Set((LPVOID*)hFunction, grapple, original);
	}
}
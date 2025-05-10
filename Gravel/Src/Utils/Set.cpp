#include "Set.hpp"

namespace Gravel {
	BOOL Set(LPVOID* origAddress, LPVOID* grappleFunction, LPVOID* trampFunction)
	{
		MH_STATUS mhs = MH_CreateHook(origAddress, grappleFunction, reinterpret_cast<LPVOID*>(trampFunction));
		if (mhs != MH_OK) return FALSE;

		mhs = MH_EnableHook(origAddress);
		if (mhs != MH_OK) return FALSE;

		return TRUE;
	}
}
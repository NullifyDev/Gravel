#include "Set.hpp"

namespace Spade {
	namespace Grapple {
		BOOL Set(LPVOID* origAddress, LPVOID* grappleFunction, LPVOID* trampFunction)
		{
			if (MH_CreateHook(origAddress, grappleFunction, reinterpret_cast<LPVOID*>(trampFunction)) != MH_OK)
				return FALSE;

			if (MH_EnableHook(origAddress) != MH_OK)
				return FALSE;

			return TRUE;
		}
	}
}
#include "Set.hpp"

namespace Gravel {
	namespace Grapple {
		BOOL Set(LPVOID* origAddress, LPVOID* hookFunction, LPVOID* trampFunction)
		{
			if (MH_CreateHook(origAddress, hookFunction, reinterpret_cast<LPVOID*>(trampFunction)) != MH_OK)
				return FALSE;

			if (MH_EnableHook(origAddress) != MH_OK)
				return FALSE;

			return TRUE;
		}
	}
}
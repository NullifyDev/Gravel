#include "Initialize.hpp"

namespace Spade {
    namespace Grapple {
        BOOL Initialize()
        {
            printf("Spade::Grapple::Initialize: hit!\n");
            if (MH_Initialize() != MH_OK) return FALSE;

            BOOL grapple = TRUE;
            grapple &= Attach((LPWSTR)L"KernelBase.dll", "CreateFileW", (LPVOID*)&Spade::Grapple::HfnCreateFileW, (LPVOID*)(&(Spade::Grapple::pfnCreateFileW)));
            printf("Initialize: grapple: %d\n", grapple);
            return grapple;
        }
    }
}
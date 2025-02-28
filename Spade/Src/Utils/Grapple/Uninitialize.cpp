#include "Uninitialize.hpp"

namespace Spade {
    namespace Grapple {
        BOOL Uninitialize()
        {
            CoUninitialize();
            return MH_Uninitialize() == MH_OK;
        }
    }
}
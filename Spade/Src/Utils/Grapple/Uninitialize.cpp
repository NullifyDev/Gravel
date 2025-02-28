#include "Uninitialize.hpp"

namespace Spade {
    namespace Grapple {
        BOOL Uninitialize()
        {
            return MH_Uninitialize() == MH_OK;
        }
    }
}
#include "Uninitialize.hpp"

namespace Gravel {
    namespace Grapple {
        BOOL Uninitialize()
        {
            return MH_Uninitialize() == MH_OK;
        }
    }
}
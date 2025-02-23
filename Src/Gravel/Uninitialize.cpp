#include "gravel.h"

namespace Gravel {
    namespace Grapple {
        BOOL Uninitialize()
        {
            return MH_Uninitialize() == MH_OK;
        }
    }
}
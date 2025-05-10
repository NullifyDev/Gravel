#include "Uninitialize.hpp"

namespace Gravel {
    BOOL Uninitialize()
    {
        return MH_Uninitialize() == MH_OK;
    }
}
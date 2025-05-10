#include "tAddIGPComponent.hpp"

namespace IGPLib
{
    namespace Trampoline {
        void tAddIGPComponent(const char* component) {
            printf("%s\n", component);
            AddIGPComponent(component);
        }
    };
};
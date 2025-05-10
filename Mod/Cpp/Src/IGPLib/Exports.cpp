#include "Exports.hpp"

namespace IGPLib {
    void Import() {
        Sleep(1000);
        IGPLibDLL = GetModuleHandleA("IGPLib_Windows_8");
        printf("IGPLibDLL: %d\n", IGPLibDLL);
        AddIGPComponent = (_AddIGPComponent)GetProcAddress(IGPLibDLL, "AddIGPComponent");
    }
}
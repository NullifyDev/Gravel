#pragma once

#include <Windows.h>
#include <stdio.h>

namespace IGPLib {
    inline HMODULE IGPLibDLL;
    
    typedef void (*_AddIGPComponent)(const char*);

    inline _AddIGPComponent AddIGPComponent;
    

    void Import();
}
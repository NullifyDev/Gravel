
/* THIS IS THE FILE THAT NEEDS TO BE INJECTED
 THIS IS THE FILE THAT NEEDS TO BE INJECTED */
/*
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>

#include "Gravel/gravel.h"

std::ofstream file;

void log(const char* msg, ...) {
    std::ostringstream oss;
    oss << msg;

    if (file.is_open()) {
        file << oss.str().c_str();
    }
    else {
        file.open("%LOCALAPPDATA%\\Packages\\GAMELOFTSA.Asphalt8Airborne_0pp20fcewvvtj\\AC\\log.txt", std::ios_base::app);
        log(msg);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    log("Launched");
    switch (ul_reason_for_call)
    {
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:  
            break;

        case DLL_PROCESS_ATTACH:
            log("PID: %s", GetCurrentProcessId());

            BOOL init = Gravel::Grapple::Initialize();
            log("%s (", init == TRUE ? "true" : (init == FALSE ? "false" : "error?"));
            log("%d)\n", init);

            file.close();
            break;

        case DLL_PROCESS_DETACH:
            Gravel::Grapple::Uninitialize();
            break;
    }
    return TRUE;
} 
*/
//#include <Windows.h>
//#include <ShObjIdl.h>
//#include <atlbase.h>
//#include <appmodel.h>
//#include <string>
//#include <io.h>
//#include <fcntl.h>

#define EXPORT extern "C" __declspec(dllexport)

//void InitConsole() {
//    AllocConsole();
//    SetConsoleTitleA("Mod.dll");
//    typedef struct { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; } FILE_COMPLETE;
//    *(FILE_COMPLETE*)stdout = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT), "w");
//    *(FILE_COMPLETE*)stderr = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_ERROR_HANDLE), _O_TEXT), "w");
//    *(FILE_COMPLETE*)stdin = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_INPUT_HANDLE), _O_TEXT), "r");
//    setvbuf(stdout, NULL, _IONBF, 0);
//    setvbuf(stderr, NULL, _IONBF, 0);
//    setvbuf(stdin, NULL, _IONBF, 0);
//}

EXPORT int ModMain(void) {
    return 0;
}

//int __cdecl wmain(int argc, WCHAR* argv[])
//{
//    if (argc != 2) return 1;
//
//    wprintf(L"PackageId: %s", argv[1]);
//
//    // Initialize COM objects
//    if (SUCCEEDED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED)))
//    {
//        // Create a new instance of IPackageDebugSettings
//        ATL::CComQIPtr<IPackageDebugSettings> debugSettings;
//        DWORD hResult = debugSettings.CoCreateInstance(CLSID_PackageDebugSettings, NULL, CLSCTX_ALL);
//        if (hResult != S_OK) return hResult;
//
//        PACKAGE_EXECUTION_STATE state;
//
//        // Get the execution state of the app and store it in state
//        hResult = debugSettings->GetPackageExecutionState(argv[1], &state);
//        if (hResult != S_OK) return hResult;
//
//        // Convert the PES to a string
//        std::wstring str;
//        switch (state) {
//        case PES_RUNNING:
//            str = L"Running"; break;
//        case PES_SUSPENDING:
//            str = L"Suspending"; break;
//        case PES_SUSPENDED:
//            str = L"Suspended"; break;
//        case PES_TERMINATED:
//            str = L"Terminated"; break;
//        case PES_UNKNOWN:
//            str = L"Unknown"; break;
//        default:
//            str = L"Uknown Execution State: " + std::to_wstring((int)state); break;
//        }
//
//        // Show a message box dialog with the execution state
//        MessageBox(NULL, str.c_str(), L"Execution State", MB_OK);
//    }
//    return 0;
//}
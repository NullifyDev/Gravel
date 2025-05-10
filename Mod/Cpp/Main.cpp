#include <Windows.h>
#include <ShObjIdl.h>
#include <atlbase.h>
#include <appmodel.h>
#include <string>
#include <io.h>
#include <fcntl.h>

#include <winrt/base.h>
#include <winrt/Windows.UI.Xaml.h>

#include "winrt/windows.ui.xaml.markup.h"
#include <windows.ui.xaml.h>

#define EXPORT extern "C" __declspec(dllexport)
#define IMPORT __declspec(dllimport)

#include <typeinfo>
#include <iostream>
#include <shlobj.h>
#include <tchar.h>
#include <winuser.h>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <vector>
#include <cstring>
#include <future>
#include <chrono>

#include "mscoree.h"
#include <winrt/windows.foundation.h>

const char* strfmt(const char* format, ...) {
    va_list args;
    va_start(args, format);

    int len = sprintf_s(nullptr, 0, format, args);
    char* str = new char[len + 1];
    vsnprintf(str, len + 1, format, args);

    va_end(args);
    return str;
}

void InitConsole() {
    AllocConsole();
    SetConsoleTitleA("Mod.dll");
    typedef struct { char* _ptr; int _cnt; char* _base; int _flag; int _file; int _charbuf; int _bufsiz; char* _tmpfname; } FILE_COMPLETE;
    *(FILE_COMPLETE*)stdout = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT), "w");
    *(FILE_COMPLETE*)stderr = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_ERROR_HANDLE), _O_TEXT), "w");
    *(FILE_COMPLETE*)stdin = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_INPUT_HANDLE), _O_TEXT), "r");
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

__declspec(dllexport) int ModMain(HWND gHwnd, HANDLE gThread, HANDLE gHandle)
{
    using namespace winrt;
    using namespace winrt::Windows;
    using namespace winrt::Windows::UI;
    using namespace winrt::Windows::Foundation;

    MessageBoxA(NULL, "ModMain: Running", "Mod.dll", MB_OK);
    InitConsole();

    auto currentPage = winrt::unbox_value<Windows::UI::Xaml::UIElement>(Xaml::Window::Current().Content());
    if (currentPage.try_as<Xaml::Controls::Page>())
    {
        Xaml::Controls::Page page = currentPage.as<Xaml::Controls::Page>();

        Numerics::float2 size = page.ActualSize(),
                                prevSize;
        while (true) {
            size = page.ActualSize();
            
            if(size != prevSize)
                printf("page.size: %d:%d\n", size.x, size.y);
    
            prevSize = size;
        }
        MessageBoxA(NULL, "the current page is grabbed", "Mod.dll", MB_OK);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    std::wstring app, modfolder;
    DWORD pid = 0;

    printf("\e");

    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH: {
            printf("\nMod.dll: Process Attached!\n");
            break;
        }
        case DLL_THREAD_ATTACH:
            printf("\nMod.dll: Thread Attached!\n");
            break;
        case DLL_THREAD_DETACH:
            printf("\nMod.dll: Thread Detached!\n");

            break;
        case DLL_PROCESS_DETACH:
            printf("\nMod.dll: Process Detached!\n");
            break;
    }
    return TRUE;
}

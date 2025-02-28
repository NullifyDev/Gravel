
/* DLL INJECTOR - Inject DLLs during the suspension of the target software */

#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <Shlobj.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <stdio.h>
#include <malloc.h>
#include <io.h>
#include <fcntl.h>

namespace fs = std::filesystem;

#define IMPORT extern __declspec(dllimport)

typedef int(*ModMain)(void); //int (*ModMain)(int, char**);

typedef struct ModEntry {
    HMODULE hmod;
    ModMain func;
    /* To be added:
    char *args; 

    // [Planned Mod File Structure] ModFolder: { Mod.dll, Mod.conf }
    */
} ModEntry;

IMPORT int __argc;
IMPORT char** __argv;
//IMPORT wchar_t** __wargv;

// Turning this into a normal Windows program so it's invisible when run
//CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)


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

BOOL str_cmp(const char* s1, const char* s2) {
    size_t len = strlen(s1);
    if (len != strlen(s2)) return FALSE;

    int i = -1;
    while (i++ < len) 
        if (s1[i] != s2[i]) 
            return FALSE;

    return TRUE;
}

BOOL str_endswith(const char* s1, const char* s2) {
    size_t len = strlen(s1), len2 = strlen(s2);
    if (len < len2) return FALSE;

    int i = len-len2-1, j = 0, k = 0;
    while (i++ < len)
        if (s1[i] != s2[j++])
            return FALSE;

    return TRUE;
}

// BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
int main(int argc, char *argv[]) 
{
    InitConsole();
    
    HWND hwnd = 0;
    std::string modsfolder;
    DWORD pid = 0;

    //int argc = __argc;
    //char** argv = __argv;

    printf("[GRAVEL]: LAUNCHED!\a \n");
    GetWindowThreadProcessId(hwnd, &pid);

    for (int i = 1; i < __argc; i++)
    {
        if (str_cmp(__argv[i], "-p")) {
            pid = atoi(__argv[++i]);
        }
        else if (str_cmp(__argv[i], "mods")) {
            modsfolder = __argv[++i];
            printf("[Mods Imported]\n");

            int modcount = 0, i = 0;
            for (const auto& entry : fs::directory_iterator(modsfolder))
                if (str_endswith(entry.path().string().c_str(), ".dll"))
                    modcount++;

            ModEntry* modlist = (ModEntry*)calloc(sizeof(ModEntry), modcount);

            for (const auto& entry : fs::directory_iterator(modsfolder)) {
                fs::path p = entry.path();
                HMODULE hModule = 0;
                ModMain procAddress = 0;
                if (p.extension() == ".dll") {
                    hModule = LoadLibraryW(p.c_str());
                    procAddress = (ModMain)GetProcAddress(hModule, "ModMain");

                    if (procAddress == 0) modcount--;
                    else modlist[i++] = { hModule, procAddress };
                }
            }

            i = -1;
            while (++i < modcount) {
                modlist[i].func();
            }
        }
    }
    return S_OK;
}

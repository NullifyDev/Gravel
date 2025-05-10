#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <Shlobj.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <stdio.h>
#include <malloc.h>

#include "Utils.hpp"

namespace fs = std::filesystem;

#define IMPORT __declspec(dllimport)
#define EXPORT __declspec(dllexport)

typedef NTSTATUS(NTAPI* pNtResumeProcess)(HANDLE ProcessHandle);
typedef NTSTATUS(NTAPI* pNtResumeThread)(HANDLE ProcessHandle);
typedef NTSTATUS(WINAPI* pNtQuerySystemInformation)(int, PVOID, ULONG, PULONG);

typedef void(*ModMain)(HWND gHwnd, HANDLE gThread, HANDLE gHandle);

class NT {
public:
    
    pNtResumeProcess ResumeProcess;
    pNtResumeThread ResumeThread;
    pNtQuerySystemInformation QuerySystemInformation;

    NT()
    {
        ResumeProcess          = (pNtResumeProcess)         GetProcAddress(GetModuleHandleA("NtDll.dll"), "NtResumeProcess");
        ResumeThread           = (pNtResumeThread)          GetProcAddress(GetModuleHandleA("NtDll.dll"), "NtResumeThread");
        QuerySystemInformation = (pNtQuerySystemInformation)GetProcAddress(GetModuleHandleA("NtDll.dll"), "NtQuerySystemInformation");

        if (!ResumeProcess)          printf("Failed to get NtResumeProcess\n");
        if (!ResumeThread)           printf("Failed to get NtResumeThread\n");
        if (!QuerySystemInformation) printf("Failed to get NtQuerySystemInformation\n");
    }
};

typedef struct ModEntry {
    HMODULE hmod;
    ModMain func;
    /* To be added:
    char *args; 

    // [Planned Mod File Structure] ModFolder: { Mod.dll, Mod.conf }
    */
} ModEntry;

typedef struct ModEntries {
    int Count;
    ModEntry* Entry;
} ModEntries;

IMPORT int __argc;
IMPORT wchar_t** __wargv;

int wmain(int argc, wchar_t** argv) {
    SetConsoleTitleA("Gravel.exe");
    printf("Initializing!\n");

    using namespace Gravel;
    std::wstring app, modfolder, args;
    DWORD pid = 0, tid = 0, parentPid;
    HANDLE hGame = 0, tGame = 0, hParent = 0;

    for (int i = 1; i < argc; i++) 
    {
        if (wstr_cmp(argv[i], L"-p")) {
            pid = _wtol(argv[++i]);
            printf("-p: %d\n", pid);
            hGame = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
            //printf("pid %d | \n", pid);
        }
        else if (wstr_cmp(argv[i], L"-tid")) {
            tid = _wtol(argv[i]);
            printf("-tid: %d\n", tid);
            tGame = OpenThread(THREAD_RESUME, TRUE, tid);
        }
        else if (wstr_cmp(argv[i], L"app")) {

            app = argv[++i];
            // printf("app %ws\n", app.c_str());
        }
        else if (wstr_cmp(argv[i], L"modfolder")) {
            modfolder = argv[++i];
            // printf("modfolder %ws\n", modfolder.c_str());
        }
        else 
        {
            printf("[Gravel]: Unknown Argument %ws %ws\n", argv[i], argv[++i]);
        }
    }

    HANDLE phGame = OpenProcess(PROCESS_SUSPEND_RESUME, FALSE, pid);
    NT *nt = new NT();

    nt->ResumeProcess(phGame);

    printf("[Loading DLLs]\n");

    ModEntries modlist;
    modlist.Count = 0;

    printf("\nDLLs Found:\n");
    for (const auto& entry : fs::directory_iterator(fs::path(modfolder.c_str()).native())) {
        printf("%ws\n", entry.path().c_str());
        modlist.Count++;
    }
    modlist.Entry = new ModEntry[modlist.Count];
    
    int i = 0;
    for (const auto& entry : fs::directory_iterator(modfolder)) {
        const wchar_t* path = entry.path().c_str();
        modlist.Entry[i].hmod = LoadLibraryW(path);
        if (!modlist.Entry[i].hmod) {
            printf("Failed to Load Library %ws\n", entry.path().c_str());
        }

        ModMain modmain = (ModMain)GetProcAddress(modlist.Entry->hmod, "ModMain");
        if (modmain == NULL) {
            printf("Failed to load \"%ws\"\n", path);
        }
        modlist.Entry->func = modmain;
    }

    BOOL res = Gravel::Initialize(tGame, app, modfolder);

    return TRUE;
}
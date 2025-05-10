#include "Util.hpp"

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <psapi.h>
#include <tlhelp32.h>

namespace Gravel {
    size_t wstr_len(const wchar_t* s) {
        size_t len = 0;
        while (s[len] != '\0') len++;
        return len;
    }

    size_t str_len(const char* s) {
        size_t len = 0;
        while (s[len] != '\0') len++;
        return len;
    }

    BOOL wstr_cmp(const wchar_t* s1, const wchar_t* s2) {
        size_t len = wstr_len(s1);
        if (len != wstr_len(s2)) return FALSE;

        size_t i = 0;
        while (i < len)
            if (s1[i] != s2[i++])
                return FALSE;

        return TRUE;
    }

    BOOL str_cmp(const char* s1, const char* s2) {
        size_t len = str_len(s1), len2 = str_len(s2);
        if (len != str_len(s2))   return FALSE;
        if (len < 1 || len2 < 1) return FALSE;

        size_t i = 0;
        while (i < len)
            if (s1[i] != s2[i++])
                return FALSE;

        return TRUE;
    }

    BOOL str_endswith(const char* s1, const char* s2) {
        size_t len = str_len(s1), len2 = str_len(s2);
        if (len < len2) return FALSE;
        if (len != str_len(s2))   return FALSE;
        if (len < 1 || len2 < 1) return FALSE;

        size_t i = len - len2 - 1, j = 0, k = 0;
        while (i < len)
            if (s1[i++] != s2[j++])
                return FALSE;

        return TRUE;
    }

    BOOL wstr_endswith(const wchar_t* s1, const wchar_t* s2) {
        size_t len = wstr_len(s1), len2 = wstr_len(s2);
        if (len < len2) return FALSE;
        if (len != wstr_len(s2))   return FALSE;
        if (len < 1 || len2 < 1) return FALSE;

        size_t i = len - len2 - 1, j = 0, k = 0;
        while (i < len)
            if (s1[i++] != s2[j++])
                return FALSE;

        return TRUE;
    }
}


// EXTERNAL CODE
//void EnumAllProcesses(PWCHAR exeName, BOOL bTryToOpen = FALSE,
//    DWORD dwAccess = PROCESS_QUERY_INFORMATION)
//{
//    PROCESSENTRY32 entry;
//    entry.dwSize = sizeof(PROCESSENTRY32);
//
//    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
//
//    if (snapshot == INVALID_HANDLE_VALUE)
//    {
//        _tprintf(_T("Unable to create a ToolHelp32 snapshot (%08X)\n"), GetLastError());
//        return;
//    }
//
//    if (Process32First(snapshot, &entry) == TRUE)
//    {
//        do
//        {
//            if (entry.szExeFile != exeName) continue;
//
//            _tprintf(_T("Process: %s (%u)\n"), entry.szExeFile, entry.th32ProcessID);
//
//            if (bTryToOpen)
//            {
//                HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION,
//                    FALSE,
//                    entry.th32ProcessID);
//
//                _tprintf(_T("    hProcess = %p (%08X)\n"), hProcess, GetLastError());
//
//                if (hProcess != NULL)
//                    CloseHandle(hProcess);
//            }
//        } while (Process32Next(snapshot, &entry) == TRUE);
//    }
//
//    CloseHandle(snapshot);
//}
#pragma once

#include <Windows.h>

namespace Spade {
    size_t  str_len(const char* s);
    BOOL    str_cmp(const char* s1, const char* s2);
    BOOL    str_endswith(const char* s1, const char* s2);

    size_t wstr_len(const wchar_t* s);
    BOOL   wstr_cmp(const wchar_t* s1, const wchar_t* s2);
    BOOL   wstr_endswith(const wchar_t* s1, const wchar_t* s2);

    bool isRunning(LPCSTR pName);
}
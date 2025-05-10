#include "Util.hpp"

namespace Spade {
    size_t wstr_len(const wchar_t* s) 
    {
        size_t len = 0;
        while (s[len] != '\0') len++;
        return len;
    }

    size_t str_len(const char* s) 
    {
        size_t len = 0;
        while (s[len] != '\0') len++;
        return len;
    }

    BOOL wstr_cmp(const wchar_t* s1, const wchar_t* s2) 
    {
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

    bool isRunning(LPCSTR pName)
    {
        return FindWindowA(NULL, pName) != 0;
    }

}
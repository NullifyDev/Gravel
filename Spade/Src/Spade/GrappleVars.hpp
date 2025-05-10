#pragma once
#include <windows.h>
#include <string>

namespace Spade 
{
	typedef struct Params {
		size_t len;
		void** arr;
	} Params;
	inline HRESULT COINITIALIZED = NULL;
	inline std::wstring MOD_FILES_PATH = L"";
}
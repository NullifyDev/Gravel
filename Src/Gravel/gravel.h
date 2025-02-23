#ifndef GRAVEL
#define GRAVEL

#include <windows.h>
#include <atlbase.h>
#include <Shlobj.h>
#include <appmodel.h>
#include <iostream>
#include <string>
#include <tchar.h>

#include "MinHook.h"

namespace Gravel
{
	void Init();
	HRESULT Launch(LPCWSTR packageFullName, PDWORD pdwProcessId);
	HRESULT LaunchSuspended(HWND hWnd, LPCWSTR appFullName);
	LPCWSTR GetPkgFullName(HWND hWnd);
	// HRESULT Resume(LPCWSTR packageFullName, PDWORD exePath)
	namespace Grapple
	{
		typedef HANDLE(WINAPI* PfnCreateFileW)(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate);
		PfnCreateFileW pfnCreateFileW;

		std::wstring MOD_FILES_PATH;
		std::wstring APP_LOCATION;

		BOOL Set(LPVOID* origAddress, LPVOID* hookFunction, LPVOID* trampFunction);
		BOOL Attach(LPWSTR wstrModule, LPCSTR strFunction, LPVOID* hook, LPVOID* original);

		BOOL Initialize();
		BOOL Uninitialize();
		int  Update();
		
		HANDLE WINAPI HfnCreateFileW(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate);

		//std::wstring AppIdFromFullName(std::wstring fullName);
		//std::wstring PackageFullNameFromFamilyName(std::wstring familyName);
	};
};

#endif
//#include <Windows.h>
//#include <ShObjIdl.h>
//#include <atlbase.h>
//#include <appmodel.h>
//#include <string>
//
//int __cdecl wmain(int argc, WCHAR* argv[]) {
//	if (argc != 2)
//		return 1;
//
//	wprintf(L"PackageId: %s", argv[1]);
//
//	if (SUCCEEDED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED)))
//	{
//		ATL::CComQIPtr<IPackageDebugSettings> debugSettings;
//		DWORD hResult = debugSettings.CoCreateInstance(CLSID_PackageDebugSettings, NULL, CLSCTX_ALL);
//		if (hResult != S_OK) return hResult;
//
//		PACKAGE_EXECUTION_STATE state;
//
//		hResult = debugSettings->GetPackageExecutionState(argv[1], &state);
//		if (hResult != S_OK) return hResult;
//
//		// Convert the PES to a string
//		std::wstring str;
//		switch (state) {
//			case PES_RUNNING:
//				str = L"Running"; 
//				break;
//
//			case PES_SUSPENDING:
//				str = L"Suspending"; 
//				break;
//
//			case PES_SUSPENDED:
//				str = L"Suspended"; 
//				break;
//
//			case PES_TERMINATED:
//				str = L"Terminated"; 
//				break;
//
//			case PES_UNKNOWN:
//				str = L"Unknown"; 
//				break;
//
//			default:
//				str = L"Uknown Execution State: " + std::to_wstring((int)state); 
//				break;
//		}
//		MessageBox(NULL, str.c_str(), L"Execution State", MB_OK);
//	}
//}
#include "gravel.h"

std::wstring AppIdFromFullName(std::wstring fullName)
{
	PACKAGE_INFO_REFERENCE pir = { 0 };
	LONG rc = OpenPackageInfoByFullName(fullName.c_str(), 0, &pir);
	
	std::wstring appId;
	if (rc != ERROR_SUCCESS) return appId;

	UINT32 count, length = 0;
	rc = GetPackageApplicationIds(pir, &length, NULL, &count);
	if (rc != ERROR_INSUFFICIENT_BUFFER)
	{
		ClosePackageInfo(pir);
		return appId;
	}

	BYTE* buffer = (BYTE*)malloc(length);
	if (buffer == NULL)
	{
		ClosePackageInfo(pir);
		return appId;
	}

	rc = GetPackageApplicationIds(pir, &length, buffer, &count);
	if (rc != ERROR_SUCCESS)
	{
		ClosePackageInfo(pir);
		return appId;
	}

	PCWSTR* applicationUserModelIds = (PCWSTR*)buffer;
	appId = applicationUserModelIds[0];

	free(buffer);

	rc = ClosePackageInfo(pir);
	return appId;
}
#include "SetPermToPath.hpp"

DWORD SetPermToPath(std::wstring wstrFilePath)
{
    PACL pOldDACL = NULL, pNewDACL = NULL;
    PSECURITY_DESCRIPTOR pSD = NULL;
    EXPLICIT_ACCESS eaAccess;
    SECURITY_INFORMATION siInfo = DACL_SECURITY_INFORMATION;
    DWORD dwResult = ERROR_SUCCESS;
    PSID pSID;

    dwResult = GetNamedSecurityInfo(wstrFilePath.c_str(), SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, &pOldDACL, NULL, &pSD);
    if (dwResult != ERROR_SUCCESS)
        goto Cleanup;

    ConvertStringSidToSid(L"S-1-15-2-1", &pSID);
    if (pSID == NULL)
        goto Cleanup;

    ZeroMemory(&eaAccess, sizeof(EXPLICIT_ACCESS));
    eaAccess.grfAccessPermissions = GENERIC_READ | GENERIC_EXECUTE;
    eaAccess.grfAccessMode = SET_ACCESS;
    eaAccess.grfInheritance = SUB_CONTAINERS_AND_OBJECTS_INHERIT;
    eaAccess.Trustee.TrusteeForm = TRUSTEE_IS_SID;
    eaAccess.Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
    eaAccess.Trustee.ptstrName = (LPWSTR)pSID;

    // Create a new ACL that merges the new ACE into the existing DACL
    dwResult = SetEntriesInAcl(1, &eaAccess, pOldDACL, &pNewDACL);
    if (ERROR_SUCCESS != dwResult)
        goto Cleanup;

    // Attach the new ACL as the object's DACL
    dwResult = SetNamedSecurityInfo((LPWSTR)wstrFilePath.c_str(), SE_FILE_OBJECT, siInfo, NULL, NULL, pNewDACL, NULL);
    if (ERROR_SUCCESS != dwResult)
        goto Cleanup;

Cleanup:
    if (pSD != NULL) LocalFree((HLOCAL)pSD);
    if (pNewDACL != NULL) LocalFree((HLOCAL)pNewDACL);

    return dwResult;
}
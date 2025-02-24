#include "PackageFullNameFromFamilyName.hpp"
#include "gravel.hpp"


namespace Gravel {
	namespace Grapple {
		void _Cleanup(PWSTR* fullNames, PWSTR buffer, UINT32* properties) {
			if (properties != nullptr)
				free(properties);
			if (buffer != nullptr)
				free(buffer);
			if (fullNames != nullptr)
				free(fullNames);
		}

		std::wstring PackageFullNameFromFamilyName(std::wstring familyName)
		{
			UINT32 count = 0, length = 0;
			LONG status = FindPackagesByPackageFamily(familyName.c_str(), PACKAGE_FILTER_HEAD, &count, nullptr, &length, nullptr, nullptr);

			std::wstring fullName;
			if (status == ERROR_SUCCESS || status != ERROR_INSUFFICIENT_BUFFER) return fullName;

			PWSTR*  fullNames  = (PWSTR*) malloc(count  * sizeof(*fullNames));
			PWSTR   buffer     = (PWSTR)  malloc(length * sizeof(WCHAR));
			UINT32* properties = (UINT32*)malloc(count  * sizeof(*properties));

			if (fullNames  == nullptr || buffer == nullptr || properties == nullptr)
				_Cleanup(fullNames, buffer, properties);

			status = FindPackagesByPackageFamily(familyName.c_str(), PACKAGE_FILTER_HEAD, &count, fullNames, &length, buffer, properties);
			if (status == ERROR_SUCCESS) 
				fullName = std::wstring(fullNames[0]); // Get the first activatable package found; usually there is only one anyway

			_Cleanup(fullNames, buffer, properties);
			return fullName;
		}
	}
}
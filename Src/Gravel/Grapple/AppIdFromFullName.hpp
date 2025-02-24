#pragma once

#include <windows.h>
#include <string>

#include <appmodel.h>

namespace Gravel {
	namespace Grapple {
		std::wstring AppIdFromFullName(std::wstring fullName);
	}
}
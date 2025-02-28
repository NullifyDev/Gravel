#pragma once

#include <windows.h>
#include <string>

#include <appmodel.h>

namespace Spade {
	namespace Grapple {
		std::wstring AppIdFromFullName(std::wstring fullName);
	}
}
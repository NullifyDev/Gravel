#pragma once

#include <Windows.h>
#include <MinHook.h>
#include <ShlObj.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <ostream>
#include <stdio.h>
#include <cstdlib>

#include "Launch.hpp"
#include "GrappleVars.hpp"
#include "Grapple\Initialize.hpp"
#include "Grapple\Uninitialize.hpp"


namespace Spade {
    HRESULT LaunchSuspended(LPCWSTR appFullName, PDWORD pid);
}
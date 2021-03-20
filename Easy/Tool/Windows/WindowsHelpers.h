#pragma once

#include "Easy.h"

using namespace easy;

#include <windows.h>
#include <windowsx.h>

namespace helpers {
    // # Data

    CString convertLPCWSTRToString(LPCWSTR string);
    Date convertSystemTimeToDate(const SYSTEMTIME& time);

    // # Errors

    // Gets the last Win32 error as String.
    CString lastWin32ErrorMessage();

    CString errorMessageForWin32ErrorCode(DWORD code);
}

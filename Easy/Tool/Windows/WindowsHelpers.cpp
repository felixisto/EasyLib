
#include "WindowsHelpers.h"

namespace helpers {
    CString convertLPCWSTRToString(LPCWSTR string) {
        return CString(std::wstring(string));
    }

    // Gets the last Win32 error as String.
    CString lastWin32ErrorMessage() {
        return errorMessageForWin32ErrorCode(GetLastError());
    }

    CString errorMessageForWin32ErrorCode(DWORD code) {
        if (code == 0) {
            return CString::EMPTY;
        }

        LPSTR messageBuffer = nullptr;

        size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

        std::string message = std::string(messageBuffer, size);

        // Free the buffer.
        LocalFree(messageBuffer);

        return CString(message);
    }

    Date convertSystemTimeToDate(const SYSTEMTIME& time) {
        struct tm tm;
        memset(&tm, 0, sizeof(tm));

        tm.tm_year = time.wYear - 1900;
        tm.tm_mon = time.wMonth - 1;
        tm.tm_mday = time.wDay;

        tm.tm_hour = time.wHour;
        tm.tm_min = time.wMinute;
        tm.tm_sec = time.wSecond;
        tm.tm_isdst = -1;

        time_t result = mktime(&tm);

        Date date = Date(TimeReference::fromTimeT(result));

        return date;
    }
}
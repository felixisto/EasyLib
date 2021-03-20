#pragma once

#include "WindowsFileSystem.h"
#include <Windows.h>

namespace easy {
	namespace fs {
		struct WinFileTime {
			static time_t timeFromSystemTime(const SYSTEMTIME* pTime) {
				struct tm tm;
				memset(&tm, 0, sizeof(tm));

				tm.tm_year = pTime->wYear - 1900;
				tm.tm_mon = pTime->wMonth - 1;
				tm.tm_mday = pTime->wDay;

				tm.tm_hour = pTime->wHour;
				tm.tm_min = pTime->wMinute;
				tm.tm_sec = pTime->wSecond;
				tm.tm_isdst = -1;

				return mktime(&tm);
			}

			static TimeReference timeReferenceFromFileTime(FILETIME winTime) {
				SYSTEMTIME tm;
				FileTimeToSystemTime(&winTime, &tm);

				time_t time = timeFromSystemTime(&tm);

				return TimeReference::fromTimeT(time);
			}
		};
	};
};

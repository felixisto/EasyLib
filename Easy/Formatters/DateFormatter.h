#pragma once

#include "../Foundation/Date.h"

namespace easy {
	/*
	 * Formats for time and date values.
	 * 
	 * The formatting is based on c++ chrono library formats.
	 * The only custom specifier is "{ms}", which displays milliseconds, and not supported by chrono by default.
	 */
	struct DateFormatter: StringRepresentable {
		Date date;
		CString format = "%Y-%m-%d %H:%M:%S";

		DateFormatter() {

		}

		DateFormatter(const DateFormatter& other) : date(other.date) {

		}

		DateFormatter(const Date& date) : date(date) {

		}

		// # Premade

		static CString timestampFormat();

		// # StringRepresentable

		virtual CString toString() const;
	};

	struct DateFormatterSpecifiers {
		static const DateFormatterSpecifiers& standard() {
			static const DateFormatterSpecifiers formatter;
			return formatter;
		}

		std::string formatFullCalendarVerbose = "%Y %B %d %H:%M:%S";
		std::string formatFullCalendar = "%Y-%m-%d %H:%M:%S";
		std::string formatShortCalendar = "%Y-%m-%d";
		std::string format24HTimeOfDay = "%H:%M:%S";
		std::string format24HTimeOfDayFull = "%H:%M:%S.{ms}";
		std::string format12HTimeOfDay = "%I:%M:%S %p";
		std::string format12HTimeOfDaySimple = "%I:%M:%S";
		std::string format12HTimeOfDayFull = "%I:%M:%S.{ms} %p";
		std::string format24HHourMinute = "%H:%M";
		std::string format12HHourMinute = "%H:%M %p";
		std::string format12HHourMinuteSimple = "%H:%M";

		std::string year = "%Y";
		std::string month = "%m";
		std::string monthName = "%b";
		std::string monthNameFull = "%B";
		std::string day = "%d"; // Prefixed with 0 if necessary.
		std::string yearDay = "%j"; // Writes the day number of the year.
		std::string weekDay = "%u"; // 1-7, where 1 is Monday
		std::string weekDayName = "%a";
		std::string weekDayNameFull = "%A";

		std::string timeAMPM = "%p"; // %P does not work for some reason.

		std::string hour12h = "%I";
		std::string hour24h = "%H";
		std::string minute = "%M"; // Prefixed with 0 if necessary.
		std::string sec = "%S"; // Prefixed with 0 if necessary.

		std::string ms = "{ms}";
	};
};

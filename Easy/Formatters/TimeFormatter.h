#pragma once

#include "../Basic/Defines.h"
#include "../Basic/Time.h"
#include "../Basic/TimeUnit.h"
#include "../Foundation/CString.h"
#include "../Foundation/Number.h"

namespace easy {
	/*
	 * Converts time to string.
	 */
	struct TimeFormatter {
		bool forceInteger = false;
		byte realPrecisionDecimals = 1; // How many characters to write after the decimal point
		bool printTimeUnitName = false;
		bool useShortTimeUnitName = true;
		bool usePluralTimeUnitNames = true;
		CString timeUnitSeparator = " ";

		time::TimeUnit highestTimeUnitAllowed = time::TimeUnit::COMMON_YEAR();
		time::TimeUnit lowestTimeUnitAllowed = time::TimeUnit::MILLISECOND();

		CString mostAppropriateStringFor(const TimeValue& time) {
			auto unitCentury = time::TimeUnit::CENTURY();
			auto unitYear = time::TimeUnit::COMMON_YEAR();
			auto unitDay = time::TimeUnit::DAY();
			auto unitHour = time::TimeUnit::HOUR();
			auto unitMinute = time::TimeUnit::MINUTE();
			auto unitSecond = time::TimeUnit::SECOND();
			auto unitMS = time::TimeUnit::MILLISECOND();

			if (isUnitAllowed(unitCentury)) {
				real centuries = time.inCenturies();

				if (centuries >= 1.0) {
					return makeStringOf(centuries, unitCentury);
				}
			}

			if (isUnitAllowed(unitYear)) {
				real commonYears = time.inCommonYears();

				if (commonYears >= 1.0) {
					return makeStringOf(commonYears, unitYear);
				}
			}

			if (isUnitAllowed(unitDay)) {
				real days = time.inDays();

				if (days >= 1.0) {
					return makeStringOf(days, unitDay);
				}
			}

			if (isUnitAllowed(unitHour)) {
				real hours = time.inHours();

				if (hours >= 1.0) {
					return makeStringOf(hours, unitHour);
				}
			}

			if (isUnitAllowed(unitMinute)) {
				real min = time.inMinutes();

				if (min >= 1.0) {
					return makeStringOf(min, unitMinute);
				}
			}

			if (isUnitAllowed(unitSecond)) {
				real sec = time.inSeconds();

				if (sec >= 1.0) {
					return makeStringOf(sec, unitSecond);
				}
			}

			if (isUnitAllowed(unitMS)) {
				ubig ms = time.inMilliseconds();

				if (ms >= 1.0) {
					return makeStringOf(ms, unitMS);
				}
			}

			return "";
		}

		CString formatReal(real value) {
			if (forceInteger || realPrecisionDecimals == 0) {
				return CString::format("%.0f", value);
			}

			if (realPrecisionDecimals <= 0) {
				return CString::format("%.1f", value);
			}

			if (realPrecisionDecimals <= 1) {
				return CString::format("%.1f", value);
			}

			if (realPrecisionDecimals <= 2) {
				return CString::format("%.2f", value);
			}

			if (realPrecisionDecimals <= 3) {
				return CString::format("%.3f", value);
			}

			if (realPrecisionDecimals <= 4) {
				return CString::format("%.4f", value);
			}

			return CString::format("%.5f", value);
		}

		CString formatInt(ubig value) {
			return CString::format("%llu", value);
		}

		bool isUnitAllowed(const time::TimeUnit& unit) {
			return unit <= highestTimeUnitAllowed && unit >= lowestTimeUnitAllowed;
		}

	private:
		CString makeStringOf(real value, const time::TimeUnit& unit) {
			return appendTimeUnit(formatReal(value), value == 1, unit);
		}

		CString makeStringOf(ubig value, const time::TimeUnit& unit) {
			return appendTimeUnit(formatInt(value), value == 1, unit);
		}

		CString appendTimeUnit(const CString& originalValue, bool isSingle, const time::TimeUnit& unit) {
			if (!printTimeUnitName) {
				return originalValue;
			}

			std::string unitName = useShortTimeUnitName ? unit.shortName : unit.name;

			if (usePluralTimeUnitNames && !isSingle) {
				unitName += "s";
			}

			return CString::format("%s%s%s", originalValue.buffer(), timeUnitSeparator.buffer(), unitName.c_str());
		}
	};
};

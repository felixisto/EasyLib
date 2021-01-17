#pragma once

#include "Defines.h"
#include "String.h"
#include "Hashable.h"
#include <string>
#include <vector>

namespace easy {
	namespace time {
		/*
		 * Encapsulates time type. 
		 */
		struct TimeUnit {
			static const TimeUnit& PLANCK_TIME();
			static const TimeUnit& YOCTOSECOND();
			static const TimeUnit& JIFFY();
			static const TimeUnit& ZEPTOSECOND();
			static const TimeUnit& ATTOSECOND();
			static const TimeUnit& FEMTOSECOND();
			static const TimeUnit& SVEDBERG();
			static const TimeUnit& PICOSECOND();
			static const TimeUnit& NANOSECOND();
			static const TimeUnit& MICROSECOND();
			static const TimeUnit& MILLISECOND();
			static const TimeUnit& CENTISECOND();
			static const TimeUnit& DECISECOND();
			static const TimeUnit& SECOND();
			static const TimeUnit& MINUTE();
			static const TimeUnit& HECTOSECOND();
			static const TimeUnit& KE();
			static const TimeUnit& KILOSECOND();
			static const TimeUnit& HOUR();
			static const TimeUnit& DAY();
			static const TimeUnit& WEEK();
			static const TimeUnit& MEGASECOND();
			static const TimeUnit& FORTNIGHT();
			static const TimeUnit& MONTH28();
			static const TimeUnit& MONTH29();
			static const TimeUnit& MONTH30();
			static const TimeUnit& MONTH31();
			static const TimeUnit& SEMESTER();
			static const TimeUnit& COMMON_YEAR();
			static const TimeUnit& LEAP_YEAR();
			static const TimeUnit& BIENNIUM();
			static const TimeUnit& TRIENNIUM();
			static const TimeUnit& QUADRENNIUM();
			static const TimeUnit& OLYMPIAD();
			static const TimeUnit& LUSTRUM();
			static const TimeUnit& DECADE();
			static const TimeUnit& GIGASECOND();
			static const TimeUnit& CENTURY();
			static const TimeUnit& MILLENNIUM();
			static const TimeUnit& TERASECOND();
			static const TimeUnit& MEGAYEAR();
			static const TimeUnit& PETASECOND();
			static const TimeUnit& GALACTIC_YEAR();
			static const TimeUnit& EXASECOND();

			static const std::vector<TimeUnit>& ALL_VALUES();

			TimeUnit(const TimeUnit& other);

			bool operator==(const TimeUnit& other) const;
			bool operator!=(const TimeUnit& other) const;

			// Use greater than and less than to check if one time unit is bigger than the other.
			bool operator>(const TimeUnit& other) const;
			bool operator>=(const TimeUnit& other) const;
			bool operator<(const TimeUnit& other) const;
			bool operator<=(const TimeUnit& other) const;

			virtual std::string toString() const;
			virtual ubig hashValue() const;

			// # Properties

			const int value;
			const std::string name;
			const std::string shortName; // Name abbreviation
			const std::string symbol; // SI symbol

			std::string pluralName() const {
				return name + "s";
			}

			std::string pluralShortName() const {
				return shortName + "s";
			}

		private:

			TimeUnit(int value, const std::string& name, const std::string& shortName, const std::string& symbol);

			static std::vector<TimeUnit> BUILD_ALL_VALUES();

			void* operator new   (size_t count) { return nullptr; }
			void* operator new[] (size_t count) { return nullptr; }
			void operator delete   (void*) {}
			void operator delete[](void*) {}
		};

		namespace convert_real {
			// # Convert seconds

			static real convertMillisecondsToSeconds(ubig ms) {
				real milliseconds = (real)ms;
				return milliseconds / 1000.0;
			}

			static ubig convertSecondsToMilliseconds(real seconds) {
				return (ubig)(seconds * 1000.0);
			}

			static real convertMinutesToSeconds(real minutes) {
				return minutes * 60.0;
			}

			static real convertSecondsToMinutes(real seconds) {
				return seconds / 60.0;
			}

			static real convertHoursToSeconds(real hours) {
				return convertMinutesToSeconds(hours) * 60.0;
			}

			static real convertSecondsToHours(real seconds) {
				return convertSecondsToMinutes(seconds) / 60.0;
			}

			static real convertDaysToSeconds(real days) {
				return convertHoursToSeconds(days) * 24.0;
			}

			static real convertSecondsToDays(real seconds) {
				return convertSecondsToHours(seconds) / 24.0;
			}

			static real convertCommonYearsToSeconds(real years) {
				return convertDaysToSeconds(years) * 365.0;
			}

			static real convertSecondsToCommonYears(real seconds) {
				return convertSecondsToDays(seconds) / 365.0;
			}

			static real convertSecondsToCenturies(real seconds) {
				return convertSecondsToCommonYears(seconds) / 100.0;
			}
		};

		namespace convert_big {
			// # Convert seconds

			static ubig convertMinutesToSeconds(ubig minutes) {
				return minutes * 60;
			}

			static ubig convertSecondsToMinutes(ubig seconds) {
				return seconds / 60;
			}

			static ubig convertHoursToSeconds(ubig hours) {
				return convertMinutesToSeconds(hours) * 60;
			}

			static ubig convertSecondsToHours(ubig seconds) {
				return convertSecondsToMinutes(seconds) / 60;
			}

			static ubig convertDaysToSeconds(ubig days) {
				return convertHoursToSeconds(days) * 24;
			}

			static ubig convertSecondsToDays(ubig seconds) {
				return convertSecondsToHours(seconds) / 24;
			}

			static ubig convertWeeksToSeconds(ubig days) {
				return convertDaysToSeconds(days) * 7;
			}

			static ubig convertSecondsToWeeks(ubig seconds) {
				return convertSecondsToDays(seconds) / 7;
			}

			static ubig convertCommonYearsToSeconds(ubig years) {
				return convertDaysToSeconds(years) * 365;
			}

			static ubig convertSecondsToCommonYears(ubig seconds) {
				return convertSecondsToDays(seconds) / 365;
			}

			static ubig convertLeapYearsToSeconds(ubig years) {
				return convertDaysToSeconds(years) * 366;
			}

			static ubig convertSecondsToLeapYears(ubig seconds) {
				return convertSecondsToDays(seconds) / 366;
			}

			static ubig convertCenturiesToSeconds(ubig centuries) {
				return convertCommonYearsToSeconds(centuries) * 100;
			}

			static ubig convertSecondsToCenturies(ubig seconds) {
				return convertSecondsToCommonYears(seconds) / 100;
			}

			static ubig convertMillenniaToSeconds(ubig millennia) {
				return convertCommonYearsToSeconds(millennia) * 1000;
			}

			static ubig convertSecondsToMillennia(ubig seconds) {
				return convertSecondsToCommonYears(seconds) / 1000;
			}

			// # Convert milliseconds

			static ubig convertMillisecondsToSeconds(ubig ms) {
				return ms * 1000;
			}

			static ubig convertSecondsToMilliseconds(ubig seconds) {
				return seconds / 1000;
			}

			static ubig convertMillisecondsToMinutes(ubig ms) {
				return convertMillisecondsToSeconds(ms) * 60;
			}

			static ubig convertMinutesToMilliseconds(ubig minutes) {
				return convertSecondsToMilliseconds(minutes) / 60;
			}

			static ubig convertHoursToMilliseconds(ubig hours) {
				return convertMinutesToMilliseconds(hours) * 60;
			}

			static ubig convertMillisecondsToHours(ubig ms) {
				return convertMillisecondsToMinutes(ms) / 60;
			}

			static ubig convertDaysToMilliseconds(ubig days) {
				return convertHoursToMilliseconds(days) * 24;
			}

			static ubig convertMillisecondsToDays(ubig ms) {
				return convertMillisecondsToHours(ms) / 24;
			}

			static ubig convertWeeksToMilliseconds(ubig days) {
				return convertDaysToMilliseconds(days) * 7;
			}

			static ubig convertMillisecondsToWeeks(ubig ms) {
				return convertMillisecondsToDays(ms) / 7;
			}

			static ubig convertCommonYearsToMilliseconds(ubig years) {
				return convertDaysToMilliseconds(years) * 365;
			}

			static ubig convertMillisecondsToCommonYears(ubig ms) {
				return convertMillisecondsToDays(ms) / 365;
			}

			static ubig convertLeapYearsToMilliseconds(ubig years) {
				return convertDaysToMilliseconds(years) * 366;
			}

			static ubig convertMillisecondsToLeapYears(ubig ms) {
				return convertMillisecondsToDays(ms) / 366;
			}

			static ubig convertCenturiesToMilliseconds(ubig centuries) {
				return convertCommonYearsToMilliseconds(centuries) * 100;
			}

			static ubig convertMillisecondsToCenturies(ubig ms) {
				return convertMillisecondsToCommonYears(ms) / 100;
			}

			static ubig convertMillenniaToMilliseconds(ubig millennia) {
				return convertCommonYearsToMilliseconds(millennia) * 1000;
			}

			static ubig convertMillisecondsToMillennia(ubig ms) {
				return convertMillisecondsToCommonYears(ms) / 1000;
			}

			// # Convert picoseconds

			static ubig convertNanosecondsToPicoseconds(ubig nanoseconds) {
				return nanoseconds * 1000;
			}

			static ubig convertPicosecondsToNanoseconds(ubig picoseconds) {
				ubig dividor = 1000;
				if (dividor > picoseconds) { return 0; }
				return picoseconds / dividor;
			}

			static ubig convertMicrosecondsToPicoseconds(ubig microseconds) {
				return microseconds * 1000 * 1000;
			}

			static ubig convertPicosecondsToMicroseconds(ubig picoseconds) {
				ubig dividor = 1000 * 1000;
				if (dividor > picoseconds) { return 0; }
				return picoseconds / dividor;
			}

			static ubig convertMillisecondsToPicoseconds(ubig milliseconds) {
				return milliseconds * 1000 * 1000 * 1000;
			}

			static ubig convertPicosecondsToMilliseconds(ubig picoseconds) {
				ubig dividor = 1000 * 1000 * 1000;
				if (dividor > picoseconds) { return 0; }
				return picoseconds / dividor;
			}

			static ubig convertSecondsToPicoseconds(ubig seconds) {
				return convertMillisecondsToPicoseconds(seconds) * 1000;
			}

			static ubig convertPicosecondsToSeconds(ubig picoseconds) {
				ubig dividor = 1000 * 1000 * 1000;
				dividor *= 1000;
				if (dividor > picoseconds) { return 0; }
				return picoseconds / dividor;
			}

			// # Convert yoctoseconds

			static ubig convertZeptosecondsToYoctoseconds(ubig zeptosecond) {
				return zeptosecond * 1000;
			}

			static ubig convertYoctosecondsToZeptoseconds(ubig yoctoseconds) {
				ubig dividor = 1000;
				if (dividor > yoctoseconds) { return 0; }
				return yoctoseconds / dividor;
			}

			static ubig convertAttosecondsToYoctoseconds(ubig attoseconds) {
				return attoseconds * 1000 * 1000;
			}

			static ubig convertYoctosecondsToAttoseconds(ubig yoctoseconds) {
				ubig dividor = 1000 * 1000;
				if (dividor > yoctoseconds) { return 0; }
				return yoctoseconds / dividor;
			}

			static ubig convertFemtosecondsToYoctoseconds(ubig femtoseconds) {
				return femtoseconds * 1000 * 1000 * 1000;
			}

			static ubig convertYoctosecondsToFemtoseconds(ubig yoctoseconds) {
				ubig dividor = 1000 * 1000 * 1000;
				if (dividor > yoctoseconds) { return 0; }
				return yoctoseconds / dividor;
			}

			static ubig convertPicosecondsToYoctoseconds(ubig picoseconds) {
				return convertFemtosecondsToYoctoseconds(picoseconds) * 1000;
			}

			static ubig convertYoctosecondsToPicoseconds(ubig yoctoseconds) {
				ubig dividor = 1000 * 1000 * 1000;
				dividor *= 1000;
				if (dividor > yoctoseconds) { return 0; }
				return yoctoseconds / dividor;
			}
		};
	};
};

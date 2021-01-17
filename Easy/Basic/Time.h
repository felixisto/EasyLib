#pragma once

#include "Defines.h"
#include "Math.h"
#include "TimeUnit.h"

namespace easy {
	/*
	 * Generic time value.
	 * 
	 * Base unit is seconds.
	 *
	 * Because the raw values is stored as seconds in a double, the following limitations must be noted:
	 * Because of the nature of double, inaccuracy grows as values get bigger or smaller.
	 * Soft max value is 9,223,372,036,854,775,808 seconds or 292 billion years.
	 * Soft min value is -9,223,372,036,854,775,808 seconds or 292 billion years.
	 * The min/max values can go much, much higher, but the inaccuracy dramatically increases.
	 * 
	 * So, it is recommended to use TimeValue when dealing with values from milliseconds to 100,000 years.
	 */
	struct TimeValue {
		static TimeValue zero();
		static TimeValue fromMilliseconds(ubig ms);
		static TimeValue fromSeconds(real seconds);
		static TimeValue fromMinutes(real minutes);
		static TimeValue fromHours(real hours);
		static TimeValue fromDays(real days);
		static TimeValue fromCommonYears(real years);

		TimeValue(const TimeValue& other);

		bool operator==(const TimeValue& other) const;
		bool operator<(const TimeValue& other) const;
		bool operator<=(const TimeValue& other) const;
		bool operator>(const TimeValue& other) const;
		bool operator>=(const TimeValue& other) const;

		TimeValue& operator=(const TimeValue& other);
		TimeValue operator+(const TimeValue& other) const;
		TimeValue operator-(const TimeValue& other) const;
		TimeValue operator*(const TimeValue& other) const;
		TimeValue operator/(const TimeValue& other) const;
		TimeValue& operator+=(const TimeValue& other);
		TimeValue& operator-=(const TimeValue& other);
		TimeValue& operator++();
		TimeValue operator++(int postFix);

		ubig inMilliseconds() const;
		real inSeconds() const;
		real inMinutes() const;
		real inHours() const;
		real inDays() const;
		real inCommonYears() const;
		real inCenturies() const;

	private:
		real _seconds;

		TimeValue(real seconds);
	};

	/*
	 * Holds time value, referencing some point in time.
	 * All time values are stored in seconds, and they all reference the last epoch (1970 January 1st).
	 * Its a common way to store time in computers.
	 *
	 * The toString formatting is based on the C++ chrono library.
	 * In addition to the default chrono specifiers, there is an additional custom specifier: "{ms}" for milliseconds.
	 *
	 * Time zone is always in UTC.
	 */
	struct TimeReference {
	private:
		real _seconds;

		TimeReference(real seconds);
	public:
		// Current epoch is always 1970 January 1st.
		static real timeSinceCurrentEpoch();

		// Current system time. Milliseconds accurate.
		static TimeReference systemTime();

		static TimeReference fromSecondsSinceCurrentEpoch(real seconds);
		static TimeReference fromTimeT(time_t timeValue);

		TimeReference();
		TimeReference(const TimeReference& other);

		bool operator==(const TimeReference& other) const;
		bool operator<(const TimeReference& other) const;
		bool operator<=(const TimeReference& other) const;
		bool operator>(const TimeReference& other) const;
		bool operator>=(const TimeReference& other) const;

		TimeReference& operator=(const TimeReference& other);

		// Returns the time value in seconds.
		real inSeconds() const;

		// Retrieves the MS only from the time value.
		integer getMS() const;

		std::string toString() const;
		std::string toString(const char* format) const;
		std::string toStringSeconds() const;
		std::string toStringDate() const;
	};
};

namespace easy {
	/*
	 * Stores milliseconds as an non-negative integer value, allowing greater precision than TimeValue.
	 *
	 * Base unit is milliseconds.
	 *
	 * Smallest possible value: 1 millisecond.
	 * Highest possible value: 1 billion years.
	 * 
	 * Note that despsite being precise with both small and very large values, division operations are very inaccurate.
	 *
	 * So, it is recommended to use PreciseTimeValue when dealing with values from seconds to millennia.
	 */
	struct PreciseTimeValue {
		static PreciseTimeValue zero();
		static PreciseTimeValue fromMilliseconds(ubig ms);
		static PreciseTimeValue fromSeconds(ubig seconds);
		static PreciseTimeValue fromMinutes(ubig minutes);
		static PreciseTimeValue fromHours(ubig hours);
		static PreciseTimeValue fromDays(ubig days);
		static PreciseTimeValue fromWeek(ubig weeks);
		static PreciseTimeValue fromCommonYear(ubig years);
		static PreciseTimeValue fromLeapYear(ubig years);
		static PreciseTimeValue fromCenturies(ubig centuries);
		static PreciseTimeValue fromMillennia(ubig millennia);

		PreciseTimeValue(const PreciseTimeValue& other);

		bool operator==(const PreciseTimeValue& other) const;
		bool operator<(const PreciseTimeValue& other) const;
		bool operator<=(const PreciseTimeValue& other) const;
		bool operator>(const PreciseTimeValue& other) const;
		bool operator>=(const PreciseTimeValue& other) const;

		PreciseTimeValue& operator=(const PreciseTimeValue& other);
		PreciseTimeValue operator+(const PreciseTimeValue& other) const;
		PreciseTimeValue operator-(const PreciseTimeValue& other) const;
		PreciseTimeValue operator*(const PreciseTimeValue& other) const;
		PreciseTimeValue operator/(const PreciseTimeValue& other) const;
		PreciseTimeValue& operator+=(const PreciseTimeValue& other);
		PreciseTimeValue& operator-=(const PreciseTimeValue& other);
		PreciseTimeValue& operator++();
		PreciseTimeValue operator++(int postFix);

		ubig inMilliseconds() const;
		ubig inSeconds() const;
		ubig inMinutes() const;
		ubig inHours() const;
		ubig inDays() const;
		ubig inWeeks() const;
		ubig inCommonYears() const;
		ubig inLeapYears() const;
		ubig inCenturies() const;
		ubig inMillennia() const;

	private:
		ubig _milliseconds;

		PreciseTimeValue(ubig milliseconds);
	};

	/*
	 * Stores small time values, such as picoseconds and nanoseconds, as an non-negative integer value.
	 *
	 * Base unit is picoseconds.
	 *
	 * Smallest possible value: 1 picosecond.
	 * Highest possible value: 10,000,000 seconds or ~115 days.
	 *
	 * So, it is recommended to use SmallTimeValue when dealing with values from picoseconds to days.
	 */
	struct SmallTimeValue {
		static SmallTimeValue zero();
		static SmallTimeValue fromPicoseconds(ubig picoseconds);
		static SmallTimeValue fromNanoseconds(ubig nanoseconds);
		static SmallTimeValue fromMicroseconds(ubig microseconds);
		static SmallTimeValue fromMilliseconds(ubig milliseconds);
		static SmallTimeValue fromSeconds(ubig seconds);

		SmallTimeValue(const SmallTimeValue& other);

		bool operator==(const SmallTimeValue& other) const;
		bool operator<(const SmallTimeValue& other) const;
		bool operator<=(const SmallTimeValue& other) const;
		bool operator>(const SmallTimeValue& other) const;
		bool operator>=(const SmallTimeValue& other) const;

		SmallTimeValue& operator=(const SmallTimeValue& other);
		SmallTimeValue operator+(const SmallTimeValue& other) const;
		SmallTimeValue operator-(const SmallTimeValue& other) const;
		SmallTimeValue operator*(const SmallTimeValue& other) const;
		SmallTimeValue operator/(const SmallTimeValue& other) const;
		SmallTimeValue& operator+=(const SmallTimeValue& other);
		SmallTimeValue& operator-=(const SmallTimeValue& other);
		SmallTimeValue& operator++();
		SmallTimeValue operator++(int postFix);

		ubig inPicoseconds() const;
		ubig inNanoseconds() const;
		ubig inMicroseconds() const;
		ubig inMilliseconds() const;
		ubig inSeconds() const;

	private:
		ubig _picoseconds;

		SmallTimeValue(ubig picoseconds);
	};

	/*
	 * Stores extremely small time values, such as yoctoseconds and femtoseconds, as an non-negative integer value.
	 *
	 * Base unit is yoctoseconds.
	 *
	 * Smallest possible value: 1 yoctosecond.
	 * Highest possible value: 10,000,000 picoseconds.
	 *
	 * So, it is recommended to use PunyTimeValue when dealing with values from yoctoseconds to picoseconds.
	 */
	struct PunyTimeValue {
		static PunyTimeValue zero();
		static PunyTimeValue fromYoctoseconds(ubig yoctoseconds);
		static PunyTimeValue fromZeptoseconds(ubig zeptoseconds);
		static PunyTimeValue fromAttoseconds(ubig attoseconds);
		static PunyTimeValue fromFemtoseconds(ubig femtoseconds);
		static PunyTimeValue fromPicoseconds(ubig picoseconds);

		PunyTimeValue(const PunyTimeValue& other);

		bool operator==(const PunyTimeValue& other) const;
		bool operator<(const PunyTimeValue& other) const;
		bool operator<=(const PunyTimeValue& other) const;
		bool operator>(const PunyTimeValue& other) const;
		bool operator>=(const PunyTimeValue& other) const;

		PunyTimeValue& operator=(const PunyTimeValue& other);
		PunyTimeValue operator+(const PunyTimeValue& other) const;
		PunyTimeValue operator-(const PunyTimeValue& other) const;
		PunyTimeValue operator*(const PunyTimeValue& other) const;
		PunyTimeValue operator/(const PunyTimeValue& other) const;
		PunyTimeValue& operator+=(const PunyTimeValue& other);
		PunyTimeValue& operator-=(const PunyTimeValue& other);
		PunyTimeValue& operator++();
		PunyTimeValue operator++(int postFix);

		ubig inYoctoseconds() const;
		ubig inZeptoseconds() const;
		ubig inAttoseconds() const;
		ubig inFemtoseconds() const;
		ubig inPicoseconds() const;
	private:
		ubig _yoctoseconds;

		PunyTimeValue(ubig yoctoseconds);
	};
};

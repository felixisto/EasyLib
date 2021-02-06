#pragma once

#include "../Basic/Defines.h"
#include "../Basic/Basic.h"
#include "../Foundation/CString.h"

namespace easy {
	/*
	 * Describes a point in time.
	 *
	 * The time is described in seconds since the last epoch - 1970 January 1st.
	 * 
	 * This is a common way to store time in computers.
	 * 
	 * You can use DateFormatter to convert the date to string in various ways.
	 * 
	 * Time zone is always in UTC.
	 */
	struct Date: StringRepresentable, Hashable, Copyable<Date> {
	private:

		TimeReference _time;

	public:
		static Date now() {
			return Date(TimeReference::systemTime());
		}

		static Date distantFuture() {
			auto max = limits::REAL_MAX;
			return Date(TimeReference::fromSecondsSinceCurrentEpoch(max - 1));
		}

		static Date distantPast() {
			return Date(TimeReference::fromSecondsSinceCurrentEpoch(1));
		}

		Date() : _time(TimeReference::systemTime()) {

		}

		Date(const Date& other) : _time(other._time) {

		}

		Date(const TimeReference& time) : _time(time) {

		}

		bool operator==(const Date& other) const {
			return _time.inSeconds() == other.inSeconds();
		}

		bool operator<(const Date& other) const {
			return _time.inSeconds() < other.inSeconds();
		}

		bool operator<=(const Date& other) const {
			return _time.inSeconds() <= other.inSeconds();
		}

		bool operator>(const Date& other) const {
			return _time.inSeconds() > other.inSeconds();
		}

		bool operator>=(const Date& other) const {
			return _time.inSeconds() >= other.inSeconds();
		}

		Date& operator=(const Date& other) {
			_time = other._time;
			return *this;
		}

		// # Property

		real inSeconds() const {
			return _time.inSeconds();
		}

		// # Checks

		// If this date takes place after other, then the result will be positive.
	    real timeSince(const Date& other) const {
			return _time.inSeconds() - other.inSeconds();
		}

		bool isBefore(const Date& other) const {
			return *this < other;
		}

		bool isAfter(const Date& other) const {
			return *this > other;
		}

		// # Create

		// Creates a new date, based on this one, with specified seconds offeset.
		Date dateFromNow(real seconds) const {
			TimeReference time = TimeReference::fromSecondsSinceCurrentEpoch(_time.inSeconds() + seconds);
			return Date(time);
		}

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const {
			return (ubig)_time.inSeconds();
		}

		// # Copyable

		virtual Date copy() const {
			return *this;
		}
	};
};

#include "../Formatters/DateFormatter.h"

#pragma once

#include "Defines.h"
#include "Math.h"

namespace easy {
	/*
	 * Generic data size for computer storage.
	 * 
	 * The base unit is in bytes.
	 *
	 * Maximum value is 18,446 petabytes.
	 * Minimum value is 1 byte.
	 */
	struct DataSize {
		static DataSize zero();
		static DataSize fromBytes(ubig bytes);
		static DataSize fromKB(real KB);
		static DataSize fromMB(real MB);
		static DataSize fromGB(real GB);
		static DataSize fromTB(real TB);
		static DataSize fromPB(real PB);

		DataSize(const DataSize& other);

		bool operator==(const DataSize& other) const;
		bool operator<(const DataSize& other) const;
		bool operator<=(const DataSize& other) const;
		bool operator>(const DataSize& other) const;
		bool operator>=(const DataSize& other) const;

		DataSize& operator=(const DataSize& other);
		DataSize operator+(const DataSize& other) const;
		DataSize operator-(const DataSize& other) const;
		DataSize operator*(const DataSize& other) const;
		DataSize operator/(const DataSize& other) const;
		DataSize& operator+=(const DataSize& other);
		DataSize& operator-=(const DataSize& other);
		DataSize& operator++();
		DataSize operator++(int postFix);

		ubig inBytes() const;
		real inKB() const;
		real inMB() const;
		real inGB() const;
		real inTB() const;
		real inPB() const;

	private:
		ubig _bytes;

		DataSize(ubig bytes);
	};
};

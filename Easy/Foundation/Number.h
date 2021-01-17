#pragma once

#include "../Basic/Defines.h"
#include "../Basic/Basic.h"
#include "../Foundation/CString.h"

namespace easy {
	struct Byte: StringRepresentable, Hashable {
		byte value;

		Byte() : value(0) {

		}

		Byte(const Byte& other) : value(other.value) {

		}

		Byte(byte value) : value(value) {

		}

		bool operator==(const Byte& other) const {
			return value == other.value;
		}

		bool operator<(const Byte& other) const {
			return value < other.value;
		}

		bool operator<=(const Byte& other) const {
			return value <= other.value;
		}

		bool operator>(const Byte& other) const {
			return value > other.value;
		}

		bool operator>=(const Byte& other) const {
			return value >= other.value;
		}

		Byte& operator=(const Byte& other) {
			value = other.value;
			return *this;
		}

		static Byte MAXIMUM() {
			return limits::BYTE_MAX;
		}

		Byte maximum() const {
			return MAXIMUM();
		}

		static Byte MINIMUM() {
			return limits::BYTE_MIN;
		}

		Byte minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%d", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return value;
		}
	};

	struct Short: StringRepresentable, Hashable {
		short value;

		Short() : value(0) {

		}

		Short(const Short& other) : value(other.value) {

		}

		Short(short value) : value(value) {

		}

		bool operator==(const Short& other) const {
			return value == other.value;
		}

		bool operator<(const Short& other) const {
			return value < other.value;
		}

		bool operator<=(const Short& other) const {
			return value <= other.value;
		}

		bool operator>(const Short& other) const {
			return value > other.value;
		}

		bool operator>=(const Short& other) const {
			return value >= other.value;
		}

		Short& operator=(const Short& other) {
			value = other.value;
			return *this;
		}

		Short operator+(const Short& other) const {
			return value + other.value;
		}

		Short operator-(const Short& other) const {
			return value - other.value;
		}

		Short operator*(const Short& other) const {
			return value * other.value;
		}

		Short operator/(const Short& other) const {
			return value / other.value;
		}

		Short& operator+=(const Short& other) {
			value += other.value;
			return *this;
		}

		Short& operator-=(const Short& other) {
			value -= other.value;
			return *this;
		}

		Short& operator++() {
			// Prefix ++
			value++;
			return *this;
		}

		Short operator++(int postFix) {
			// Postfix ++
			auto old = *this;
			value++;
			return old;
		}

		static Short MAXIMUM() {
			return limits::SHORT_MAX;
		}

		Short maximum() const {
			return MAXIMUM();
		}

		static Short MINIMUM() {
			return limits::SHORT_MIN;
		}

		Short minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%d", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return value;
		}
	};

	struct UShort: StringRepresentable, Hashable {
		ushort value;

		UShort() : value(0) {

		}

		UShort(const UShort& other) : value(other.value) {

		}

		UShort(ushort value) : value(value) {

		}

		bool operator==(const UShort& other) const {
			return value == other.value;
		}

		bool operator<(const UShort& other) const {
			return value < other.value;
		}

		bool operator<=(const UShort& other) const {
			return value <= other.value;
		}

		bool operator>(const UShort& other) const {
			return value > other.value;
		}

		bool operator>=(const UShort& other) const {
			return value >= other.value;
		}

		UShort& operator=(const UShort& other) {
			value = other.value;
			return *this;
		}

		UShort operator+(const UShort& other) const {
			return value + other.value;
		}

		UShort operator-(const UShort& other) const {
			return value - other.value;
		}

		UShort operator*(const UShort& other) const {
			return value * other.value;
		}

		UShort operator/(const UShort& other) const {
			return value / other.value;
		}

		UShort& operator+=(const UShort& other) {
			value += other.value;
			return *this;
		}

		UShort& operator-=(const UShort& other) {
			value -= other.value;
			return *this;
		}

		UShort& operator++() {
			// Prefix ++
			value++;
			return *this;
		}

		UShort operator++(int postFix) {
			// Postfix ++
			auto old = *this;
			value++;
			return old;
		}

		static UShort MAXIMUM() {
			return limits::USHORT_MAX;
		}

		UShort maximum() const {
			return MAXIMUM();
		}

		static UShort MINIMUM() {
			return limits::USHORT_MIN;
		}

		UShort minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%d", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return value;
		}
	};

	struct Integer: StringRepresentable, Hashable {
		integer value;

		Integer() : value(0) {

		}

		Integer(const Integer& other) : value(other.value) {

		}

		Integer(integer value) : value(value) {

		}

		bool operator==(const Integer& other) const {
			return value == other.value;
		}

		bool operator<(const Integer& other) const {
			return value < other.value;
		}

		bool operator<=(const Integer& other) const {
			return value <= other.value;
		}

		bool operator>(const Integer& other) const {
			return value > other.value;
		}

		bool operator>=(const Integer& other) const {
			return value >= other.value;
		}

		Integer& operator=(const Integer& other) {
			value = other.value;
			return *this;
		}

		Integer operator+(const Integer& other) const {
			return value + other.value;
		}

		Integer operator-(const Integer& other) const {
			return value - other.value;
		}

		Integer operator*(const Integer& other) const {
			return value * other.value;
		}

		Integer operator/(const Integer& other) const {
			return value / other.value;
		}

		Integer& operator+=(const Integer& other) {
			value += other.value;
			return *this;
		}

		Integer& operator-=(const Integer& other) {
			value -= other.value;
			return *this;
		}

		Integer& operator++() {
			// Prefix ++
			value++;
			return *this;
		}

		Integer operator++(int postFix) {
			// Postfix ++
			auto old = *this;
			value++;
			return old;
		}

		static Integer MAXIMUM() {
			return limits::INTEGER_MAX;
		}

		Integer maximum() const {
			return MAXIMUM();
		}

		static Integer MINIMUM() {
			return limits::INTEGER_MIN;
		}

		Integer minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%d", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return value;
		}
	};

	struct UInteger: StringRepresentable, Hashable {
		uinteger value;

		UInteger() : value(0) {

		}

		UInteger(const UInteger& other) : value(other.value) {

		}

		UInteger(uinteger value) : value(value) {

		}

		bool operator==(const UInteger& other) const {
			return value == other.value;
		}

		bool operator<(const UInteger& other) const {
			return value < other.value;
		}

		bool operator<=(const UInteger& other) const {
			return value <= other.value;
		}

		bool operator>(const UInteger& other) const {
			return value > other.value;
		}

		bool operator>=(const UInteger& other) const {
			return value >= other.value;
		}

		UInteger& operator=(const UInteger& other) {
			value = other.value;
			return *this;
		}

		UInteger operator+(const UInteger& other) const {
			return value + other.value;
		}

		UInteger operator-(const UInteger& other) const {
			return value - other.value;
		}

		UInteger operator*(const UInteger& other) const {
			return value * other.value;
		}

		UInteger operator/(const UInteger& other) const {
			return value / other.value;
		}

		UInteger& operator+=(const UInteger& other) {
			value += other.value;
			return *this;
		}

		UInteger& operator-=(const UInteger& other) {
			value -= other.value;
			return *this;
		}

		UInteger& operator++() {
			// Prefix ++
			value++;
			return *this;
		}

		UInteger operator++(int postFix) {
			// Postfix ++
			auto old = *this;
			value++;
			return old;
		}

		static UInteger MAXIMUM() {
			return limits::UINTEGER_MAX;
		}

		UInteger maximum() const {
			return MAXIMUM();
		}

		static UInteger MINIMUM() {
			return limits::UINTEGER_MIN;
		}

		UInteger minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%lu", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return value;
		}
	};

	struct Big: StringRepresentable, Hashable {
		big value;

		Big() : value(0) {

		}

		Big(const Big& other) : value(other.value) {

		}

		Big(big value) : value(value) {

		}

		bool operator==(const Big& other) const {
			return value == other.value;
		}

		bool operator<(const Big& other) const {
			return value < other.value;
		}

		bool operator<=(const Big& other) const {
			return value <= other.value;
		}

		bool operator>(const Big& other) const {
			return value > other.value;
		}

		bool operator>=(const Big& other) const {
			return value >= other.value;
		}

		Big& operator=(const Big& other) {
			value = other.value;
			return *this;
		}

		Big operator+(const Big& other) const {
			return value + other.value;
		}

		Big operator-(const Big& other) const {
			return value - other.value;
		}

		Big operator*(const Big& other) const {
			return value * other.value;
		}

		Big operator/(const Big& other) const {
			return value / other.value;
		}

		Big& operator+=(const Big& other) {
			value += other.value;
			return *this;
		}

		Big& operator-=(const Big& other) {
			value -= other.value;
			return *this;
		}

		Big& operator++() {
			// Prefix ++
			value++;
			return *this;
		}

		Big operator++(int postFix) {
			// Postfix ++
			auto old = *this;
			value++;
			return old;
		}

		static Big MAXIMUM() {
			return limits::BIG_MAX;
		}

		Big maximum() const {
			return MAXIMUM();
		}

		static Big MINIMUM() {
			return limits::BIG_MIN;
		}

		Big minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%lld", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return value;
		}
	};

	struct UBig: StringRepresentable, Hashable {
		ubig value;

		UBig() : value(0) {

		}

		UBig(const UBig& other) : value(other.value) {

		}

		UBig(ubig value) : value(value) {

		}

		bool operator==(const UBig& other) const {
			return value == other.value;
		}

		bool operator<(const UBig& other) const {
			return value < other.value;
		}

		bool operator<=(const UBig& other) const {
			return value <= other.value;
		}

		bool operator>(const UBig& other) const {
			return value > other.value;
		}

		bool operator>=(const UBig& other) const {
			return value >= other.value;
		}

		UBig& operator=(const UBig& other) {
			value = other.value;
			return *this;
		}

		UBig operator+(const UBig& other) const {
			return value + other.value;
		}

		UBig operator-(const UBig& other) const {
			return value - other.value;
		}

		UBig operator*(const UBig& other) const {
			return value * other.value;
		}

		UBig operator/(const UBig& other) const {
			return value / other.value;
		}

		UBig& operator+=(const UBig& other) {
			value += other.value;
			return *this;
		}

		UBig& operator-=(const UBig& other) {
			value -= other.value;
			return *this;
		}

		UBig& operator++() {
			// Prefix ++
			value++;
			return *this;
		}

		UBig operator++(int postFix) {
			// Postfix ++
			auto old = *this;
			value++;
			return old;
		}

		static UBig MAXIMUM() {
			return limits::UBIG_MAX;
		}

		UBig maximum() const {
			return MAXIMUM();
		}

		static UBig MINIMUM() {
			return limits::UBIG_MIN;
		}

		UBig minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%llu", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return (ubig)value;
		}
	};

	struct Float: StringRepresentable, Hashable {
		float value;

		Float() : value(0) {

		}

		Float(const Float& other) : value(other.value) {

		}

		Float(float value) : value(value) {

		}

		bool operator==(const Float& other) const {
			return value == other.value;
		}

		bool operator<(const Float& other) const {
			return value < other.value;
		}

		bool operator<=(const Float& other) const {
			return value <= other.value;
		}

		bool operator>(const Float& other) const {
			return value > other.value;
		}

		bool operator>=(const Float& other) const {
			return value >= other.value;
		}

		Float& operator=(const Float& other) {
			value = other.value;
			return *this;
		}

		Float operator+(const Float& other) {
			return value + other.value;
		}

		Float operator-(const Float& other) const {
			return value - other.value;
		}

		Float operator*(const Float& other) const {
			return value * other.value;
		}

		Float operator/(const Float& other) const {
			return value / other.value;
		}

		Float& operator+=(const Float& other) {
			value += other.value;
			return *this;
		}

		Float& operator-=(const Float& other) {
			value -= other.value;
			return *this;
		}

		Float& operator++() {
			// Prefix ++
			value++;
			return *this;
		}

		Float operator++(int postFix) {
			// Postfix ++
			auto old = *this;
			value++;
			return old;
		}

		static Float MAXIMUM() {
			return limits::FLOAT_MAX;
		}

		Float maximum() const {
			return MAXIMUM();
		}

		static Float MINIMUM() {
			return limits::FLOAT_MIN;
		}

		Float minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		bool isInfinity() const {
			return std::isinf(value);
		}

		bool isNAN() const {
			return std::isnan(value);
		}

		bool isNormal() const {
			return !isInfinity() && !isNAN();
		}

		void roundUp() {
			value = ceil(value);
		}

		void roundDown() {
			value = floor(value);
		}

		Float integralPart() {
			return (float)math::integralPart(value);
		}

		Float fractionalPart() {
			return (float)math::fractionalPart(value);
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%.2f", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return (ubig)value;
		}
	};

	struct Real: StringRepresentable, Hashable {
		real value;

		Real() : value(0) {

		}

		Real(const Real& other) : value(other.value) {

		}

		Real(real value) : value(value) {

		}

		bool operator==(const Real& other) const {
			return value == other.value;
		}

		bool operator<(const Real& other) const {
			return value < other.value;
		}

		bool operator<=(const Real& other) const {
			return value <= other.value;
		}

		bool operator>(const Real& other) const {
			return value > other.value;
		}

		bool operator>=(const Real& other) const {
			return value >= other.value;
		}

		Real& operator=(const Real& other) {
			value = other.value;
			return *this;
		}

		Real operator+(const Real& other) {
			return value + other.value;
		}

		Real operator-(const Real& other) const {
			return value - other.value;
		}

		Real operator*(const Real& other) const {
			return value * other.value;
		}

		Real operator/(const Real& other) const {
			return value / other.value;
		}

		Real& operator+=(const Real& other) {
			value += other.value;
			return *this;
		}

		Real& operator-=(const Real& other) {
			value -= other.value;
			return *this;
		}

		Real& operator++() {
			// Prefix ++
			value++;
			return *this;
		}

		Real operator++(int postFix) {
			// Postfix ++
			auto old = *this;
			value++;
			return old;
		}

		static Real MAXIMUM() {
			return limits::REAL_MAX;
		}

		Real maximum() const {
			return MAXIMUM();
		}

		static Real MINIMUM() {
			return limits::REAL_MIN;
		}

		Real minimum() const {
			return MINIMUM();
		}

		bool isZero() const {
			return value == 0;
		}

		bool isNegative() const {
			return value < 0;
		}

		bool isPositive() const {
			return value > 0;
		}

		bool isInfinity() const {
			return std::isinf(value);
		}

		bool isNAN() const {
			return std::isnan(value);
		}

		bool isNormal() const {
			return !isInfinity() && !isNAN();
		}

		void roundUp() {
			value = ceil(value);
		}

		void roundDown() {
			value = floor(value);
		}

		Real integralPart() {
			return math::integralPart(value);
		}

		Real fractionalPart() {
			return math::fractionalPart(value);
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%.2f", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return (ubig)value;
		}
	};
};
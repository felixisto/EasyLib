#pragma once

#include "../Basic/Defines.h"
#include "../Basic/Basic.h"
#include "../Foundation/CString.h"

namespace easy {
	struct Byte;
	struct Short;
	struct UShort;
	struct Integer;
	struct UInteger;
	struct Big;
	struct UBig;
	struct Float;
	struct Real;
	
	struct Byte: StringRepresentable, Hashable {
		byte value;

		Byte();
		Byte(const Byte& other);
		Byte(byte value);

		bool operator==(const Byte& other) const;
		bool operator!=(const Byte& other) const;
		bool operator<(const Byte& other) const;
		bool operator<=(const Byte& other) const;
		bool operator>(const Byte& other) const;
		bool operator>=(const Byte& other) const;
		Byte& operator=(const Byte& other);

		static Byte MAXIMUM();
		Byte maximum() const;
		static Byte MINIMUM();
		Byte minimum() const;

		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};

	struct Short: StringRepresentable, Hashable {
		short value;

		Short();
		Short(const Short& other);
		Short(Byte value);
		Short(UShort value);
		Short(short value);

		bool operator==(const Short& other) const;
		bool operator!=(const Short& other) const;
		bool operator<(const Short& other) const;
		bool operator<=(const Short& other) const;
		bool operator>(const Short& other) const;
		bool operator>=(const Short& other) const;
		Short& operator=(const Short& other);
		Short operator+(const Short& other) const;
		Short operator-(const Short& other) const;
		Short operator*(const Short& other) const;
		Short operator/(const Short& other) const;
		Short& operator+=(const Short& other);
		Short& operator-=(const Short& other);
		Short& operator++();
		Short operator++(int postFix);

		static Short MAXIMUM();
		Short maximum() const;
		static Short MINIMUM();
		Short minimum() const;
		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};

	struct UShort: StringRepresentable, Hashable {
		ushort value;

		UShort();
		UShort(const UShort& other);
		UShort(Byte value);
		UShort(Short value);
		UShort(ushort value);

		bool operator==(const UShort& other) const;
		bool operator!=(const UShort& other) const;
		bool operator<(const UShort& other) const;
		bool operator<=(const UShort& other) const;
		bool operator>(const UShort& other) const;
		bool operator>=(const UShort& other) const;
		UShort& operator=(const UShort& other);
		UShort operator+(const UShort& other) const;
		UShort operator-(const UShort& other) const;
		UShort operator*(const UShort& other) const;
		UShort operator/(const UShort& other) const;
		UShort& operator+=(const UShort& other);
		UShort& operator-=(const UShort& other);
		UShort& operator++();
		UShort operator++(int postFix);

		static UShort MAXIMUM();
		UShort maximum() const;
		static UShort MINIMUM();
		UShort minimum() const;
		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};

	struct Integer: StringRepresentable, Hashable {
		integer value;

		Integer();
		Integer(const Integer& other);
		Integer(Byte value);
		Integer(Short value);
		Integer(UShort value);
		Integer(UInteger value);
		Integer(Big value);
		Integer(Float value);
		Integer(Real value);
		Integer(integer value);

		bool operator==(const Integer& other) const;
		bool operator!=(const Integer& other) const;
		bool operator<(const Integer& other) const;
		bool operator<=(const Integer& other) const;
		bool operator>(const Integer& other) const;
		bool operator>=(const Integer& other) const;
		Integer& operator=(const Integer& other);
		Integer operator+(const Integer& other) const;
		Integer operator-(const Integer& other) const;
		Integer operator*(const Integer& other) const;
		Integer operator/(const Integer& other) const;
		Integer& operator+=(const Integer& other);
		Integer& operator-=(const Integer& other);
		Integer& operator++();
		Integer operator++(int postFix);

		static Integer MAXIMUM();
		Integer maximum() const;
		static Integer MINIMUM();
		Integer minimum() const;
		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};

	struct UInteger: StringRepresentable, Hashable {
		uinteger value;

		UInteger();
		UInteger(const UInteger& other);
		UInteger(Byte value);
		UInteger(Short value);
		UInteger(UShort value);
		UInteger(Integer value);
		UInteger(Big value);
		UInteger(Float value);
		UInteger(Real value);
		UInteger(uinteger value);

		bool operator==(const UInteger& other) const;
		bool operator!=(const UInteger& other) const;
		bool operator<(const UInteger& other) const;
		bool operator<=(const UInteger& other) const;
		bool operator>(const UInteger& other) const;
		bool operator>=(const UInteger& other) const;
		UInteger& operator=(const UInteger& other);
		UInteger operator+(const UInteger& other) const;
		UInteger operator-(const UInteger& other) const;
		UInteger operator*(const UInteger& other) const;
		UInteger operator/(const UInteger& other) const;
		UInteger& operator+=(const UInteger& other);
		UInteger& operator-=(const UInteger& other);
		UInteger& operator++();
		UInteger operator++(int postFix);

		static UInteger MAXIMUM();
		UInteger maximum() const;
		static UInteger MINIMUM();
		UInteger minimum() const;
		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};

	struct Big: StringRepresentable, Hashable {
		big value;

		Big();
		Big(const Big& other);
		Big(Byte value);
		Big(Short value);
		Big(UShort value);
		Big(Integer value);
		Big(UInteger value);
		Big(UBig value);
		Big(big value);

		bool operator==(const Big& other) const;
		bool operator!=(const Big& other) const;
		bool operator<(const Big& other) const;
		bool operator<=(const Big& other) const;
		bool operator>(const Big& other) const;
		bool operator>=(const Big& other) const;
		Big& operator=(const Big& other);
		Big operator+(const Big& other) const;
		Big operator-(const Big& other) const;
		Big operator*(const Big& other) const;
		Big operator/(const Big& other) const;
		Big& operator+=(const Big& other);
		Big& operator-=(const Big& other);
		Big& operator++();
		Big operator++(int postFix);

		static Big MAXIMUM();
		Big maximum() const;
		static Big MINIMUM();
		Big minimum() const;
		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};

	struct UBig: StringRepresentable, Hashable {
		ubig value;

		UBig();
		UBig(const UBig& other);
		UBig(Integer value);
		UBig(UInteger value);
		UBig(Big value);
		UBig(ubig value);

		bool operator==(const UBig& other) const;
		bool operator!=(const UBig& other) const;
		bool operator<(const UBig& other) const;
		bool operator<=(const UBig& other) const;
		bool operator>(const UBig& other) const;
		bool operator>=(const UBig& other) const;
		UBig& operator=(const UBig& other);
		UBig operator+(const UBig& other) const;
		UBig operator-(const UBig& other) const;
		UBig operator*(const UBig& other) const;
		UBig operator/(const UBig& other) const;
		UBig& operator+=(const UBig& other);
		UBig& operator-=(const UBig& other);
		UBig& operator++();

		UBig operator++(int postFix);
		static UBig MAXIMUM();
		UBig maximum() const;
		static UBig MINIMUM();
		UBig minimum() const;
		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};

	struct Float: StringRepresentable, Hashable {
		float value;

		Float();
		Float(const Float& other);
		Float(Real value);
		Float(Integer value);
		Float(float value);

		bool operator==(const Float& other) const;
		bool operator!=(const Float& other) const;
		bool operator<(const Float& other) const;
		bool operator<=(const Float& other) const;
		bool operator>(const Float& other) const;
		bool operator>=(const Float& other) const;
		Float& operator=(const Float& other);
		Float operator+(const Float& other);
		Float operator-(const Float& other) const;
		Float operator*(const Float& other) const;
		Float operator/(const Float& other) const;
		Float& operator+=(const Float& other);
		Float& operator-=(const Float& other);
		Float& operator++();
		Float operator++(int postFix);

		static Float MAXIMUM();
		Float maximum() const;
		static Float MINIMUM();
		Float minimum() const;

		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;
		bool isInfinity() const;
		bool isNAN() const;
		bool isNormal() const;
		void roundUp();
		void roundDown();

		Float integralPart();
		Float fractionalPart();

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};

	struct Real: StringRepresentable, Hashable {
		real value;

		Real();
		Real(const Real& other);
		Real(Float value);
		Real(Integer value);
		Real(real value);

		bool operator==(const Real& other) const;
		bool operator!=(const Real& other) const;
		bool operator<(const Real& other) const;
		bool operator<=(const Real& other) const;
		bool operator>(const Real& other) const;
		bool operator>=(const Real& other) const;
		Real& operator=(const Real& other);
		Real operator+(const Real& other);
		Real operator-(const Real& other) const;
		Real operator*(const Real& other) const;
		Real operator/(const Real& other) const;
		Real& operator+=(const Real& other);
		Real& operator-=(const Real& other);
		Real& operator++();
		Real operator++(int postFix);

		static Real MAXIMUM();
		Real maximum() const;
		static Real MINIMUM();
		Real minimum() const;
		bool isZero() const;
		bool isNegative() const;
		bool isPositive() const;
		bool isInfinity() const;
		bool isNAN() const;
		bool isNormal() const;

		void roundUp();
		void roundDown();

		Real integralPart();
		Real fractionalPart();

		// # StringRepresentable

		virtual CString toString() const;

		// # Hashable

		virtual ubig hashValue() const;
	};
};
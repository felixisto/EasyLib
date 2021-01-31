
#include "Number.h"

using namespace easy;

//
// # Byte
//

Byte::Byte() : value(0) {

}

Byte::Byte(const Byte& other) : value(other.value) {

}

Byte::Byte(byte value) : value(value) {

}

bool Byte::operator==(const Byte& other) const {
	return value == other.value;
}

bool Byte::operator<(const Byte& other) const {
	return value < other.value;
}

bool Byte::operator<=(const Byte& other) const {
	return value <= other.value;
}

bool Byte::operator>(const Byte& other) const {
	return value > other.value;
}

bool Byte::operator>=(const Byte& other) const {
	return value >= other.value;
}

Byte& Byte::operator=(const Byte& other) {
	value = other.value;
	return *this;
}

Byte Byte::MAXIMUM() {
	return limits::BYTE_MAX;
}

Byte Byte::maximum() const {
	return MAXIMUM();
}

Byte Byte::MINIMUM() {
	return limits::BYTE_MIN;
}

Byte Byte::minimum() const {
	return MINIMUM();
}

bool Byte::isZero() const {
	return value == 0;
}

bool Byte::isNegative() const {
	return value < 0;
}

bool Byte::isPositive() const {
	return value > 0;
}

// # StringRepresentable

CString Byte::toString() const {
	return CString::format("%d", value);
}

// # Hashable

ubig Byte::hashValue() const {
	return value;
}

//
// # Short
//

Short::Short() : value(0) {

}

Short::Short(const Short& other) : value(other.value) {

}

Short::Short(Byte value) : value((short)value.value) {

}

Short::Short(UShort value) : value((short)value.value) {

}

Short::Short(short value) : value(value) {

}

bool Short::operator==(const Short& other) const {
	return value == other.value;
}

bool Short::operator<(const Short& other) const {
	return value < other.value;
}

bool Short::operator<=(const Short& other) const {
	return value <= other.value;
}

bool Short::operator>(const Short& other) const {
	return value > other.value;
}

bool Short::operator>=(const Short& other) const {
	return value >= other.value;
}

Short& Short::operator=(const Short& other) {
	value = other.value;
	return *this;
}

Short Short::operator+(const Short& other) const {
	return value + other.value;
}

Short Short::operator-(const Short& other) const {
	return value - other.value;
}

Short Short::operator*(const Short& other) const {
	return value * other.value;
}

Short Short::operator/(const Short& other) const {
	return value / other.value;
}

Short& Short::operator+=(const Short& other) {
	value += other.value;
	return *this;
}

Short& Short::operator-=(const Short& other) {
	value -= other.value;
	return *this;
}

Short& Short::operator++() {
	// Prefix ++
	value++;
	return *this;
}

Short Short::operator++(int postFix) {
	// Postfix ++
	auto old = *this;
	value++;
	return old;
}

Short Short::MAXIMUM() {
	return limits::SHORT_MAX;
}

Short Short::maximum() const {
	return MAXIMUM();
}

Short Short::MINIMUM() {
	return limits::SHORT_MIN;
}

Short Short::minimum() const {
	return MINIMUM();
}

bool Short::isZero() const {
	return value == 0;
}

bool Short::isNegative() const {
	return value < 0;
}

bool Short::isPositive() const {
	return value > 0;
}

// # StringRepresentable

CString Short::toString() const {
	return CString::format("%d", value);
}

// # Hashable

ubig Short::hashValue() const {
	return value;
}

//
// # UShort
//

UShort::UShort() : value(0) {

}

UShort::UShort(const UShort& other) : value(other.value) {

}

UShort::UShort(Byte value) : value((ushort)value.value) {

}

UShort::UShort(Short value) : value((ushort)value.value) {

}

UShort::UShort(ushort value) : value(value) {

}

bool UShort::operator==(const UShort& other) const {
	return value == other.value;
}

bool UShort::operator<(const UShort& other) const {
	return value < other.value;
}

bool UShort::operator<=(const UShort& other) const {
	return value <= other.value;
}

bool UShort::operator>(const UShort& other) const {
	return value > other.value;
}

bool UShort::operator>=(const UShort& other) const {
	return value >= other.value;
}

UShort& UShort::operator=(const UShort& other) {
	value = other.value;
	return *this;
}

UShort UShort::operator+(const UShort& other) const {
	return value + other.value;
}

UShort UShort::operator-(const UShort& other) const {
	return value - other.value;
}

UShort UShort::operator*(const UShort& other) const {
	return value * other.value;
}

UShort UShort::operator/(const UShort& other) const {
	return value / other.value;
}

UShort& UShort::operator+=(const UShort& other) {
	value += other.value;
	return *this;
}

UShort& UShort::operator-=(const UShort& other) {
	value -= other.value;
	return *this;
}

UShort& UShort::operator++() {
	// Prefix ++
	value++;
	return *this;
}

UShort UShort::operator++(int postFix) {
	// Postfix ++
	auto old = *this;
	value++;
	return old;
}

UShort UShort::MAXIMUM() {
	return limits::USHORT_MAX;
}

UShort UShort::maximum() const {
	return MAXIMUM();
}

UShort UShort::MINIMUM() {
	return limits::USHORT_MIN;
}

UShort UShort::minimum() const {
	return MINIMUM();
}

bool UShort::isZero() const {
	return value == 0;
}

bool UShort::isNegative() const {
	return value < 0;
}

bool UShort::isPositive() const {
	return value > 0;
}

// # StringRepresentable

CString UShort::toString() const {
	return CString::format("%d", value);
}

// # Hashable

ubig UShort::hashValue() const {
	return value;
}

//
// # Integer
//

Integer::Integer() : value(0) {

}

Integer::Integer(const Integer& other) : value(other.value) {

}

Integer::Integer(Byte value) : value((integer)value.value) {

}

Integer::Integer(Short value) : value((integer)value.value) {

}

Integer::Integer(UShort value) : value((integer)value.value) {

}

Integer::Integer(UInteger value) : value((integer)value.value) {

}

Integer::Integer(Big value) : value((integer)value.value) {

}

Integer::Integer(Float value) : value((integer)value.value) {

}

Integer::Integer(Real value) : value((integer)value.value) {

}

Integer::Integer(integer value) : value(value) {

}

bool Integer::operator==(const Integer& other) const {
	return value == other.value;
}

bool Integer::operator<(const Integer& other) const {
	return value < other.value;
}

bool Integer::operator<=(const Integer& other) const {
	return value <= other.value;
}

bool Integer::operator>(const Integer& other) const {
	return value > other.value;
}

bool Integer::operator>=(const Integer& other) const {
	return value >= other.value;
}

Integer& Integer::operator=(const Integer& other) {
	value = other.value;
	return *this;
}

Integer Integer::operator+(const Integer& other) const {
	return value + other.value;
}

Integer Integer::operator-(const Integer& other) const {
	return value - other.value;
}

Integer Integer::operator*(const Integer& other) const {
	return value * other.value;
}

Integer Integer::operator/(const Integer& other) const {
	return value / other.value;
}

Integer& Integer::operator+=(const Integer& other) {
	value += other.value;
	return *this;
}

Integer& Integer::operator-=(const Integer& other) {
	value -= other.value;
	return *this;
}

Integer& Integer::operator++() {
	// Prefix ++
	value++;
	return *this;
}

Integer Integer::operator++(int postFix) {
	// Postfix ++
	auto old = *this;
	value++;
	return old;
}

Integer Integer::MAXIMUM() {
	return limits::INTEGER_MAX;
}

Integer Integer::maximum() const {
	return MAXIMUM();
}

Integer Integer::MINIMUM() {
	return limits::INTEGER_MIN;
}

Integer Integer::minimum() const {
	return MINIMUM();
}

bool Integer::isZero() const {
	return value == 0;
}

bool Integer::isNegative() const {
	return value < 0;
}

bool Integer::isPositive() const {
	return value > 0;
}

// # StringRepresentable

CString Integer::toString() const {
	return CString::format("%d", value);
}

// # Hashable

ubig Integer::hashValue() const {
	return value;
}

//
// UInteger
//

UInteger::UInteger() : value(0) {

}

UInteger::UInteger(const UInteger& other) : value(other.value) {

}

UInteger::UInteger(Byte value) : value((uinteger)value.value) {

}

UInteger::UInteger(Short value) : value((uinteger)value.value) {

}

UInteger::UInteger(UShort value) : value((uinteger)value.value) {

}

UInteger::UInteger(Integer value) : value((uinteger)value.value) {

}

UInteger::UInteger(Big value) : value((uinteger)value.value) {

}

UInteger::UInteger(Float value) : value((uinteger)value.value) {

}

UInteger::UInteger(Real value) : value((uinteger)value.value) {

}

UInteger::UInteger(uinteger value) : value(value) {

}

bool UInteger::operator==(const UInteger& other) const {
	return value == other.value;
}

bool UInteger::operator<(const UInteger& other) const {
	return value < other.value;
}

bool UInteger::operator<=(const UInteger& other) const {
	return value <= other.value;
}

bool UInteger::operator>(const UInteger& other) const {
	return value > other.value;
}

bool UInteger::operator>=(const UInteger& other) const {
	return value >= other.value;
}

UInteger& UInteger::operator=(const UInteger& other) {
	value = other.value;
	return *this;
}

UInteger UInteger::operator+(const UInteger& other) const {
	return value + other.value;
}

UInteger UInteger::operator-(const UInteger& other) const {
	return value - other.value;
}

UInteger UInteger::operator*(const UInteger& other) const {
	return value * other.value;
}

UInteger UInteger::operator/(const UInteger& other) const {
	return value / other.value;
}

UInteger& UInteger::operator+=(const UInteger& other) {
	value += other.value;
	return *this;
}

UInteger& UInteger::operator-=(const UInteger& other) {
	value -= other.value;
	return *this;
}

UInteger& UInteger::operator++() {
	// Prefix ++
	value++;
	return *this;
}

UInteger UInteger::operator++(int postFix) {
	// Postfix ++
	auto old = *this;
	value++;
	return old;
}

UInteger UInteger::MAXIMUM() {
	return limits::UINTEGER_MAX;
}

UInteger UInteger::maximum() const {
	return MAXIMUM();
}

UInteger UInteger::MINIMUM() {
	return limits::UINTEGER_MIN;
}

UInteger UInteger::minimum() const {
	return MINIMUM();
}

bool UInteger::isZero() const {
	return value == 0;
}

bool UInteger::isNegative() const {
	return value < 0;
}

bool UInteger::isPositive() const {
	return value > 0;
}

// # StringRepresentable

CString UInteger::toString() const {
	return CString::format("%lu", value);
}

// # Hashable

ubig UInteger::hashValue() const {
	return value;
}

//
// # Big
//

Big::Big() : value(0) {

}

Big::Big(const Big& other) : value(other.value) {

}

Big::Big(Byte value) : value((big)value.value) {

}

Big::Big(Short value) : value((big)value.value) {

}

Big::Big(UShort value) : value((big)value.value) {

}

Big::Big(Integer value) : value((big)value.value) {

}

Big::Big(UInteger value) : value((big)value.value) {

}

Big::Big(UBig value) : value((big)value.value) {

}

Big::Big(big value) : value(value) {

}

bool Big::operator==(const Big& other) const {
	return value == other.value;
}

bool Big::operator<(const Big& other) const {
	return value < other.value;
}

bool Big::operator<=(const Big& other) const {
	return value <= other.value;
}

bool Big::operator>(const Big& other) const {
	return value > other.value;
}

bool Big::operator>=(const Big& other) const {
	return value >= other.value;
}

Big& Big::operator=(const Big& other) {
	value = other.value;
	return *this;
}

Big Big::operator+(const Big& other) const {
	return value + other.value;
}

Big Big::operator-(const Big& other) const {
	return value - other.value;
}

Big Big::operator*(const Big& other) const {
	return value * other.value;
}

Big Big::operator/(const Big& other) const {
	return value / other.value;
}

Big& Big::operator+=(const Big& other) {
	value += other.value;
	return *this;
}

Big& Big::operator-=(const Big& other) {
	value -= other.value;
	return *this;
}

Big& Big::operator++() {
	// Prefix ++
	value++;
	return *this;
}

Big Big::operator++(int postFix) {
	// Postfix ++
	auto old = *this;
	value++;
	return old;
}

Big Big::MAXIMUM() {
	return limits::BIG_MAX;
}

Big Big::maximum() const {
	return MAXIMUM();
}

Big Big::MINIMUM() {
	return limits::BIG_MIN;
}

Big Big::minimum() const {
	return MINIMUM();
}

bool Big::isZero() const {
	return value == 0;
}

bool Big::isNegative() const {
	return value < 0;
}

bool Big::isPositive() const {
	return value > 0;
}

// # StringRepresentable

CString Big::toString() const {
	return CString::format("%lld", value);
}

// # Hashable

ubig Big::hashValue() const {
	return value;
}

//
// # UBig
//

UBig::UBig() : value(0) {

}

UBig::UBig(const UBig& other) : value(other.value) {

}

UBig::UBig(Integer value) : value((ubig)value.value) {

}

UBig::UBig(UInteger value) : value((ubig)value.value) {

}

UBig::UBig(Big value) : value((ubig)value.value) {

}

UBig::UBig(ubig value) : value(value) {

}

bool UBig::operator==(const UBig& other) const {
	return value == other.value;
}

bool UBig::operator<(const UBig& other) const {
	return value < other.value;
}

bool UBig::operator<=(const UBig& other) const {
	return value <= other.value;
}

bool UBig::operator>(const UBig& other) const {
	return value > other.value;
}

bool UBig::operator>=(const UBig& other) const {
	return value >= other.value;
}

UBig& UBig::operator=(const UBig& other) {
	value = other.value;
	return *this;
}

UBig UBig::operator+(const UBig& other) const {
	return value + other.value;
}

UBig UBig::operator-(const UBig& other) const {
	return value - other.value;
}

UBig UBig::operator*(const UBig& other) const {
	return value * other.value;
}

UBig UBig::operator/(const UBig& other) const {
	return value / other.value;
}

UBig& UBig::operator+=(const UBig& other) {
	value += other.value;
	return *this;
}

UBig& UBig::operator-=(const UBig& other) {
	value -= other.value;
	return *this;
}

UBig& UBig::operator++() {
	// Prefix ++
	value++;
	return *this;
}

UBig UBig::operator++(int postFix) {
	// Postfix ++
	auto old = *this;
	value++;
	return old;
}

UBig UBig::MAXIMUM() {
	return limits::UBIG_MAX;
}

UBig UBig::maximum() const {
	return MAXIMUM();
}

UBig UBig::MINIMUM() {
	return limits::UBIG_MIN;
}

UBig UBig::minimum() const {
	return MINIMUM();
}

bool UBig::isZero() const {
	return value == 0;
}

bool UBig::isNegative() const {
	return value < 0;
}

bool UBig::isPositive() const {
	return value > 0;
}

// # StringRepresentable

CString UBig::toString() const {
	return CString::format("%llu", value);
}

// # Hashable

ubig UBig::hashValue() const {
	return (ubig)value;
}

//
// # Float
//

Float::Float() : value(0) {

}

Float::Float(const Float& other) : value(other.value) {

}

Float::Float(Real value) : value((float)value.value) {

}

Float::Float(Integer value) : value((float)value.value) {

}

Float::Float(float value) : value(value) {

}

bool Float::operator==(const Float& other) const {
	return value == other.value;
}

bool Float::operator<(const Float& other) const {
	return value < other.value;
}

bool Float::operator<=(const Float& other) const {
	return value <= other.value;
}

bool Float::operator>(const Float& other) const {
	return value > other.value;
}

bool Float::operator>=(const Float& other) const {
	return value >= other.value;
}

Float& Float::operator=(const Float& other) {
	value = other.value;
	return *this;
}

Float Float::operator+(const Float& other) {
	return value + other.value;
}

Float Float::operator-(const Float& other) const {
	return value - other.value;
}

Float Float::operator*(const Float& other) const {
	return value * other.value;
}

Float Float::operator/(const Float& other) const {
	return value / other.value;
}

Float& Float::operator+=(const Float& other) {
	value += other.value;
	return *this;
}

Float& Float::operator-=(const Float& other) {
	value -= other.value;
	return *this;
}

Float& Float::operator++() {
	// Prefix ++
	value++;
	return *this;
}

Float Float::operator++(int postFix) {
	// Postfix ++
	auto old = *this;
	value++;
	return old;
}

Float Float::MAXIMUM() {
	return limits::FLOAT_MAX;
}

Float Float::maximum() const {
	return MAXIMUM();
}

Float Float::MINIMUM() {
	return limits::FLOAT_MIN;
}

Float Float::minimum() const {
	return MINIMUM();
}

bool Float::isZero() const {
	return value == 0;
}

bool Float::isNegative() const {
	return value < 0;
}

bool Float::isPositive() const {
	return value > 0;
}

bool Float::isInfinity() const {
	return std::isinf(value);
}

bool Float::isNAN() const {
	return std::isnan(value);
}

bool Float::isNormal() const {
	return !isInfinity() && !isNAN();
}

void Float::roundUp() {
	value = ceil(value);
}

void Float::roundDown() {
	value = floor(value);
}

Float Float::integralPart() {
	return (float)math::integralPart(value);
}

Float Float::fractionalPart() {
	return (float)math::fractionalPart(value);
}

// # StringRepresentable

CString Float::toString() const {
	return CString::format("%.2f", value);
}

// # Hashable

ubig Float::hashValue() const {
	return (ubig)value;
}

//
// # Real
//

Real::Real() : value(0) {

}

Real::Real(const Real& other) : value(other.value) {

}

Real::Real(Float value) : value((real)value.value) {

}

Real::Real(Integer value) : value((real)value.value) {

}

Real::Real(real value) : value(value) {

}

bool Real::operator==(const Real& other) const {
	return value == other.value;
}

bool Real::operator<(const Real& other) const {
	return value < other.value;
}

bool Real::operator<=(const Real& other) const {
	return value <= other.value;
}

bool Real::operator>(const Real& other) const {
	return value > other.value;
}

bool Real::operator>=(const Real& other) const {
	return value >= other.value;
}

Real& Real::operator=(const Real& other) {
	value = other.value;
	return *this;
}

Real Real::operator+(const Real& other) {
	return value + other.value;
}

Real Real::operator-(const Real& other) const {
	return value - other.value;
}

Real Real::operator*(const Real& other) const {
	return value * other.value;
}

Real Real::operator/(const Real& other) const {
	return value / other.value;
}

Real& Real::operator+=(const Real& other) {
	value += other.value;
	return *this;
}

Real& Real::operator-=(const Real& other) {
	value -= other.value;
	return *this;
}

Real& Real::operator++() {
	// Prefix ++
	value++;
	return *this;
}

Real Real::operator++(int postFix) {
	// Postfix ++
	auto old = *this;
	value++;
	return old;
}

Real Real::MAXIMUM() {
	return limits::REAL_MAX;
}

Real Real::maximum() const {
	return MAXIMUM();
}

Real Real::MINIMUM() {
	return limits::REAL_MIN;
}

Real Real::minimum() const {
	return MINIMUM();
}

bool Real::isZero() const {
	return value == 0;
}

bool Real::isNegative() const {
	return value < 0;
}

bool Real::isPositive() const {
	return value > 0;
}

bool Real::isInfinity() const {
	return std::isinf(value);
}

bool Real::isNAN() const {
	return std::isnan(value);
}

bool Real::isNormal() const {
	return !isInfinity() && !isNAN();
}

void Real::roundUp() {
	value = ceil(value);
}

void Real::roundDown() {
	value = floor(value);
}

Real Real::integralPart() {
	return math::integralPart(value);
}

Real Real::fractionalPart() {
	return math::fractionalPart(value);
}

// # StringRepresentable

CString Real::toString() const {
	return CString::format("%.2f", value);
}

// # Hashable

ubig Real::hashValue() const {
	return (ubig)value;
}

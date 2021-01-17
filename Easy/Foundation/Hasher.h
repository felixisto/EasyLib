#pragma once

#include "../Basic/Defines.h"
#include "CString.h"

namespace easy {
	struct Byte;
	struct Short;
	struct UShort;
	struct Integer;
	struct UInteger;
	struct Big;
	struct UBig;
	struct Real;

	struct Hasher {
		virtual ubig combine(ubig a, ubig b) const = 0;

		virtual ubig hash(void* value) const = 0;
		virtual ubig hash(const void* value) const = 0;
		virtual ubig hash(bool value) const = 0;
		virtual ubig hash(byte value) const = 0;
		virtual ubig hash(short value) const = 0;
		virtual ubig hash(ushort value) const = 0;
		virtual ubig hash(integer value) const = 0;
		virtual ubig hash(uinteger value) const = 0;
		virtual ubig hash(big value) const = 0;
		virtual ubig hash(ubig value) const = 0;
		virtual ubig hash(float value) const = 0;
		virtual ubig hash(double value) const = 0;
		virtual ubig hash(const CString& value) const = 0;

		virtual ubig hash(const Byte& value) const = 0;
		virtual ubig hash(const Short& value) const = 0;
		virtual ubig hash(const UShort& value) const = 0;
		virtual ubig hash(const Integer& value) const = 0;
		virtual ubig hash(const UInteger& value) const = 0;
		virtual ubig hash(const Big& value) const = 0;
		virtual ubig hash(const UBig& value) const = 0;
		virtual ubig hash(const Real& value) const = 0;
	};
};

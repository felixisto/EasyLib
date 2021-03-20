#pragma once

#include "../../Foundation/Hasher.h"
#include "../../Foundation/Number.h"

namespace easy {
	/// Hash generator (64 bit).
	/// Strings are converted using a fancy algorithm. Does not work when string is longer than 512 chars (result is always 1).
	/// All other values are simply converted to ubig.
	struct MurmurHash64B: Hasher {
	private:

		const unsigned int seed;

	public:

		static const MurmurHash64B& global();

		MurmurHash64B();
		MurmurHash64B(int seed);

		virtual ubig combine(ubig a, ubig b) const;

		virtual ubig hash(const void* value) const;
		virtual ubig hash(bool value) const;
		virtual ubig hash(byte value) const;
		virtual ubig hash(short value) const;
		virtual ubig hash(ushort value) const;
		virtual ubig hash(integer value) const;
		virtual ubig hash(uinteger value) const;
		virtual ubig hash(big value) const;
		virtual ubig hash(ubig value) const;
		virtual ubig hash(float value) const;
		virtual ubig hash(double value) const;
		virtual ubig hash(const CString& value) const;

		virtual ubig hash(const Byte& value) const;
		virtual ubig hash(const Short& value) const;
		virtual ubig hash(const UShort& value) const;
		virtual ubig hash(const Integer& value) const;
		virtual ubig hash(const UInteger& value) const;
		virtual ubig hash(const Big& value) const;
		virtual ubig hash(const UBig& value) const;
		virtual ubig hash(const Real& value) const;

		virtual ubig hash(const Hashable& value) const;
	};
};

#pragma once

#include "../Basic/Defines.h"
#include "../Foundation/CString.h"
#include "../Foundation/Number.h"
#include <vector>

namespace easy {
	/*
	 * Performs simple transformations from one data to CString.
	 */
	template <typename T>
	struct _BaseRealValueFormatter {
		T parse(bool value) const {
			return T(value);
		}

		T parse(char value) const {
			return T(value);
		}

		T parse(byte value) const {
			return T(value);
		}

		T parse(short value) const {
			return T(value);
		}

		T parse(ushort value) const {
			return T(value);
		}

		T parse(integer value) const {
			return T(value);
		}

		T parse(uinteger value) const {
			return T(value);
		}

		T parse(big value) const {
			return T(value);
		}

		T parse(ubig value) const {
			return T(value);
		}

		T parse(float value) const {
			return T(value);
		}

		T parse(real value) const {
			return T(value);
		}

		T parse(const Byte& value) const {
			return T(value.value);
		}

		T parse(const Short& value) const {
			return T(value.value);
		}

		T parse(const UShort& value) const {
			return T(value.value);
		}

		T parse(const Integer& value) const {
			return T(value.value);
		}

		T parse(const UInteger& value) const {
			return T(value.value);
		}

		T parse(const Big& value) const {
			return T(value.value);
		}

		T parse(const UBig& value) const {
			return T(value.value);
		}

		T parse(const Float& value) const {
			return T(value.value);
		}

		T parse(const Real& value) const {
			return T(value.value);
		}

		T parse(const StringRepresentable& value) const {
			return T(value.toString().asReal());
		}
	};

	struct RealValueFormatter: _BaseRealValueFormatter<real> {

	};

	struct RealFormatter: _BaseRealValueFormatter<Real> {

	};
};

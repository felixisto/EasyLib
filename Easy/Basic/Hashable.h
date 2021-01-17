#pragma once

#include "Defines.h"

namespace easy {
	/*
	 * Describes an object with a unique number value.
	 */
	struct Hashable {
		virtual ~Hashable() {}

		virtual ubig hashValue() const = 0;
	};

	/*
	 * Describes an object that can be copied.
	 */
	template<typename T>
	struct Copyable {
		virtual ~Copyable() {}

		// Always returns non-null.
		virtual T copy() const = 0;
	};
};

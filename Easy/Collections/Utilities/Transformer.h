#pragma once

#include "Transformer.h"

namespace easy {
	template <typename T>
	struct Transformer {
		virtual void transform(T& value) const = 0;
	};
};

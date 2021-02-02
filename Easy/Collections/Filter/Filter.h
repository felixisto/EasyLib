#pragma once

namespace easy {
	template <typename T>
	struct Filter {
		// Return false to filter out the element.
		virtual bool filter(const T& arg) = 0;

		virtual ~Filter() {}
	};
};

#pragma once

#include "Logging.h"

namespace easy {
	namespace samples {
		struct SampleTest {
			virtual ~SampleTest() {}

			virtual bool performAll() = 0;
		};
	};
};

#pragma once

#include "../Basic/Defines.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

namespace easy {
	struct ErrorHandling {
		static void assertIf(bool expression, cstring message) {
			if (!expression) {
				fatalError(message);
			}
		}

		static void fatalError(cstring message) {
			printf("Fatal error: %s\n", message);
			printf("Stack trace: %s\n", Stack::stackTrace(true, false, true).c_str());
			assert(message);
			exit(1);
		}
	};
};

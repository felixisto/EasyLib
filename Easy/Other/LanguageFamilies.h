#pragma once

#include "LanguageFamily.h"
#include "../Collections/Array/List.h"

namespace easy {
	struct LanguageFamilies {
		static List<LanguageFamily> ALL();

		// # Primary

		static LanguageFamily INDO_EUROPEAN();

		// # Sub

		static LanguageFamily GERMANIC();
		static LanguageFamily WEST_GERMANIC();
		static LanguageFamily NORTH_SEA_GERMANIC();
		static LanguageFamily ANGLO_FRISIAN();
		static LanguageFamily ANGLIC();

	private:
		static List<LanguageFamily> CREATE_ALL();
		static List<LanguageFamily> CREATE_PRIMARY();
		static List<LanguageFamily> CREATE_SUB();
	};
};

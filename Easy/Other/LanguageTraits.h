#pragma once

#include "../Foundation/CString.h"

namespace easy {
	struct LanguageFamily {
		ubig type = 0;
		CString name;

		LanguageFamily() {

		}

		LanguageFamily(const LanguageFamily& other) : type(other.type), name(other.name) {

		}

		bool operator==(const LanguageFamily& other) const {
			return type == other.type && name == other.name;
		}

		LanguageFamily& operator=(const LanguageFamily& other) {
			type = other.type;
			name = other.name;
			return *this;
		}
	};
};
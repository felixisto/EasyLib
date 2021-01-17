#pragma once

#include "Defines.h"
#include <string>
#include <stdarg.h>
#include <assert.h>

// # Interfaces
namespace easy {
	struct CString;

	/*
	 * Describes an object with a string.
	 */
	struct StringRepresentable {
		virtual ~StringRepresentable() {}

		virtual CString toString() const = 0;
	};
};

// # std::string helpers
namespace easy {
	// Usage:
	// The first argument should be a std::string.
	// Second argument must be a variadic parameter. Can't be a literal.
	// STDSTRING_FORMAT(str, "%f", 1) will NOT work. Must pass a variadic variable.
	#define STDSTRING_FORMAT(_string_, _format_, ...) \
		const uinteger ___capacity = 64; \
		uinteger ___length = 0; \
		char ___str[___capacity + 1]; \
		char* ___s = ___str; \
		va_list ___vl; \
		va_start(___vl, _format_); \
		___length = vsnprintf(___str, ___capacity, _format_, ___vl); \
		va_end(___vl); \
		if (___length >= ___capacity) { \
			___s = new char[___length + 1]; \
			va_start(___vl, _format_); \
			vsnprintf(___s, (___length + 1), _format_, ___vl); \
			va_end(___vl); \
			_string_ = std::string(___s); \
			delete[] ___s; \
		} \
		else { \
			_string_ = std::string(___str); \
		}

	static std::string stringFromFormat(const char* format, ...) {
		std::string string;
		STDSTRING_FORMAT(string, format);
		return string;
	}

	static size_t stringIndexOf(std::string& string, const std::string& target) {
		size_t start_pos = 0;

		if ((start_pos = string.find(target, start_pos)) != std::string::npos) {
			return start_pos;
		}

		return std::string::npos;
	}

	static bool stringContains(std::string& string, const std::string& target) {
		return stringIndexOf(string, target) != std::string::npos;
	}

	static void stringReplace(std::string& string, const std::string& target, const std::string& replacement) {
		const size_t targetLength = target.length();
		const size_t replacementLength = replacement.length();
		size_t start_pos = 0;

		while ((start_pos = string.find(target, start_pos)) != std::string::npos) {
			string.replace(start_pos, targetLength, replacement);
			start_pos += replacementLength + 1;
		}
	}
};

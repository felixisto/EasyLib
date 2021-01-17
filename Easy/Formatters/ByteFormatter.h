#pragma once

#include "../Basic/Defines.h"
#include "../Foundation/CString.h"
#include "../Foundation/Number.h"
#include <vector>

namespace easy {
	/*
	 * Byte and hex formatter. 
	 */
	struct ByteFormatter {
		bool uppercase = true;

		// You can split the values by a symbol each @separatorValuesBySize characters.
		CString separator;
		integer separatorValuesBySize = 0;

		CString parse(char value) const {
			return uppercase ? CString::format("%02X", value) : CString::format("%02x", value);
		}

		CString parse(byte value) const {
			return uppercase ? CString::format("%02X", value) : CString::format("%02x", value);
		}

		CString parse(char16_t value) const {
			return uppercase ? CString::format("%04X", value) : CString::format("%04x", value);
		}

		template <typename T>
		CString parseSpecific(const T* value, integer length) const {
			CString result;

			int currentWidth = 0;

			for (int e = 0; e < length; e++) {
				if (e > 0 && !separator.isEmpty() && separatorValuesBySize != 0 && currentWidth == separatorValuesBySize) {
					currentWidth = 0;
					result += separator;
				}

				result += parse(value[e]);

				currentWidth++;
			}

			return result;
		}

		CString parse(const char* value, integer length) const {
			return parseSpecific(value, length);
		}

		CString parse(const byte* value, integer length) const {
			return parseSpecific(value, length);
		}

		CString parse(const char16_t* value, integer length) const {
			return parseSpecific(value, length);
		}
	};
};

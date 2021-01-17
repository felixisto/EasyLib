#pragma once

#include "../Basic/Defines.h"
#include "../Foundation/CString.h"
#include "../Collections/Enumeration/PairIterator.h"
#include <vector>

namespace easy {
	/*
	 * Performs simple transformations from one data to CString. 
	 */
	struct StringFormatter {
		CString parse(const void* pointer) const {
			return CString::format("%p", pointer);
		}

		CString parse(void* pointer) const {
			return CString::format("%p", pointer);
		}

		CString parse(bool value) const {
			return CString::format("%d", value);
		}

		CString parse(char value) const {
			return CString::format("%c", value);
		}

		CString parse(char16_t value) const {
			return CString::format("%c", value);
		}

		CString parse(byte value) const {
			return CString::format("%d", value);
		}

		CString parse(short value) const {
			return CString::format("%d", value);
		}

		CString parse(ushort value) const {
			return CString::format("%d", value);
		}

		CString parse(integer value) const {
			return CString::format("%d", value);
		}

		CString parse(uinteger value) const {
			return CString::format("%d", value);
		}

		CString parse(big value) const {
			return CString::format("%lld", value);
		}

		CString parse(ubig value) const {
			return CString::format("%llu", value);
		}

		CString parse(float value) const {
			return CString::format("%.2f", value);
		}

		CString parse(double value) const {
			return CString::format("%.2f", value);
		}

		CString parse(const StringRepresentable& value) const {
			return CString::format("%s", value.toString().buffer());
		}

		template<typename T>
		CString _parseGenericIterator(T iterator, CString opening, CString closing, CString separation) const {
			CString str = opening;

			integer e = 0;

			while (iterator.hasNext()) {
				if (e != 0) {
					str += separation;
				}

				str += parse(*iterator);

				iterator++;
				e++;
			}

			str += closing;

			return str;
		}

		template<typename T>
		CString list(VectorIterator<T> iterator) const {
			return _parseGenericIterator(iterator, "[", "]", "; ");
		}

		template<typename T>
		CString set(SetIterator<T> iterator) const {
			return _parseGenericIterator(iterator, "(", ")", "; ");
		}

		template<typename Key, typename T>
		CString dictionary(MapIterator<Key, T> iterator) const {
			CString result = "{";

			integer count = 0;

			for (; iterator.hasNext(); ++iterator) {
				if (count > 0) {
					result += "; ";
				}

				auto first = iterator.get().first.toString();
				auto second = iterator.get().second.toString();

				result += CString::format("'%s' = %s", first.buffer(), second.buffer());

				count++;
			}

			result += "}";

			return result;
		}
	};
};

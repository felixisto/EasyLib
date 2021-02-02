#pragma once

#include "Filter.h"
#include "../../Basic/Constraints.h"

namespace easy {
	template <typename T>
	struct FilterEquality: Filter<T> {
		static_assert(constraints::isEqualityComparable<T>::value, "<T> must support equality");

		const T& v;

		FilterEquality(const T& value) : v(value) {

		}

		virtual bool filter(const T& arg) {
			return arg == v;
		}
	};

	template <typename T>
	struct FilterInequality: Filter<T> {
		static_assert(constraints::isInequalityComparable<T>::value, "<T> must support inequality");

		const T& v;

		FilterInequality(const T& value) : v(value) {

		}

		virtual bool filter(const T& arg) {
			return arg != v;
		}
	};

	template <typename T>
	struct FilterGreaterThan: Filter<T> {
		static_assert(constraints::isGreaterComparable<T>::value, "<T> must support greater comparison");

		const T& v;

		FilterGreaterThan(const T& value) : v(value) {

		}

		virtual bool filter(const T& arg) {
			return arg > v;
		}
	};

	template <typename T>
	struct FilterGreaterThanOrEqualTo: Filter<T> {
		static_assert(constraints::isEqualityComparable<T>::value, "<T> must support equality");
		static_assert(constraints::isGreaterComparable<T>::value, "<T> must support greater comparison");

		const T& v;

		FilterGreaterThanOrEqualTo(const T& value) : v(value) {

		}

		virtual bool filter(const T& arg) {
			return arg >= v;
		}
	};

	template <typename T>
	struct FilterLessThan: Filter<T> {
		static_assert(constraints::isLesserComparable<T>::value, "<T> must support lesser comparison");

		const T& v;

		FilterLessThan(const T& value) : v(value) {

		}

		virtual bool filter(const T& arg) {
			return arg < v;
		}
	};

	template <typename T>
	struct FilterLessThanOrEqualTo: Filter<T> {
		static_assert(constraints::isEqualityComparable<T>::value, "<T> must support equality");
		static_assert(constraints::isLesserComparable<T>::value, "<T> must support lesser comparison");

		const T& v;

		FilterLessThanOrEqualTo(const T& value) : v(value) {

		}

		virtual bool filter(const T& arg) {
			return arg <= v;
		}
	};

	template <typename T>
	struct FilterByUnique : Filter<T> {
		static_assert(constraints::isEqualityComparable<T>::value, "<T> must support equality");

	private:

		std::vector<const T*> _cache;

	public:

		FilterByUnique() {

		}

		bool contains(const T* element) const {
			size_t size = _cache.size();

			for (size_t e = 0; e < size; e++) {
				const T* current = _cache[e];

				if (*current == *element) {
					return true;
				}
			}

			return false;
		}

		virtual bool filter(const T& arg) {
			if (contains(&arg)) {
				return false;
			}

			_cache.push_back(&arg);

			return true;
		}
	};
};

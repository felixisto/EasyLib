#pragma once

#include "../../Basic/Constraints.h"
#include "../../Collections/Enumeration/MutableIterator.h"

namespace easy {
	struct ReverseSorting {
		// Reverses the given vector.
		template <typename E>
		static void sortVector(std::vector<E>& data) {
			std::reverse(data.begin(), data.end());
		}

		// Reverses a collection using the given iterator (see Collections Iterator).
		template <typename IteratorType>
		static void sortIterator(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			integer size = iterator.distance();

			if (size <= 1) {
				return;
			}

			auto it = iterator;

			while (it.distance() > 1) {
				it.moveEndBackwards();
				it.swapCurrentWithEnd();

				it++;
			}
		}
	};
	/*
	 * Sorts a mutable collection directly.
	 *
	 * The given iterators must be mutable.
	 *
	 * Relies on iterators to sort, so, if the given iterators are invalidated, this component is also invalidated.
	 */
	template <typename IteratorType, typename E>
	struct ReverseSort {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

		ReverseSort(IteratorType iterator) : _iterator(iterator) {

		}

		ReverseSort(const ReverseSort<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		void sort() {
			ReverseSorting::sortIterator(_iterator);
		}
	};
};

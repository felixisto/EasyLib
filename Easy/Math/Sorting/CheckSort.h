#pragma once

#include "../../Basic/Constraints.h"
#include "../../Collections/Enumeration/MutableIterator.h"

namespace easy {
	struct CheckSorting {
		// Sorts the given vector.
		template <typename E>
		static bool isVectorSorted(const std::vector<E>& data) {
			return std::is_sorted(data.cbegin(), data.cend());
		}

		// Sorts a collection using the given iterator (see Collections Iterator).
		template <typename IteratorType>
		static bool isIteratorSorted(IteratorType iterator) {
			static_assert(constraints::isReadIterator<IteratorType>::value, "<IteratorType> must be a read iterator");

			return std::is_sorted(iterator.currentPointer().pointer(), iterator.endPointer().pointer());
		}
	};

	/*
	 * Checks if a collection is sorted.
	 *
	 * Relies on iterators to sort, so, if the given iterators are invalidated, this component is also invalidated.
	 */
	template <typename IteratorType, typename E>
	struct CheckSort {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

		CheckSort(IteratorType iterator) : _iterator(iterator) {

		}

		CheckSort(const CheckSort<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		bool isSorted() {
			return CheckSorting::isSorted(_iterator);
		}
	};
};

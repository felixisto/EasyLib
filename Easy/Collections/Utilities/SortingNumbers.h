#pragma once

#include "../../Basic/Constraints.h"
#include "../../Math/Sorting/CheckSort.h"
#include "../../Math/Sorting/ReverseSort.h"
#include "../../Math/Sorting/BubbleSort.h"
#include "../../Math/Sorting/InsertionSort.h"
#include "../../Math/Sorting/SelectionSort.h"
#include "../../Math/Sorting/MergeSort.h"
#include "../../Math/Sorting/QuickSort.h"
#include "../../Math/Sorting/HeapSort.h"

namespace easy {
	/*
	 * Uses general sorting algorithm to sort number collections. Mutates the collection directly.
	 * 
	 * The given iterators must be mutable.
	 * 
	 * Relies on iterators to sort, so, if the given iterators are invalidated, this component is also invalidated.
	 */
	template <typename IteratorType, typename E>
	struct SortingNumbers {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");
		static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

		SortingNumbers(IteratorType iterator) : _iterator(iterator) {

		}

		SortingNumbers(const SortingNumbers<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		bool isSorted() {
			return CheckSorting::isIteratorSorted(_iterator);
		}

		void sortByAscending() {
			integer size = _iterator.distance();

			if (size < 1000) {
				BubbleSorting::sortIterator(_iterator);
			} else {
				InsertionSorting::sortIterator(_iterator);
			}
		}

		void sortByDescending() {
			sortByAscending();
			reverse();
		}

		void reverse() {
			ReverseSorting::sortIterator(_iterator);
		}
	};
};

#pragma once

#include "../../Basic/Constraints.h"
#include "../../Collections/Enumeration/MutableIterator.h"

namespace easy {
	/*
	 * Selection sort is an in-place comparison sorting algorithm.
	 *
	 * The algorithm divides the input list into two parts: a sorted sublist of items
	 * which is built up from left to right at the front (left) of the list
	 * and a sublist of the remaining unsorted items that occupy the rest of the list.
	 * The algorithm proceeds by finding the smallest (or largest, depending on sorting order)
	 * element in the unsorted sublist, swapping it with the leftmost unsorted element (putting it in sorted order),
	 * and moving the sublist boundaries one element to the right.
	 * 
	 * Generally performs worse than the similar insertion sort.
	 * 
	 * Best-case: O(n^2)
	 * Average performance: O(n^2)
	 * Worst-case: O(n^2)
	 * Worst-case space complexity: O(1)
	 * Stable: no
	 */
	struct SelectionSorting {
		// Sorts the given vector.
		template <typename E>
		static void sortVector(std::vector<E>& data) {
			static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
			static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

			auto begin = data.begin();
			auto end = data.begin();

			for (auto i = begin; i != end; ++i) {
				std::iter_swap(i, std::min_element(i, end));
			}
		}

		// Sorts a collection using the given iterator (see Collections Iterator).
		template <typename IteratorType>
		static void sortIterator(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			while (iterator.hasNext()) {
				auto minimum = iterator.getMinimumPointer();
				iterator.currentPointer().swapWith(minimum);
				iterator++;
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
	struct SelectionSort {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

		SelectionSort(IteratorType iterator) : _iterator(iterator) {

		}

		SelectionSort(const SelectionSort<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		void sort() {
			SelectionSorting::sortIterator(_iterator);
		}
	};
};

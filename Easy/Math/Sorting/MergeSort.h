#pragma once

#include "../../Basic/Constraints.h"
#include "../../Collections/Enumeration/MutableIterator.h"

namespace easy {
	/*
	 * Efficient, general-purpose, divide and conquer and comparison-based sorting algorithm.
	 *
	 * Works in 2 steps:
	 * 1. Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
	 * 2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.
	 * 
	 * Comparing it to quicksort, this algorithm is slightly faster but takes more space.
	 * 
	 * Best-case: O(n log n)
	 * Average performance: O(n log n)
	 * Worst-case: O(n log n)
	 * Worst-case space complexity: O(n)
	 * Stable: yes
	 */
	struct MergeSorting {
	private:

		template <typename Iterator>
		static void mergeSort(Iterator begin, Iterator end) {
			if (end <= begin + 1) {
				return;
			}

			Iterator middle = begin + (end - begin) / 2;

			mergeSort(begin, middle);
			mergeSort(middle, end);

			std::inplace_merge(begin, middle, end);
		}
	public:
		// Sorts the given vector.
		template <typename E>
		static void sortVector(std::vector<E>& data) {
			if (1 < data.size()) {
				std::vector<E> array1(data.begin(), data.begin() + data.size() / 2);
				sortVector(array1);
				std::vector<E> array2(data.begin() + data.size() / 2, data.end());
				sortVector(array2);

				data.clear();

				std::merge(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(data));
			}
		}

		// Sorts a collection using the given iterator (see Collections Iterator).
		// In-place merge.
		template <typename IteratorType>
		static void sortIterator(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			mergeSort(iterator.currentPointer().pointer(), iterator.endPointer().pointer());
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
	struct MergeSort {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

		MergeSort(IteratorType iterator) : _iterator(iterator) {

		}

		MergeSort(const MergeSort<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		void sort() {
			MergeSorting::sortIterator(_iterator);
		}
	};
};

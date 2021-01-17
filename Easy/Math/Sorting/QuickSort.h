#pragma once

#include "../../Basic/Constraints.h"
#include "../../Collections/Enumeration/MutableIterator.h"

namespace easy {
	/*
	 * Quicksort (sometimes called partition-exchange sort) is an efficient sorting algorithm. 
	 *
	 * Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot'
	 * element from the array and partitioning the other elements into two sub-arrays,
	 * according to whether they are less than or greater than the pivot.
	 * The sub-arrays are then sorted recursively.
	 * 
	 * Best-case: simple partition O(n log n)
	 * Average performance: O(n log n)
	 * Worst-case: O(n^2)
	 * Worst-case space complexity: naive O(log n)
	 * Stable: no
	 */
	struct QuickSorting {
	private:

		template <typename E>
		static int partition(std::vector<E>& data, int p, int size) {
			const int x = data[p];
			int i = p;

			for (int e = p + 1; e < size; e++) {
				if (data[e] < x) {
					i = i + 1;
					std::swap(data[i], data[e]);
				}
			}

			std::swap(data[i], data[p]);

			return i;
		}

		template <typename E>
		static void quickSort(std::vector<E>& data, int p, int size) {
			int r;

			if (p < size) {
				r = partition(data, p, size);
				quickSort(data, p, r);
				quickSort(data, r + 1, size);
			}
		}

		template <typename IteratorType>
		static void quickSort(IteratorType begin, IteratorType end) {
			if (end <= begin) {
				return;
			}

			auto pivot = begin, middle = begin + 1;

			for (auto i = begin + 1; i < end; ++i) {
				if (*i < *pivot) {
					std::iter_swap(i, middle);
					++middle;
				}
			}

			std::iter_swap(begin, middle - 1);

			quickSort(begin, middle - 1);
			quickSort(middle, end);
		}
	public:
		// Sorts the given vector.
		// Quicksort here is done in-place with O(log n) stack space.
		template <typename E>
		static void sortVector(std::vector<E>& data) {
			static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
			static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

			quickSort(data, 0, data.size());
		}

		// Sorts a collection using the given iterator (see Collections Iterator).
		// Quicksort here is done in-place with O(log n) stack space.
		template <typename IteratorType>
		static void sortIterator(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			quickSort(iterator.currentPointer().pointer(), iterator.endPointer().pointer());
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
	struct QuickSort {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

		QuickSort(IteratorType iterator) : _iterator(iterator) {

		}

		QuickSort(const QuickSort<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		void sort() {
			QuickSorting::sortIterator(_iterator);
		}
	};
};

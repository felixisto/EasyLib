#pragma once

#include "../../Basic/Constraints.h"
#include "../../Collections/Enumeration/MutableIterator.h"

namespace easy {
	/*
	 * Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time.
	 *
	 * Insertion sort iterates, consuming one input element each repetition,
	 * and grows a sorted output list. At each iteration, insertion sort removes one element from the input data,
	 * finds the location it belongs within the sorted list, and inserts it there.
	 * It repeats until no input elements remain.
	 *
	 * Best-case: O(n)
	 * Average performance: O(n^2)
	 * Worst-case: O(n^2)
	 * Worst-case space complexity: O(1)
	 * Stable: yes
	 */
	struct InsertionSorting {
		// Sorts the given vector.
		template <typename E>
		static void sortVector(std::vector<E>& data) {
			static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
			static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

			int min = 0;
			int max = data.size();
			int key = 0;

			// We loop trough all elements in the original array from the second element
			for (int e = 1; e < max; ++e) {
				// Store the current element as the key
				key = data[e];

				// Get the element index just before the current element index
				int i = e - 1;

				// Loop trough all elements from the key to the start
				// Check if the current element is smaller than the key
				while (i >= 0 && data[i] > key) {
					// We move the current element backwards
					data[i + 1] = data[i];
					i--;
				}

				// We finally move the key
				data[i + 1] = key;
			}
		}

		// Sorts a collection using the given iterator (see Collections Iterator).
		template <typename IteratorType>
		static void sortIterator(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			auto minimum = iterator.getMinimumPointer();
			iterator.currentPointer().swapWith(minimum);

			auto begin = iterator.currentPointer();
			auto end = iterator.endPointer();

			for (auto b = begin; ++b < end; begin = b) {
				for (auto c = b; *c < *begin; --c, --begin) {
					begin.swapWith(c);
				}
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
	struct InsertionSort {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

		InsertionSort(IteratorType iterator) : _iterator(iterator) {

		}

		InsertionSort(const InsertionSort<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		void sort() {
			InsertionSorting::sortIterator(_iterator);
		}
	};
};

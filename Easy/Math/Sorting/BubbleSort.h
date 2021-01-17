#pragma once

#include "../../Basic/Constraints.h"
#include "../../Collections/Enumeration/MutableIterator.h"

namespace easy {
	/*
	 * Bubble sort, also referred to as sinking sort is a sorting algorithm.
	 * 
	 * Works by repeatedly stepping through a list,
	 * compares adjacent elements and swaps them if they are in the wrong order.
	 * 
	 * Another thing about the bubble sort is its tiny code size compared to other sorting algorithms.
	 * 
	 * Best-case: O(n)
	 * Average performance: O(n^2)
	 * Worst-case: O(n^2)
	 * Worst-case space complexity: O(1)
	 * Stable: yes
	 */
	struct BubbleSorting {
		// Sorts the given vector.
		template <typename E>
		static void sortVector(std::vector<E>& data) {
			static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
			static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

			int temp;

			for (int i = 0; i < data.size(); ++i) {
				for (int e = 0; e < data.size() - i - 1; ++e) {
					if (data[e + 1] < data[e]) {
						temp = data[e + 1];
						data[e + 1] = data[e];
						data[e] = temp;
					}
				}
			}
		}

		// Sorts a collection using the given iterator (see Collections Iterator).
		template <typename IteratorType>
		static void sortIterator(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			for (auto i = iterator; i.hasNext(); ++i) {
				for (auto j = iterator; j < i; ++j) {
					if (*i < *j) {
						i.swapCurrentWith(j);
					}
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
	struct BubbleSort {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

		BubbleSort(IteratorType iterator) : _iterator(iterator) {

		}

		BubbleSort(const BubbleSort<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		void sort() {
			BubbleSorting::sortIterator(_iterator);
		}
	};
};

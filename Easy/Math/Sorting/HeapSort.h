#pragma once

#include "../../Basic/Constraints.h"
#include "../../Collections/Enumeration/MutableIterator.h"

namespace easy {
	/*
	 * Heapsort is a comparison-based sorting algorithm.
	 *
	 * Heapsort can be thought of as an improved selection sort: like selection sort, heapsort divides its input into a sorted and an unsorted region,
	 * and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. 
	 *
	 * Best-case: O(n log n)
	 * Average performance: O(n log n)
	 * Worst-case: O(n log n)
	 * Worst-case space complexity: O(1) - yes, O(1)
	 * Stable: no
	 */
	struct HeapSorting {
	private:

		// Heapify a subtree rooted with node with index @i in @data.
		// @n size of the heap
		// @i index of a node
		template <typename El>
		static void heapify(std::vector<El>& data, int size, int i) {
			int largest = i; // Init largest as root
			int l = 2 * i + 1; // left
			int r = 2 * i + 2; // right

			// If left child is larger than root
			if (l < size && data[l] > data[largest]) {
				largest = l;
			}

			// If right child is larger than root
			if (r < size && data[r] > data[largest]) {
				largest = r;
			}

			// If largest is not root
			if (largest != i) {
				std::swap(data[i], data[largest]);

				// Recursively heapify the affected sub-tree
				heapify(data, size, largest);
			}
		}

	public:
		// Sorts the given vector.
		template <typename E>
		static void sortVector(std::vector<E>& data) {
			static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
			static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

			const int size = data.size();

			// Build heap
			for (int i = (size / 2) - 1; i >= 0; --i) {
				heapify(data, size, i);
			}

			// One by one extract the elements from the heap
			for (int e = size - 1; e >= 0; e--) {
				// Move current root to end
				std::swap(data[0], data[e]);

				// Call max heapify on the reduced heap
				heapify(data, e, 0);
			}
		}

		template <typename IteratorType>
		static void makeHeap(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			auto begin = iterator.currentPointer().pointer();
			auto end = iterator.endPointer().pointer();

			std::make_heap(begin, end);
		}

		template <typename IteratorType>
		static void sortHeap(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			auto begin = iterator.currentPointer().pointer();
			auto end = iterator.endPointer().pointer();

			std::sort_heap(begin, end);
		}

		// Sorts a collection using the given iterator (see Collections Iterator).
		template <typename IteratorType>
		static void sortIterator(IteratorType iterator) {
			static_assert(constraints::isReadWriteIterator<IteratorType>::value, "<IteratorType> must be a read-write iterator");

			makeHeap(iterator);
			sortHeap(iterator);
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
	struct HeapSort {
	private:
		IteratorType _iterator;

	public:
		static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
		static_assert(constraints::isGreaterComparable<E>::value, "<E> must support greater comparisons");
		static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser comparisons");

		HeapSort(IteratorType iterator) : _iterator(iterator) {

		}

		HeapSort(const HeapSort<IteratorType, E>& other) : _iterator(other._iterator) {

		}

		void sort() {
			HeapSorting::sortIterator(_iterator);
		}
	};
};

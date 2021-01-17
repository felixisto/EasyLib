#pragma once

#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include "../../Tool/ErrorHandling.h"

namespace easy {
	/*
	 * Points to a specific place in a collection.
	 * 
	 * May or may not be valid.
	 * Begin pointers point to the first element.
	 * End points point past the last element of the collection.
	 */
	template <typename IteratorType, typename ElementType>
	struct IteratorPointer {
	protected:
		IteratorType _it;

	public:
		using ReverseItType = std::reverse_iterator<IteratorType>;

		IteratorPointer() {

		}

		IteratorPointer(const IteratorPointer<IteratorType, ElementType>& other) : _it(other._it) {

		}

		IteratorPointer(IteratorType it) : _it(it) {

		}

		bool operator==(const IteratorPointer& other) const {
			return _it == other._it;
		}

		bool operator!=(const IteratorPointer& other) const {
			return _it != other._it;
		}

		bool operator<(const IteratorPointer& other) const {
			return _it < other._it;
		}

		bool operator>(const IteratorPointer& other) const {
			return _it > other._it;
		}

		const ElementType& operator*() const {
			return get();
		}

		IteratorPointer<IteratorType, ElementType>& operator++() {
			_it++;
			return *this;
		}

		IteratorPointer<IteratorType, ElementType> operator++(int postFix) {
			auto old = *this;
			_it++;
			return old;
		}

		IteratorPointer<IteratorType, ElementType>& operator--() {
			_it--;
			return *this;
		}

		IteratorPointer<IteratorType, ElementType> operator--(int postFix) {
			auto old = *this;
			_it--;
			return old;
		}

		// # Access

		const IteratorType& pointer() const {
			return _it;
		}

		IteratorType& pointer() {
			return _it;
		}

		const ElementType& get() const {
			return *_it;
		}

		// # Modification

		void next() {
			_it++;
		}

		void moveForwards() {
			_it++;
		}

		void moveBackwards() {
			_it--;
		}

		void swapWith(IteratorPointer<IteratorType, ElementType>& pointer) {
			std::iter_swap(_it, pointer._it);
		}

		// # Other

		IteratorPointer<ReverseItType, ElementType> reverse() const {
			auto it = std::reverse_iterator<IteratorType>(_it);
			return IteratorPointer<ReverseItType, ElementType>(it);
		}
	};
};

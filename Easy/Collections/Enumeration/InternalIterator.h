#pragma once

#include "IteratorPointer.h"
#include "../../Basic/Math.h"

namespace easy {
	/*
	 * Generic iterator class used by other iterators as base.
	 * 
	 * Do not use directly, use ConstIterator or MutableIterator instead.
	 */
	template <typename IteratorType, typename ElementType>
	struct InternalIterator {
		using ReverseItType = std::reverse_iterator<IteratorType>;

		IteratorPointer<IteratorType, ElementType> current;
		IteratorPointer<IteratorType, ElementType> end;

		InternalIterator() {

		}

		InternalIterator(const InternalIterator<IteratorType, ElementType>& other) : current(other.current), end(other.end) {

		}

		InternalIterator(IteratorPointer<IteratorType, ElementType> current, IteratorPointer<IteratorType, ElementType> end) : current(current), end(end) {

		}

		bool operator==(const InternalIterator& other) const {
			return current == other.current;
		}

		bool operator!=(const InternalIterator& other) const {
			return current != other.current;
		}

		bool operator<(const InternalIterator& other) const {
			return current < other.current;
		}

		bool operator>(const InternalIterator& other) const {
			return current > other.current;
		}

		const ElementType& operator*() const {
			return get();
		}

		InternalIterator<IteratorType, ElementType>& operator++() {
			current++;
			return *this;
		}

		InternalIterator<IteratorType, ElementType> operator++(int postFix) {
			auto old = *this;
			current++;
			return old;
		}

		// # Access pointers

		// Returns the smallest value found via <.
		IteratorPointer<IteratorType, ElementType> getMinimumPointer() const {
			return std::min_element(current.pointer(), end.pointer());
		}

		// Returns the highest value found via <.
		IteratorPointer<IteratorType, ElementType> getMaximumPointer() const {
			return std::max_element(current.pointer(), end.pointer());
		}

		// Returns the smallest value found via <.
		IteratorPointer<IteratorType, ElementType> getMinimumPointer() {
			return std::min_element(current.pointer(), end.pointer());
		}

		// Returns the highest value found via <.
		IteratorPointer<IteratorType, ElementType>&getMaximumPointer() {
			return std::max_element(current.pointer(), end.pointer());
		}

		// # Access values

		const ElementType& get() const {
			ErrorHandling::assertIf(hasNext(), "Reading current Iterator value past end");
			return *current;
		}

		const ElementType& getEnd() const {
			return *end;
		}

		// Length between the base and end. Always non-negative value.
		integer distance() const {
			integer distance = (integer)std::distance(current.pointer(), end.pointer());
			return math::absolute(distance);
		}

		bool hasNext() const {
			// Dont use less than here, it will not work in all cases
			return current != end;
		}

		// # Modification

		bool next() {
			operator++();
			return hasNext();
		}

		bool moveCurrentForwards() {
			current++;
			return hasNext();
		}

		void moveEndForwards() {
			end++;
		}

		bool moveCurrentBackwards() {
			current--;
			return hasNext();
		}

		void moveEndBackwards() {
			end--;
		}
	};
};

#pragma once

#include "InternalIterator.h"

namespace easy {
	template <typename IteratorType, typename ElementType>
	struct ConstIterator;

	template <typename E>
	using VectorIterator = ConstIterator<typename std::vector<E>::const_iterator, E>;

	template <typename E>
	using SetIterator = ConstIterator<typename std::set<E>::const_iterator, E>;

	/*
	 * Component used to enumerate a collection. Modifying the source collection may invalidate the iterator.
	 * 
	 * Knows where the collections starts and where it ends.
	 *
	 * Values are immutable.
	 */
	template <typename IteratorType, typename ElementType>
	struct ConstIterator: ReadIterator {
	protected:
		InternalIterator<IteratorType, ElementType> _iterator;

	public:
		using ReverseItType = std::reverse_iterator<IteratorType>;

		ConstIterator() {

		}

		ConstIterator(const ConstIterator<IteratorType, ElementType>& other) : _iterator(other._iterator) {
			
		}

		ConstIterator(IteratorPointer<IteratorType, ElementType> current, IteratorPointer<IteratorType, ElementType> end) : _iterator(current, end) {

		}

		bool operator==(const ConstIterator& other) const {
			return _iterator == other._iterator;
		}

		bool operator!=(const ConstIterator& other) const {
			return _iterator != other._iterator;
		}

		bool operator<(const ConstIterator& other) const {
			return _iterator < other._iterator;
		}

		bool operator>(const ConstIterator& other) const {
			return _iterator > other._iterator;
		}

		const ElementType& operator*() const {
			return _iterator.get();
		}

		ConstIterator<IteratorType, ElementType>& operator++() {
			_iterator++;
			return *this;
		}

		ConstIterator<IteratorType, ElementType> operator++(int postFix) {
			auto old = *this;
			_iterator++;
			return old;
		}

		// # Access pointers

		IteratorPointer<IteratorType, ElementType> currentPointer() const {
			return _iterator.current;
		}

		IteratorPointer<IteratorType, ElementType> endPointer() const {
			return _iterator.end;
		}

		// Returns the smallest value found via <.
		IteratorPointer<IteratorType, ElementType> getMinimumPointer() const {
			return _iterator.getMinimumPointer();
		}

		// Returns the highest value found via <.
		IteratorPointer<IteratorType, ElementType> getMaximumPointer() const {
			return _iterator.getMaximumPointer();
		}

		// # Access values

		const ElementType& get() const {
			return _iterator.get();
		}

		// Returns the smallest value found via <.
		const ElementType& getMinimum() const {
			return _iterator.getMinimum();
		}

		// Returns the highest value found via <.
		const ElementType& getMaximum() const {
			return _iterator.getMaximum();
		}

		// Length between the base and end. Always non-negative value.
		integer distance() const {
			return _iterator.distance();
		}

		bool hasNext() const {
			return _iterator.hasNext();
		}

		// # Modification

		bool next() {
			return _iterator.next();
		}

		bool moveBaseForwards() {
			return _iterator.moveCurrentForwards();
		}

		void moveEndForwards() {
			_iterator.moveEndForwards();
		}

		bool moveBaseBackwards() {
			return _iterator.moveCurrentBackwards();
		}

		void moveEndBackwards() {
			_iterator.moveEndBackwards();
		}

		// # Other

		ConstIterator<ReverseItType, ElementType> reverse() const {
			auto end = _iterator.current.reverse();
			auto begin = _iterator.end.reverse();

			return ConstIterator<ReverseItType, ElementType>(begin, end);
		}
	};
};

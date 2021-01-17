#pragma once

#include "ConstIterator.h"

namespace easy {
	template <typename IteratorType, typename ElementType>
	struct MutableIterator;

	template <typename E>
	using MutableVectorIterator = MutableIterator<typename std::vector<E>::iterator, E>;

	template <typename E>
	using MutableSetIterator = MutableIterator<typename std::set<E>::iterator, E>;

	/*
	 * Mutable version of Iterator - values can be read from and written to.
	 *
	 * @see Iterator
	 */
	template <typename IteratorType, typename ElementType>
	struct MutableIterator: ReadWriteIterator {
	protected:
		InternalIterator<IteratorType, ElementType> _iterator;

	public:
		using ReverseItType = std::reverse_iterator<IteratorType>;

		MutableIterator() {

		}

		MutableIterator(const MutableIterator<IteratorType, ElementType>& other) : _iterator(other._iterator) {

		}

		MutableIterator(IteratorPointer<IteratorType, ElementType> current, IteratorPointer<IteratorType, ElementType> end) : _iterator(current, end) {

		}

		bool operator==(const MutableIterator& other) const {
			return _iterator == other._iterator;
		}

		bool operator!=(const MutableIterator& other) const {
			return _iterator != other._iterator;
		}

		bool operator<(const MutableIterator& other) const {
			return _iterator < other._iterator;
		}

		bool operator>(const MutableIterator& other) const {
			return _iterator > other._iterator;
		}

		ElementType& operator*() {
			return *_iterator.current.pointer();
		}

		MutableIterator<IteratorType, ElementType>& operator++() {
			_iterator++;
			return *this;
		}

		MutableIterator<IteratorType, ElementType> operator++(int postFix) {
			auto old = *this;
			_iterator++;
			return old;
		}

		// # Access pointers

		const IteratorPointer<IteratorType, ElementType>& currentPointer() const {
			return _iterator.current;
		}

		const IteratorPointer<IteratorType, ElementType>& endPointer() const {
			return _iterator.end;
		}

		IteratorPointer<IteratorType, ElementType>& currentPointer() {
			return _iterator.current;
		}

		IteratorPointer<IteratorType, ElementType>& endPointer() {
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

		// Returns the smallest value found via <.
		IteratorPointer<IteratorType, ElementType> getMinimumPointer() {
			return _iterator.getMinimumPointer();
		}

		// Returns the highest value found via <.
		IteratorPointer<IteratorType, ElementType> getMaximumPointer() {
			return _iterator.getMaximumPointer();
		}

		// # Access

		ElementType& get() {
			ErrorHandling::assertIf(hasNext(), "Reading current Iterator value past end");
			return *_iterator.current.pointer();
		}

		ElementType& getEnd() {
			return *_iterator.end.pointer();
		}

		// Returns the smallest value found via <.
		ElementType& getMinimum() {
			return *std::min_element(_iterator.current(), _iterator.end());
		}

		// Returns the highest value found via <.
		ElementType& getMaximum() {
			return *std::max_element(_iterator.current(), _iterator.end());
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

		bool hasNext() {
			return _iterator.hasNext();
		}

		// # Modification

		bool next() {
			return _iterator.next();
		}

		bool moveBaseForwards() {
			_iterator.moveCurrentForwards();
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

		void swapCurrentWith(MutableIterator<IteratorType, ElementType>& other) {
			_iterator.current.swapWith(other._iterator.current);
		}

		void swapCurrentWithEnd() {
			_iterator.current.swapWith(_iterator.end);
		}

		ConstIterator<IteratorType, ElementType> asImmutableIterator() {
			return ConstIterator<IteratorType, ElementType>(_iterator.current, _iterator.end);
		}

		// # Other

		MutableIterator<ReverseItType, ElementType> reverseMutable() {
			auto end = _iterator.current.reverse();
			auto begin = _iterator.end.reverse();

			return MutableIterator<ReverseItType, ElementType>(begin, end);
		}
	};
};

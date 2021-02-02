#pragma once

#include "../../Basic/Basic.h"
#include "../../Tool/ErrorHandling.h"
#include "../../Math/Hashing/MurmurHash64B.h"
#include "../Enumeration/ConstIterator.h"
#include "../Enumeration/MutableIterator.h"
#include "../Utilities/Transformer.h"
#include "../Filter/Filter.h"
#include <vector>

namespace easy {
	template <typename E>
	using ListEnumeratable = VectorEnumerable<E>;

	template <typename E>
	using ListIterator = VectorIterator<E>;

	template <typename E>
	using MutableListIterator = MutableVectorIterator<E>;

	/*
	 * A zero-index ordered collection of values.
	 * 
	 * Do not use this class directly, prefer to use the other collections such as List and Vector.
	 * 
	 * Performance:
	 * Access: O(1)
	 * Back insertion: O(1) or O(n)
	 * Other insertion: O(n)
	 * Back erase: O(1)
	 * Other erase: O(n)
	 * Find sorted: O(log n)
	 * Find unsorted: O(n)
	 */
	template <typename E>
	struct BaseList {
	private:

		std::vector<E> _array;

	public:
		BaseList() {

		}

		BaseList(const BaseList& other) : _array(other._array) {

		}

		BaseList(const std::vector<E>& array) : _array(array) {

		}

		BaseList(const ListIterator<E>& it) {
			while (it.hasNext()) {
				_array.add(it.get());
				it++;
			}
		}

		virtual ~BaseList() {

		}

		// # Properties

		integer size() const {
			return _array.size();
		}

		const std::vector<E>& rawData() const {
			return _array;
		}

		// # Conversion

		std::vector<E> asSTDVector() const {
			return _array;
		}

		// # Operators

		const E& operator[](integer index) const {
			return _array[index];
		}

		E& operator[](integer index) {
			return _array[index];
		}

		bool operator==(const BaseList& other) const {
			return _array == other._array;
		}

		BaseList& operator=(const BaseList& other) {
			_array = other._array;
			return *this;
		}

		BaseList operator+(const BaseList& other) {
			auto result = *this;
			result.addAll(other);
			return result;
		}

		BaseList& operator+=(const BaseList& other) {
			addAll(other);
			return *this;
		}

		// # Query

		bool isEmpty() const {
			return _array.size() == 0;
		}

		bool isIndexValid(integer index) const {
			return index >= 0 && index < size();
		}

		E& get(integer index) {
			ErrorHandling::assertIf(isIndexValid(index), "BaseList: Out of bounds access");
			return _array[index];
		}

		const E& get(integer index) const {
			ErrorHandling::assertIf(isIndexValid(index), "BaseList: Out of bounds access");
			return _array[index];
		}

		E& first() {
			ErrorHandling::assertIf(isIndexValid(0), "BaseList: Out of bounds access");
			return _array[0];
		}

		const E& first() const {
			ErrorHandling::assertIf(isIndexValid(0), "BaseList: Out of bounds access");
			return _array[0];
		}

		E& last() {
			integer lastIndex = size() - 1;
			ErrorHandling::assertIf(isIndexValid(lastIndex), "BaseList: Out of bounds access");
			return _array[lastIndex];
		}

		const E& last() const {
			integer lastIndex = size() - 1;
			ErrorHandling::assertIf(isIndexValid(lastIndex), "BaseList: Out of bounds access");
			return _array[lastIndex];
		}

		bool contains(const E& element) const {
			return indexOf(element) != kInvalidIndex;
		}

		bool containsDuplicates() const {
			auto arrayCopy = _array;
			std::sort(arrayCopy.begin(), arrayCopy.end(), std::greater<E>());
			return std::adjacent_find(arrayCopy.begin(), arrayCopy.end()) != arrayCopy.end();
		}

		integer indexOf(const E& element, integer startFromIndex) const {
			if (!isIndexValid(startFromIndex)) {
				return kInvalidIndex;
			}

			auto startPosition = _array.begin() + startFromIndex;
			auto found = std::find(startPosition, _array.end(), element);
			integer distance = (integer)std::distance(found, _array.begin());
			integer pos = math::absolute(distance);

			if (pos >= size()) {
				return kInvalidIndex;
			}

			return pos;
		}

		integer indexOf(const E& element) const {
			return indexOf(element, 0);
		}

		integer lastIndexOf(const E& element, integer startFromIndex) const {
			startFromIndex = size() - startFromIndex;

			auto startPosition = _array.rbegin() + startFromIndex;
			auto found = std::find(startPosition, _array.rend(), element);
			integer distance = (integer)std::distance(found, _array.rend());
			integer pos = math::absolute(distance) - 1;

			if (pos >= size()) {
				return kInvalidIndex;
			}

			return pos;
		}

		integer lastIndexOf(const E& element) const {
			return lastIndexOf(element, size());
		}

		BaseList sublist(const Range& range) const {
			ErrorHandling::assertIf(isIndexValid(range.start), "BaseList: Out of bounds access");
			ErrorHandling::assertIf(range.start >= range.end && range.end <= size(), "BaseList: Out of bounds access");

			if (range.start == range.end) {
				return BaseList();
			}

			BaseList<E> result;

			int endIndex = range.end >= size() ? size() : range.end;

			for (int e = 0; e < endIndex; e++) {
				result.add(_array[e]);
			}

			return result;
		}

		// # Manipulation

		void add(const E& element) {
			_array.push_back(element);
		}

		void addAll(const BaseList<E>& other) {
			_array.insert(_array.end(), other._array.begin(), other._array.end());
		}

		void addAll(const E* buffer, integer length) {
			const E* current = buffer;

			for (int e = 0; e < length; e++) {
				add(*current);

				current++;
			}
		}

		void addAll(ListIterator<E> iterator) {
			while (iterator.hasNext()) {
				add(iterator.get());

				iterator++;
			}
		}

		void removeAt(integer index) {
			ErrorHandling::assertIf(isIndexValid(index), "BaseList: Out of bounds access");
			_array.erase(_array.begin() + index);
		}

		void removeFirst() {
			removeAt(0);
		}

		void removeLast() {
			removeAt(size() - 1);
		}

		bool removeFirst(const E& value) {
			auto index = indexOf(value);

			if (index != kInvalidIndex) {
				removeAt(index);
				return true;
			}

			return false;
		}

		bool removeLast(const E& value) {
			auto index = lastIndexOf(value);

			if (index != kInvalidIndex) {
				removeAt(index);
				return true;
			}

			return false;
		}

		void removeAll(const E& value) {
			integer index = indexOf(value);

			while (index != kInvalidIndex) {
				_array.erase(_array.begin() + index);
			}
		}

		void removeAllOverlapping(const BaseList<E>& other) {
			for (integer e = 0; e < other.size(); e++) {
				removeAll(other[e]);
			}
		}

		void removeAll() {
			_array.clear();
		}

		void insert(integer index, const E& value) {
			ErrorHandling::assertIf(index == 0 || index < size(), "BaseList: Out of bounds access");
			_array.insert(_array.begin() + index, value);
		}

		void insert(integer index, const BaseList<E>& other) {
			ErrorHandling::assertIf(index == 0 || index < size(), "BaseList: Out of bounds access");
			_array.insert(_array.begin() + index, other._array.begin(), other._array.end());
		}

		void set(integer index, const E& value) {
			ErrorHandling::assertIf(isIndexValid(index), "BaseList: Out of bounds access");
			_array[index] = value;
		}

		void replace(integer index, const E& value) {
			set(index, value);
		}

		void swap(integer a, integer b) {
			ErrorHandling::assertIf(isIndexValid(a), "BaseList: Out of bounds access");
			ErrorHandling::assertIf(isIndexValid(b), "BaseList: Out of bounds access");

			E temp = _array.at(b);

			_array[b] = _array[a];
			_array[a] = temp;
		}

		void reverse() {
			std::reverse(_array.begin(), _array.end());
		}

		// # Hashable

		virtual ubig hashValue() const {
			MurmurHash64B hasher;

			ubig hash = 0;

			for (int e = 0; e < size(); e++) {
				hash = hasher.combine(hash, hasher.hash(_array[e]));
			}

			return hash;
		}

		// # Enumeration

		virtual ListIterator<E> beginEnumeration() const {
			return ListIterator<E>(_array.cbegin(), _array.cend());
		}

		virtual MutableListIterator<E> beginMutableEnumeration() {
			return MutableListIterator<E>(_array.begin(), _array.end());
		}

		// # Convert

		BaseList<E> filterBy(Filter<E>& filter) const {
			BaseList<E> result;

			auto iterator = beginEnumeration();

			while (iterator.hasNext()) {
				auto& value = iterator.get();

				if (filter.filter(value)) {
					result.add(value);
				}

				iterator++;
			}

			return result;
		}

		void transform(const Transformer<E>& transformer) {
			auto iterator = beginMutableEnumeration();

			while (iterator.hasNext()) {
				transformer.transform(iterator.get());
				iterator++;
			}
		}
	};
};

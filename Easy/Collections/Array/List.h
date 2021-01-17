#pragma once

#include "../Collection.h"
#include "BaseList.h"
#include "../../Foundation/CString.h"

namespace easy {
	/*
     * A zero-index ordered collection of classes.
	 * 
	 * Elements must implement StringRepresentable and Hashable. Elements must also support equality.
	 * Iterators are invalidated when inserting or deleting values.
	 * 
	 * @see BaseList
     */
	template <typename E>
	struct List: Collection<E>, StringRepresentable, Hashable, Copyable<List<E>>, ListEnumeratable<E> {
	private:

		BaseList<E> _array;

	public:
		List() {

		}

		List(const List& other) : _array(other._array) {

		}

		List(ListIterator<E> it) : _array(it) {
			
		}

		List(const std::vector<E>& array) : _array(array) {

		}

		virtual ~List() {
			// The static asserts are here, so that List can work with forward declarations
			static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
			static_assert(constraints::isTypeOf<StringRepresentable, E>::value, "<E> must implement StringRepresentable");
			static_assert(constraints::isTypeOf<Hashable, E>::value, "<E> must implement Hashable");
		}

		// # Properties

		integer size() const {
			return _array.size();
		}

		// # Conversion

		std::vector<E> asSTDVector() const {
			return _array.asSTDVector();
		}

		// # Operators

		const E& operator[](integer index) const {
			return _array[index];
		}

		E& operator[](integer index) {
			return _array[index];
		}

		bool operator==(const List& other) const {
			return _array == other._array;
		}

		List& operator=(const List& other) {
			_array = other._array;
			return *this;
		}

		List operator+(const List& other) const {
			auto result = _array + other._array;
			return List(result);
		}

		List& operator+=(const List& other) {
			_array += other._array;
			return *this;
		}

		// # Query

		bool isEmpty() const {
			return _array.isEmpty();
		}

		bool isIndexValid(integer index) const {
			return _array.isIndexValid(index);
		}

		E& get(integer index) {
			return _array.get(index);
		}

		const E& get(integer index) const {
			return _array.get(index);
		}

		E& first() {
			return _array.first();
		}

		const E& first() const {
			return _array.first();
		}

		E& last() {
			return _array.last();
		}

		const E& last() const {
			return _array.last();
		}

		bool contains(const E& element) const {
			return _array.contains(element);
		}

		bool containsDuplicates() const {
			return _array.containsDuplicates();
		}

		integer indexOf(const E& element, integer startFromIndex) const {
			return _array.indexOf(element, startFromIndex);
		}

		integer indexOf(const E& element) const {
			return _array.indexOf(element);
		}

		integer lastIndexOf(const E& element, integer startFromIndex) const {
			return _array.lastIndexOf(element, startFromIndex);
		}

		integer lastIndexOf(const E& element) const {
			return _array.lastIndexOf(element);
		}

		List<E> sublist(const Range& range) const {
			return _array.sublist(range);
		}

		// # Manipulation

		void add(const E& element) {
			_array.add(element);
		}

		void addAll(const List<E>& other) {
			_array.addAll(other);
		}

		void addAll(const E* buffer, integer length) {
			_array.addAll(buffer, length);
		}

		void addAll(const ListIterator<E>& iterator) {
			_array.addAll(iterator);
		}

		void removeAt(integer index) {
			_array.removeAt(index);
		}

		void removeFirst() {
			_array.removeFirst();
		}

		void removeLast() {
			_array.removeLast();
		}

		bool removeFirst(const E& value) {
			return _array.removeFirst(value);
		}

		bool removeLast(const E& value) {
			return _array.removeLast(value);
		}

		void removeAll(const E& value) {
			_array.removeAll(value);
		}

		void removeAllOverlapping(const List<E>& other) {
			_array.removeAllOverlapping(other);
		}

		void removeAll() {
			_array.removeAll();
		}

		void removeDuplicates() {
			std::vector<E> copyValues = _array.rawData();
			int size = (int)copyValues.size();

			_array.removeAll();

			for (int e = 0; e < size; e++) {
				auto& value = copyValues[e];

				if (!contains(value)) {
					_array.add(value);
				}
			}
		}

		void insert(integer index, const E& value) {
			_array.insert(index, value);
		}

		void insert(integer index, const List<E>& other) {
			_array.insert(index, other);
		}

		void set(integer index, const E& value) {
			_array.set(index, value);
		}

		void replace(integer index, const E& value) {
			_array.replace(index, value);
		}

		void swap(integer a, integer b) {
			_array.swap(a, b);
		}

		void reverse() {
			_array.reverse();
		}

		// # StringRepresentable

		virtual CString stringRepresentableOf(const E& element) const {
			return element.toString();
		}

		virtual CString toString() const {
			CString str = "[";

			auto iterator = beginEnumeration();
			integer e = 0;

			while (iterator.hasNext()) {
				if (e != 0) {
					str += "; ";
				}

				str += stringRepresentableOf(*iterator);

				iterator++;
				e++;
			}

			str += "]";

			return str;
		}

		// # Hashable

		virtual ubig hashValue() const {
			return _array.hashValue();
		}

		// # Copyable

		virtual List copy() const {
			return *this;
		}

		// # Enumeration

		virtual ListIterator<E> beginEnumeration() const {
			return _array.beginEnumeration();
		}

		virtual MutableListIterator<E> beginMutableEnumeration() {
			return _array.beginMutableEnumeration();
		}
	};
};

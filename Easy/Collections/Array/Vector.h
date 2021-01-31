#pragma once

#include "List.h"
#include "../../Formatters/StringFormatter.h"
#include "../../Basic/Parser.h"

namespace easy {
	/*
	 * A zero-index ordered collection of primitive values or pointer values.
	 * 
	 * Elements must support equality.
	 * Iterators are invalidated when inserting or deleting values.
	 * 
	 * @see BaseList
	 */
	template <typename E>
	struct Vector: Collection<E>, StringRepresentable, Hashable, Copyable<Vector<E>>, ListEnumeratable<E> {
	private:

		BaseList<E> _array;

	public:
		Vector() {

		}

		Vector(const Vector& other) : _array(other._array) {

		}

		Vector(VectorIterator<E> it) : _array(it) {
			
		}

		Vector(const std::vector<E>& array) : _array(array) {

		}

		virtual ~Vector() {
			// The static asserts are here, so that Vector can work with forward declarations
			static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
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

		bool operator==(const Vector& other) const {
			return _array == other._array;
		}

		Vector& operator=(const Vector& other) {
			_array = other._array;
			return *this;
		}

		Vector operator+(const Vector& other) {
			_array = _array + other._array;
			return *this;
		}

		Vector& operator+=(const Vector& other) {
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

		void addAll(const Vector<E>& other) {
			_array.addAll(other._array);
		}

		void addAll(const E* buffer, integer length) {
			_array.addAll(buffer, length);
		}

		void addAll(VectorIterator<E> iterator) {
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
			static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser than comparison");

			std::sort(_array.begin(), _array.end());
			_array.erase(std::unique(_array.begin(), _array.end()), _array.end());
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

		virtual CString toString() const {
			return StringFormatter().list(beginEnumeration());
		}

		// # Hashable

		virtual ubig hashValue() const {
			return _array.hashValue();
		}

		// # Copyable

		virtual Vector copy() const {
			return *this;
		}

		// # Enumeration

		virtual ListIterator<E> beginEnumeration() const {
			return _array.beginEnumeration();
		}

		virtual MutableListIterator<E> beginMutableEnumeration() {
			return _array.beginMutableEnumeration();
		}

		// # Convert
		
		template <typename Source>
		void mapTo(const Vector<Source>& other) {
			using Destination = E;

			auto mapper = Mapper<Source, Destination>();
			auto iterator = other.beginEnumeration();
			auto parser = PrimitiveParser<Source, Destination>();
			auto result = mapper.map<Vector<Destination>>(iterator, parser);
			addAll(result.beginEnumeration());
		}
	};
};

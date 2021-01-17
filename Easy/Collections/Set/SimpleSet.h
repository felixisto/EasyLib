#pragma once

#include "BaseSet.h"
#include "../Array/Vector.h"

namespace easy {
	/*
	 * A collection composed of unique primitive or pointer values.
	 * 
	 * Provides iterators to access its values instead of indexes.
	 * Iterators are not invalidated when inserting or deleting values.
	 * 
	 * @see BaseSet
	 */
	template <typename E>
	struct SimpleSet: Collection<E>, StringRepresentable, Hashable, Copyable<SimpleSet<E>>, SetEnumerable<E> {
	public:

		BaseSet<E> _set;

	public:
		SimpleSet() {

		}

		SimpleSet(const SimpleSet& other) : _set(other._set) {

		}

		SimpleSet(SetIterator<E> it) : _set(it) {

		}

		SimpleSet(const std::set<E>& set) : _set(set) {

		}

		virtual ~SimpleSet() {

		}

		// # Properties

		integer size() const {
			return _set.size();
		}

		// # Conversion

		std::set<E> asSTDSet() const {
			return _set.asSTDSet();
		}

		Vector<E> asList() const {
			Vector<E> result;

			auto end = _set.end();

			for (auto iterator = _set.begin(); iterator != end; iterator++) {
				result.add(*iterator);
			}

			return result;
		}

		std::vector<E> asSTDVector() const {
			return std::vector<E>(_set.rawData().cbegin(), _set.rawData().cend());
		}

		// # Operators

		bool operator==(const SimpleSet& other) const {
			return _set == other._set;
		}

		SimpleSet& operator=(const SimpleSet& other) {
			_set = other._set;
			return *this;
		}

		// # Query

		bool IsEmpty() const {
			return _set.IsEmpty();
		}

		bool contains(const E& element) const {
			return _set.contains(element);
		}

		const E& any() const {
			return _set.any();
		}

		// # Manipulation

		void insert(const E& element) {
			_set.insert(element);
		}

		void addAll(const Vector<E>& other) {
			for (int e = 0; e < other.size(); e++) {
				insert(other.get(e));
			}
		}

		void addAll(const E* buffer, integer length) {
			_set.addAll(buffer, length);
		}

		void addAll(const SimpleSet<E>& other) {
			_set.addAll(other._set);
		}

		// # StringRepresentable

		virtual CString toString() const {
			return StringFormatter().set(beginEnumeration());
		}

		// # Hashable

		virtual ubig hashValue() const {
			return _set.hashValue();
		}

		// # Copyable

		virtual SimpleSet copy() const {
			return *this;
		}

		// # Enumeration

		virtual SetIterator<E> beginEnumeration() const {
			return _set.beginEnumeration();
		}
	};
};

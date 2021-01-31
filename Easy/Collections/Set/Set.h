#pragma once

#include "BaseSet.h"

namespace easy {
	/*
	 * A collection composed of unique objects.
	 *
	 * Provides iterators to access its values instead of indexes.
	 * Iterators are not invalidated when inserting or deleting values.
	 * 
	 * @see BaseSet
	 */
	template <typename E>
	struct Set: Collection<E>, StringRepresentable, Hashable, Copyable<Set<E>>, SetEnumerable<E> {
	public:

		BaseSet<E> _set;

	public:
		Set() {

		}

		Set(const Set& other) : _set(other._set) {

		}

		Set(SetIterator<E> it) : _set(it) {

		}

		Set(const std::set<E>& set) : _set(set) {

		}

		virtual ~Set() {
			// The static asserts are here, so that Set can work with forward declarations
			static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
			static_assert(constraints::isLesserComparable<E>::value, "<E> must support lesser than comparison");
			static_assert(constraints::isTypeOf<StringRepresentable, E>::value, "<E> must implement StringRepresentable");
			static_assert(constraints::isTypeOf<Hashable, E>::value, "<E> must implement Hashable");
		}

		// # Properties

		integer size() const {
			return _set.size();
		}

		// # Conversion

		std::set<E> asSTDSet() const {
			return _set.asSTDSet();
		}

		List<E> asList() const {
			List<E> result;

			auto end = _set.rawData().end();

			for (auto iterator = _set.rawData().begin(); iterator != end; iterator++) {
				result.add(*iterator);
			}

			return result;
		}

		std::vector<E> asSTDVector() const {
			return std::vector<E>(_set.rawData().begin(), _set.rawData().end());
		}

		// # Operators

		bool operator==(const Set& other) const {
			return _set == other._set;
		}

		Set& operator=(const Set& other) {
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

		void addAll(const Set<E>& other) {
			_set.addAll(other._set);
		}

		void addAll(const E* buffer, integer length) {
			_set.addAll(buffer, length);
		}

		// # StringRepresentable

		virtual CString stringRepresentableOf(const E& element) const {
			return element.toString();
		}

		virtual CString toString() const {
			CString str = "(";

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

			str += ")";

			return str;
		}

		// # Hashable

		virtual ubig hashValue() const {
			return _set.hashValue();
		}

		// # Copyable

		virtual Set copy() const {
			return *this;
		}

		// # Enumeration

		virtual SetIterator<E> beginEnumeration() const {
			return _set.beginEnumeration();
		}

		// # Convert
		
		template <typename Source>
		void mapTo(const Set<Source>& other) {
			using Destination = E;

			auto mapper = Mapper<Source, Destination>();
			auto iterator = other.beginEnumeration();
			auto parser = SimpleParser<Source, Destination>();
			auto result = mapper.map<Set<Destination>>(iterator, mapper.simpleParser());
			addAll(result.beginEnumeration());
		}
	};
};

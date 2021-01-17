#pragma once

#include "../Array/List.h"
#include <set>

namespace easy {
	 /*
	  * A collection composed of unique values. Ordered.
	  * 
	  * Provides iterators to access its values instead of indexes.
	  * Iterators are not invalidated when inserting or deleting values.
	  * 
	  * Do not use this class directly, prefer to use the other collections such as Set and SimpleSet.
	  * 
	  * Performance:
      * Access: -
      * Insertion: O(log n)
      * Erase: O(log n)
      * Find: O(log n)
	  */
	template <typename E>
	struct BaseSet: Hashable, SetEnumerable<E> {
	private:

		std::set<E> _set;

	public:
		BaseSet() {

		}

		BaseSet(const BaseSet& other) : _set(other._set) {

		}

		BaseSet(const std::set<E>& set) : _set(set) {

		}

		BaseSet(SetIterator<E> it) {
			while (it.hasNext()) {
				_set.insert(it.get());
				it++;
			}
		}

		virtual ~BaseSet() {

		}

		// # Properties

		integer size() const {
			return _set.size();
		}

		const std::set<E>& rawData() const {
			return _set;
		}

		// # Operators

		bool operator==(const BaseSet& other) const {
			return _set == other._set;
		}

		BaseSet& operator=(const BaseSet& other) {
			_set = other._set;
			return *this;
		}

		// # Query

		bool IsEmpty() const {
			return _set.size() == 0;
		}

		bool contains(const E& element) const {
			return _set.find(element) != _set.end();
		}

		const E& any() const {
			return *_set.begin();
		}

		// # Manipulation

		void insert(const E& element) {
			_set.insert(element);
		}

		void addAll(const E* buffer, integer length) {
			const E* current = buffer;

			for (int e = 0; e < length; e++) {
				add(*current);

				current++;
			}
		}

		void addAll(const BaseSet<E>& other) {
			auto end = other._set.end();

			for (auto iterator = other._set.begin(); iterator != end; iterator++) {
				insert(*iterator);
			}
		}

		void addAll(SetIterator<E> iterator) {
			while (iterator.hasNext()) {
				add(iterator.get());

				iterator++;
			}
		}

		// # Hashable

		virtual ubig hashValue() const {
			MurmurHash64B hasher;

			ubig hash = 0;

			auto iterator = beginEnumeration();

			while (iterator.hasNext()) {
				hash = hasher.combine(hash, hasher.hash(*iterator));

				iterator++;
			}

			return hash;
		}

		// # Enumeration

		virtual SetIterator<E> beginEnumeration() const {
			return SetIterator<E>(_set.cbegin(), _set.cend());
		}
	};
};

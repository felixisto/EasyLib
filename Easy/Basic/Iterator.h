#pragma once

#include "Defines.h"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <stdarg.h>

namespace easy {
	template <typename IteratorType, typename ElementType>
	struct ConstIterator;

	template <typename IteratorType, typename ElementType>
	struct MutableIterator;

	/*
	 * A container/collection object that can be iterated over.
	 */
	template<typename CollectionType, typename ElementType>
	struct Enumerable {
		virtual ~Enumerable() {}

		virtual ConstIterator<typename CollectionType::const_iterator, ElementType> beginEnumeration() const = 0;
	};

	template<typename CollectionType, typename ElementType>
	struct MutableEnumerable : Enumerable<CollectionType, ElementType> {
		virtual ~MutableEnumerable() {}

		virtual MutableIterator<typename CollectionType::iterator, ElementType> beginMutableEnumeration() = 0;
	};

	template <typename E>
	using VectorEnumerable = MutableEnumerable<typename std::vector<E>, E>;

	template <typename E>
	using SetEnumerable = Enumerable<typename std::set<E>, E>;

	template <typename Key, typename E>
	using MapEnumerable = Enumerable<typename std::map<Key, E>, typename std::map<Key, E>::value_type>;

	/*
	 * A container/collection iterator. Read-only.
	 */
	struct ReadIterator {
		virtual ~ReadIterator() {}
	};

	/*
	 * A container/collection iterator. Read-write.
	 */
	struct ReadWriteIterator : ReadIterator {
		virtual ~ReadWriteIterator() {}
	};
};

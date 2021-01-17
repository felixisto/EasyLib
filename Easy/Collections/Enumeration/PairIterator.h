#pragma once

#include "ConstIterator.h"

namespace easy {
	template <typename Key, typename E>
	using PairConstIterator = ConstIterator<typename std::map<Key, E>::const_iterator, typename std::map<Key, E>::value_type>;

	template <typename Key, typename E>
	using MutablePairIterator = MutableIterator<typename std::map<Key, E>::iterator, typename std::map<Key, E>::value_type>;

	template <typename Key, typename E>
	using MapIterator = PairConstIterator<Key, E>;

	template <typename Key, typename E>
	using MutableMapIterator = MutablePairIterator<Key, E>;
};

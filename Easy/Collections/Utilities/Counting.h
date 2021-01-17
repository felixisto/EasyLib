#pragma once

#include "CountingNumbers.h"
#include "../Array/List.h"
#include "../Array/Vector.h"
#include "../Set/Set.h"
#include "../Set/SimpleSet.h"

namespace easy {
	struct Counting {
		template <typename E>
		static CountingNumbers<VectorIterator<E>, E> count(const Vector<E>& vector) {
			return CountingNumbers<VectorIterator<E>, E>(vector.beginEnumeration());
		}

		template <typename E>
		static CountingNumbers<ListIterator<E>, E> count(const List<E>& list) {
			return CountingNumbers<ListIterator<E>, E>(list.beginEnumeration());
		}

		template <typename E>
		static CountingNumbers<SetIterator<E>, E> count(const SimpleSet<E>& set) {
			return CountingNumbers<SetIterator<E>, E>(set.beginEnumeration());
		}

		template <typename E>
		static CountingNumbers<SetIterator<E>, E> count(const Set<E>& set) {
			return CountingNumbers<SetIterator<E>, E>(set.beginEnumeration());
		}
	};
};

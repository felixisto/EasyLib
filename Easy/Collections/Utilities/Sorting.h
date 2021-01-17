#pragma once

#include "SortingNumbers.h"
#include "../Array/List.h"
#include "../Array/Vector.h"
#include "../Set/Set.h"
#include "../Set/SimpleSet.h"

namespace easy {
	struct Sorting {
		template <typename E>
		static SortingNumbers<MutableVectorIterator<E>, E> sort(Vector<E>& vector) {
			return SortingNumbers<MutableVectorIterator<E>, E>(vector.beginMutableEnumeration());
		}

		template <typename E>
		static SortingNumbers<MutableListIterator<E>, E> sort(List<E>& list) {
			return SortingNumbers<MutableListIterator<E>, E>(list.beginMutableEnumeration());
		}
	};
};

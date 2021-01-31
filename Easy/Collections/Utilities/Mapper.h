#pragma once

#include "../../Basic/Parser.h"
#include "../Enumeration/PairIterator.h"

namespace easy {
	template <typename SourceEl, typename DestEl>
	struct Mapper {
		Mapper() {

		}

		// Maps list iterator's contents to the specified collection type.
		// Collection must have method add(element) defined.
		template <typename CollectionDest>
		CollectionDest map(ListIterator<SourceEl> iterator, const Parser<SourceEl, DestEl>& parser) const {
			CollectionDest result;

			while (iterator.hasNext()) {
				result.add(parser.parse(iterator.get()));

				iterator++;
			}

			return result;
		}

		// Maps list iterator's contents to the specified collection type.
		// Collection must have method insert(element) defined.
		template <typename CollectionDest>
		CollectionDest map(SetIterator<SourceEl> iterator, const Parser<SourceEl, DestEl>& parser) const {
			CollectionDest result;

			while (iterator.hasNext()) {
				result.insert(parser.parse(iterator.get()));

				iterator++;
			}

			return result;
		}

		// Maps list iterator's contents to the specified collection type.
		// Collection must operator [key] defined.
		template <typename CollectionDest, typename DictionaryKey>
		CollectionDest mapPair(MapIterator<DictionaryKey, SourceEl> iterator, const Parser<SourceEl, DestEl>& parser) const {
			CollectionDest result;

			while (iterator.hasNext()) {
				auto& entry = iterator.get();
				
				result[entry.first] = parser.parse(entry.second);

				iterator++;
			}

			return result;
		}
	};
};

#pragma once

#include "../../Basic/Parser.h"
#include "../Enumeration/PairIterator.h"

namespace easy {
	template <typename SourceEl, typename DestEl>
	struct Mapper {
		Mapper() {

		}

		template <typename CollectionDest>
		CollectionDest map(ListIterator<SourceEl> iterator, const Parser<SourceEl, DestEl>& parser) const {
			CollectionDest result;

			while (iterator.hasNext()) {
				result.add(parser.parse(iterator.get()));

				iterator++;
			}

			return result;
		}

		template <typename CollectionDest>
		CollectionDest map(SetIterator<SourceEl> iterator, const Parser<SourceEl, DestEl>& parser) const {
			CollectionDest result;

			while (iterator.hasNext()) {
				result.insert(parser.parse(iterator.get()));

				iterator++;
			}

			return result;
		}

		template <typename CollectionDest, typename DictionaryKey>
		CollectionDest mapPair(MapIterator<DictionaryKey, SourceEl> iterator, const Parser<SourceEl, DestEl>& parser) const {
			CollectionDest result;

			while (iterator.hasNext()) {
				auto& entry = iterator.get();

				result.insert(entry.first, parser.parse(entry.second));

				iterator++;
			}

			return result;
		}
	};
};

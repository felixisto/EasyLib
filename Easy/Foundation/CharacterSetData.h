#pragma once

#include "../Collections/Set/SimpleSet.h"

namespace easy {
	struct CharacterSetASCIIData {
	private:
		SimpleSet<character> _all;
		SimpleSet<character> _humanReadable;
		SimpleSet<character> _alphabetical;
		SimpleSet<character> _alphabeticalUpper;
		SimpleSet<character> _alphabeticalLower;
		SimpleSet<character> _numerical;
		SimpleSet<character> _alphanumerical;
		SimpleSet<character> _symbols;
		SimpleSet<character> _controls;
		SimpleSet<character> _spaceCharacters;

		CharacterSetASCIIData() {
			init();
		}

		void init() {
			allInit();
			humanReadableInit();
		}

		SimpleSet<character> allInit();
		SimpleSet<character> humanReadableInit();
		SimpleSet<character> alphabeticalInit();
		SimpleSet<character> numericalInit();
		SimpleSet<character> alphanumericalInit();
		SimpleSet<character> symbolsInit();
		SimpleSet<character> controlsInit();
		SimpleSet<character> spaceCharactersInit();

	public:
		static const CharacterSetASCIIData& standard() {
			static CharacterSetASCIIData set;
			return set;
		}

		static const SimpleSet<character>& all() {
			return standard()._all;
		}

		static const SimpleSet<character>& humanReadable() {
			return standard()._humanReadable;
		}

		static const SimpleSet<character>& alphabetical() {
			return standard()._alphabetical;
		}

		static const SimpleSet<character>& alphabeticalUpper() {
			return standard()._alphabeticalUpper;
		}

		static const SimpleSet<character>& alphabeticalLower() {
			return standard()._alphabeticalLower;
		}

		static const SimpleSet<character>& numerical() {
			return standard()._numerical;
		}

		static const SimpleSet<character>& alphanumerical() {
			return standard()._alphanumerical;
		}

		static const SimpleSet<character>& symbols() {
			return standard()._symbols;
		}

		static const SimpleSet<character>& controls() {
			return standard()._controls;
		}

		static const SimpleSet<character>& spaceCharacters() {
			return standard()._spaceCharacters;
		}

		static character spaceCharacter();

		static integer count() {
			return standard()._all.size();
		}
	};
};

#pragma once

#include "../Basic/Constraints.h"

namespace easy {
	template <typename Source, typename Destination>
	struct Parser {
		virtual Destination parse(const Source& source) const = 0;

		virtual ~Parser() {}
	};

	// Generic parser, uses copy constructor to convert one type to another.
	template <typename Source, typename Destination>
	struct SimpleParser: Parser<Source, Destination> {
		virtual Destination parse(const Source& source) const {
			return Destination(source);
		}

		virtual ~SimpleParser() {
			// The static asserts are here, so that SimpleParser can work with forward declarations
			static_assert(constraints::hasCopyConstructor<Destination>::value, "<Destination> must have copy constructor");
		}
	};

	// Generic parser, uses explicit cast to convert one primitive type to another.
	template <typename Source, typename Destination>
	struct PrimitiveParser : Parser<Source, Destination> {
		virtual Destination parse(const Source& source) const {
			return (Destination)source;
		}

		virtual ~PrimitiveParser() {}
	};
};

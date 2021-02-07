#pragma once

#include "../../Foundation/CString.h"

namespace easy {
	struct CurrencyImpl: Clonable<CurrencyImpl> {
		virtual ~CurrencyImpl() {}

		virtual ubig getType() const = 0;
		virtual CString getName() const = 0;
		virtual CString getAbbreviation() const = 0;

		virtual CurrencyImpl* clone() const = 0;
	};

	struct CurrencyGeneric : CurrencyImpl {
	private:

		ubig _type;
		CString _name;
		CString _abbreviation;

	public:

		static CurrencyGeneric* create() {
			return new CurrencyGeneric(0, "", "");
		}

		CurrencyGeneric(ubig type, const CString& name, const CString& abbreviation) : _type(type), _name(name), _abbreviation(abbreviation) {

		}

		virtual ~CurrencyGeneric() {}

		virtual ubig getType() const {
			return _type;
		}

		virtual CString getName() const {
			return _name;
		}

		virtual CString getAbbreviation() const {
			return _abbreviation;
		}

		virtual CurrencyImpl* clone() const {
			return new CurrencyGeneric(_type, _name, _abbreviation);
		}
	};
};

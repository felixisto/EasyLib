#pragma once

#include "../../Foundation/CString.h"
#include "../LanguageFamily.h"
#include "../LanguageWriting.h"

namespace easy {
	struct LanguageImpl : Clonable<LanguageImpl> {
		virtual ~LanguageImpl() {}

		virtual ubig getType() const = 0;
		virtual CString getName() const = 0;
		virtual CString getAbbreviation() const = 0;
		virtual const LanguageWriting& getWriting() const = 0;
		virtual const LanguageFamily& getFamily() const = 0;

		virtual LanguageImpl* clone() const = 0;
	};

	struct LanguageGeneric : LanguageImpl {
	private:

		ubig _type;
		CString _name;
		CString _abbreviation;
		LanguageWriting _writing;
		LanguageFamily _family;

	public:

		static LanguageGeneric* create() {
			static LanguageWriting genericWriting;
			static LanguageFamily genericFamily;

			return new LanguageGeneric(0, "", "", genericWriting, genericFamily);
		}

		LanguageGeneric(ubig type, const CString& name, const CString& abbreviation,
			const LanguageWriting& writing, const LanguageFamily& family) : _type(type), _name(name), _abbreviation(abbreviation), _writing(writing), _family(family) {

		}

		virtual ~LanguageGeneric() {}

		virtual ubig getType() const {
			return _type;
		}

		virtual CString getName() const {
			return _name;
		}

		virtual CString getAbbreviation() const {
			return _abbreviation;
		}

		virtual const LanguageWriting& getWriting() const {
			return _writing;
		}

		virtual const LanguageFamily& getFamily() const {
			return _family;
		}

		virtual LanguageImpl* clone() const {
			return new LanguageGeneric(_type, _name, _abbreviation, _writing, _family);
		}
	};
};

#pragma once

#include "../../Foundation/CString.h"
#include "../../Collections/Array/List.h"

namespace easy {
	struct LanguageWritingImpl : Clonable<LanguageWritingImpl> {
		virtual ~LanguageWritingImpl() {}

		virtual ubig getType() const = 0;
		virtual CString getName() const = 0;

		virtual LanguageWritingImpl* clone() const = 0;
	};

	struct LanguageWritingGeneric : LanguageWritingImpl {
	private:

		ubig _type;
		CString _name;

	public:

		static LanguageWritingGeneric* create() {
			return new LanguageWritingGeneric(0, "");
		}

		LanguageWritingGeneric(ubig type, const CString& name) : _type(type), _name(name) {

		}

		virtual ~LanguageWritingGeneric() {}

		virtual ubig getType() const {
			return _type;
		}

		virtual CString getName() const {
			return _name;
		}

		virtual LanguageWritingImpl* clone() const {
			return new LanguageWritingGeneric(_type, _name);
		}
	};
};

#pragma once

#include "../Foundation/CString.h"

namespace easy {
	struct LanguageFamily;

	struct LanguageFamilyParent {
		LanguageFamilyParent();
		LanguageFamilyParent(const LanguageFamilyParent& other);
		LanguageFamilyParent(const LanguageFamily& value);
		~LanguageFamilyParent();
		bool exists() const;
		const LanguageFamily& get() const;
	private:
		const LanguageFamily* _value;
	};

	struct LanguageFamily: StringRepresentable, Hashable {
		ubig type = 0;
		CString name;

		LanguageFamily() {

		}

		LanguageFamily(const LanguageFamily& other) : type(other.type), name(other.name) {

		}

		LanguageFamily(ubig type, const CString& name) : type(type), name(name) {

		}

		bool operator==(const LanguageFamily& other) const {
			return type == other.type && name == other.name;
		}

		LanguageFamily& operator=(const LanguageFamily& other) {
			type = other.type;
			name = other.name;
			return *this;
		}

		CString toString() const {
			return name;
		}

		ubig hashValue() const {
			return type;
		}
	};
};
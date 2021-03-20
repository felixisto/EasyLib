
#include "../LanguageFamily.h"

using namespace easy;

LanguageFamilyParent::LanguageFamilyParent() : _value(nullptr) {

}

LanguageFamilyParent::LanguageFamilyParent(const LanguageFamilyParent& other) : _value(nullptr) {
	if (other.exists()) {
		_value = new LanguageFamily(*other._value);
	}
}

LanguageFamilyParent::LanguageFamilyParent(const LanguageFamily& value) : _value(new LanguageFamily(value)) {

}

LanguageFamilyParent::~LanguageFamilyParent() {
	delete _value;
}

bool LanguageFamilyParent::exists() const {
	return _value != nullptr;
}

const LanguageFamily& LanguageFamilyParent::get() const {
	return *_value;
}


#include "../Language.h"

using namespace easy;

Language::Language() : _impl(LanguageGeneric::create()) {

}

Language::Language(const Language& other) : _impl(other._impl->clone()) {

}

Language::Language(const LanguageImpl& impl) : _impl(impl.clone()) {

}

Language::~Language() {
	delete _impl;
}

bool Language::operator==(const Language& other) const {
	return _impl->getType() == other._impl->getType();
}

Language& Language::operator=(const Language& other) {
	delete _impl;
	_impl = other._impl->clone();
	return *this;
}

CString Language::toString() const {
	return getName();
}

ubig Language::hashValue() const {
	return getType();
}

ubig Language::getType() const {
	return _impl->getType();
}

CString Language::getName() const {
	return _impl->getName();
}

CString Language::getAbbreviation() const {
	return _impl->getAbbreviation();
}

const LanguageWriting& Language::getWriting() const {
	return _impl->getWriting();
}

const LanguageFamily& Language::getFamily() const {
	return _impl->getFamily();
}

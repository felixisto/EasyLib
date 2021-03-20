
#include "../Currency.h"

using namespace easy;

Currency::Currency() : _impl(CurrencyGeneric::create()) {

}

Currency::Currency(const Currency& other) : _impl(other._impl->clone()) {

}

Currency::Currency(const CurrencyImpl& impl) : _impl(impl.clone()) {

}

Currency::~Currency() {
	delete _impl;
}

bool Currency::operator==(const Currency& other) const {
	return _impl->getType() == other._impl->getType();
}

Currency& Currency::operator=(const Currency& other) {
	delete _impl;
	_impl = other._impl->clone();
	return *this;
}

CString Currency::toString() const {
	return getName();
}

ubig Currency::hashValue() const {
	return getType();
}

ubig Currency::getType() const {
	return _impl->getType();
}

CString Currency::getName() const {
	return _impl->getName();
}

CString Currency::getAbbreviation() const {
	return _impl->getAbbreviation();
}

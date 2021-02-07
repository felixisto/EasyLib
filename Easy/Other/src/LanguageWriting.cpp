
#include "../LanguageWriting.h"

using namespace easy;

LanguageWriting::LanguageWriting() : _impl(LanguageWritingGeneric::create()) {

}

LanguageWriting::LanguageWriting(const LanguageWriting& other) : _impl(other._impl->clone()) {

}

LanguageWriting::LanguageWriting(const LanguageWritingImpl& impl) : _impl(impl.clone()) {

}

LanguageWriting::~LanguageWriting() {
	delete _impl;
}

bool LanguageWriting::operator==(const LanguageWriting& other) const {
	return _impl->getType() == other.getType();
}

LanguageWriting& LanguageWriting::operator=(const LanguageWriting& other) {
	delete _impl;
	_impl = other._impl->clone();
	return *this;
}

ubig LanguageWriting::getType() const {
	return _impl->getType();
}

CString LanguageWriting::getName() const {
	return _impl->getName();
}

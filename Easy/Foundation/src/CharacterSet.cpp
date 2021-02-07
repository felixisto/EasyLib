
#include "../CharacterSet.h"
#include "../CharacterSetData.h"

using namespace easy;

// # CharacterSet



// # CharacterSetASCII

CharacterSetASCII::CharacterSetASCII() : _name("ASCII") {

}

CharacterSetASCII::CharacterSetASCII(const CharacterSetASCII& other) : _name(other._name) {

}

CharacterSetASCII::CharacterSetASCII(CString name, SetIterator<character> iterator) : _name(name) {

}

CharacterSetASCII::~CharacterSetASCII() {

}

const CharacterSetASCII& CharacterSetASCII::standard() {
	static CharacterSetASCII set;
	return set;
}

// # Properties

CString CharacterSetASCII::name() const {
	return _name;
}

integer CharacterSetASCII::count() const {
	return CharacterSetASCIIData::count();
}

SetIterator<character> CharacterSetASCII::enumerateAll() const {
	return CharacterSetASCIIData::all().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateHumanReadable() const {
	return CharacterSetASCIIData::humanReadable().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateAlphabetical() const {
	return CharacterSetASCIIData::alphabetical().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateAlphabeticalUppercase() const {
	return CharacterSetASCIIData::alphabeticalUpper().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateAlphabeticalLowercase() const {
	return CharacterSetASCIIData::alphabeticalLower().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateNumerical() const {
	return CharacterSetASCIIData::numerical().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateAlphanumerical() const {
	return CharacterSetASCIIData::alphanumerical().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateSymbols() const {
	return CharacterSetASCIIData::symbols().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateControls() const {
	return CharacterSetASCIIData::controls().beginEnumeration();
}

SetIterator<character> CharacterSetASCII::enumerateSpaceCharacters() const {
	return CharacterSetASCIIData::spaceCharacters().beginEnumeration();
}

character CharacterSetASCII::spaceCharacter() const {
	return CharacterSetASCIIData::spaceCharacter();
}

// # Copyable

CharacterSetASCII CharacterSetASCII::copy() const {
	return *this;
}

// # Enumeration

SetIterator<character> CharacterSetASCII::beginEnumeration() const {
	return CharacterSetASCIIData::all().beginEnumeration();
}

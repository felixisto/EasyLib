
#include "CharacterSetData.h"

using namespace easy;

SimpleSet<character> CharacterSetASCIIData::allInit() {
	SimpleSet<character> set;
	set.addAll(alphanumericalInit());
	set.addAll(symbolsInit());
	set.addAll(controlsInit());
	set.addAll(spaceCharactersInit());
	_all = set;
	return set;
}

SimpleSet<character> CharacterSetASCIIData::humanReadableInit() {
	SimpleSet<character> set;
	set.addAll(alphanumericalInit());
	set.addAll(symbolsInit());
	_humanReadable = set;
	return set;
}

SimpleSet<character> CharacterSetASCIIData::alphabeticalInit() {
	SimpleSet<character> upper;

	for (int e = 65; e <= 90; e++) {
		upper.insert(character(e));
	}

	_alphabeticalUpper = upper;

	SimpleSet<character> lower;

	for (int e = 97; e <= 122; e++) {
		lower.insert(character(e));
	}

	_alphabeticalLower = lower;

	SimpleSet<character> set;
	set.addAll(upper);
	set.addAll(lower);
	_alphabetical = set;
	return set;
}

SimpleSet<character> CharacterSetASCIIData::numericalInit() {
	SimpleSet<character> set;
	for (int e = 48; e <= 57; e++) {
		set.insert(character(e));
	}
	_numerical = set;
	return set;
}

SimpleSet<character> CharacterSetASCIIData::alphanumericalInit() {
	SimpleSet<character> set;
	set.addAll(alphabeticalInit());
	set.addAll(numericalInit());
	_alphanumerical = set;
	return set;
}

SimpleSet<character> CharacterSetASCIIData::symbolsInit() {
	SimpleSet<character> set;
	for (int e = 33; e <= 47; e++) {
		set.insert(character(e));
	}
	for (int e = 91; e <= 96; e++) {
		set.insert(character(e));
	}
	for (int e = 123; e <= 126; e++) {
		set.insert(character(e));
	}
	_symbols = set;
	return set;
}

SimpleSet<character> CharacterSetASCIIData::controlsInit() {
	SimpleSet<character> set;
	for (int e = 1; e <= 31; e++) {
		set.insert(character(e));
	}
	set.insert(character(127));
	_controls = set;
	return set;
}

SimpleSet<character> CharacterSetASCIIData::spaceCharactersInit() {
	SimpleSet<character> set;
	set.insert(spaceCharacter());
	return set;
}

character CharacterSetASCIIData::spaceCharacter() {
	return character(32);
}

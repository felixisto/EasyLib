
#include "../LanguageFamilies.h"

using namespace easy;

List<LanguageFamily> LanguageFamilies::CREATE_ALL() {
	List<LanguageFamily> all;
	all.addAll(CREATE_PRIMARY());
	all.addAll(CREATE_SUB());
	return all;
}

List<LanguageFamily> LanguageFamilies::CREATE_PRIMARY() {
	List<LanguageFamily> all;
	all.add(LanguageFamily(all.size(), "Indo-European"));
	return all;
}

List<LanguageFamily> LanguageFamilies::CREATE_SUB() {
	List<LanguageFamily> all;
	all.add(LanguageFamily(all.size(), "Germanic"));
	all.add(LanguageFamily(all.size(), "West Germanic"));
	all.add(LanguageFamily(all.size(), "North Sea Germanic"));
	all.add(LanguageFamily(all.size(), "Anglo-Frisian"));
	all.add(LanguageFamily(all.size(), "Anglic"));
	return all;
}

List<LanguageFamily> LanguageFamilies::ALL() {
	static List<LanguageFamily> all = CREATE_ALL();
	return all;
}

// # Primary

LanguageFamily LanguageFamilies::INDO_EUROPEAN() {
	return CREATE_PRIMARY().get(0);
}

// # Sub

LanguageFamily LanguageFamilies::GERMANIC() {
	return CREATE_SUB().get(0);
}

LanguageFamily LanguageFamilies::WEST_GERMANIC() {
	return CREATE_SUB().get(1);
}

LanguageFamily LanguageFamilies::NORTH_SEA_GERMANIC() {
	return CREATE_SUB().get(2);
}

LanguageFamily LanguageFamilies::ANGLO_FRISIAN() {
	return CREATE_SUB().get(3);
}

LanguageFamily LanguageFamilies::ANGLIC() {
	return CREATE_SUB().get(4);
}

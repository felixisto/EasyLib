
#include "../Currencies.h"

using namespace easy;

struct ModernCurrency: CurrencyGeneric, CurrencyPaper, CurrencyCoin {
	ModernCurrency(ubig type, const CString& name, const CString& abbreviation) : CurrencyGeneric(type, name, abbreviation) {

	}

	ModernCurrency(const ModernCurrency& other) : CurrencyGeneric(other) {

	}

	virtual CurrencyImpl* clone() const {
		return new ModernCurrency(*this);
	}
};

List<Currency> Currencies::CREATE_ALL() {
	List<Currency> all;
	all.add(Currency(ModernCurrency(all.size(), "United States dollar", "USD")));
	all.add(Currency(ModernCurrency(all.size(), "Euro", "EUR")));
	all.add(Currency(ModernCurrency(all.size(), "Pound sterling", "GBP")));
	all.add(Currency(ModernCurrency(all.size(), "Japanese yen", "JPY")));
	all.add(Currency(ModernCurrency(all.size(), "Australian dollar", "AUD")));
	all.add(Currency(ModernCurrency(all.size(), "Canadian dollar", "CAD")));
	all.add(Currency(ModernCurrency(all.size(), "Swiss franc", "CHF")));
	all.add(Currency(ModernCurrency(all.size(), "Renminbi", "CNY")));
	all.add(Currency(ModernCurrency(all.size(), "Hong Kong dollar", "HKD")));
	all.add(Currency(ModernCurrency(all.size(), "New Zealand dollar", "NZD")));
	all.add(Currency(ModernCurrency(all.size(), "Swedish krona", "SEK")));
	all.add(Currency(ModernCurrency(all.size(), "South Korean won", "KRW")));
	all.add(Currency(ModernCurrency(all.size(), "Russian ruble", "INR")));
	all.add(Currency(ModernCurrency(all.size(), "Indian rupee", "RUB")));
	return all;
}

List<Currency> Currencies::ALL() {
	static List<Currency> all = CREATE_ALL();
	return all;
}

Currency Currencies::USD() {
	return CREATE_ALL().get(0);
}

Currency Currencies::EURO() {
	return CREATE_ALL().get(1);
}

Currency Currencies::POUND_STERLING() {
	return CREATE_ALL().get(2);
}

Currency Currencies::JAP_YEN() {
	return CREATE_ALL().get(3);
}

Currency Currencies::AUSTR_DOLLAR() {
	return CREATE_ALL().get(4);
}

Currency Currencies::CANAD_DOLLAR() {
	return CREATE_ALL().get(5);
}

Currency Currencies::SWISS_FRANC() {
	return CREATE_ALL().get(6);
}

Currency Currencies::RENMINBI() {
	return CREATE_ALL().get(7);
}

Currency Currencies::HONG_KONG_DOLLAR() {
	return CREATE_ALL().get(8);
}

Currency Currencies::NEWZ_DOLLAR() {
	return CREATE_ALL().get(9);
}

Currency Currencies::SWEDISH_KRONA() {
	return CREATE_ALL().get(10);
}

Currency Currencies::SOUTHK_WON() {
	return CREATE_ALL().get(11);
}

Currency Currencies::RUSSIAN_RUBLE() {
	return CREATE_ALL().get(12);
}

Currency Currencies::INDIAN_RUPEE() {
	return CREATE_ALL().get(13);
}


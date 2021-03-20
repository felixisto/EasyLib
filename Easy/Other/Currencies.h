#pragma once

#include "Currency.h"
#include "../Collections/Array/List.h"

namespace easy {
	struct Currencies {
		static List<Currency> ALL();

		static Currency USD();
		static Currency EURO();
		static Currency POUND_STERLING();
		static Currency JAP_YEN();
		static Currency AUSTR_DOLLAR();
		static Currency CANAD_DOLLAR();
		static Currency SWISS_FRANC();
		static Currency RENMINBI();
		static Currency HONG_KONG_DOLLAR();
		static Currency NEWZ_DOLLAR();
		static Currency SWEDISH_KRONA();
		static Currency SOUTHK_WON();
		static Currency RUSSIAN_RUBLE();
		static Currency INDIAN_RUPEE();

	private:
		static List<Currency> CREATE_ALL();
	};
};

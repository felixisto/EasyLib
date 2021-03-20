#pragma once

#include "Impl/CurrencyImpl.h"

namespace easy {
	struct Currency: StringRepresentable, Hashable {
	private:
		CurrencyImpl* _impl;
	public:

		Currency();
		Currency(const Currency& other);
		Currency(const CurrencyImpl& impl);

		virtual ~Currency();

		bool operator==(const Currency& other) const;
		Currency& operator=(const Currency& other);

		virtual CString toString() const;
		virtual ubig hashValue() const const;

		virtual ubig getType() const;
		virtual CString getName() const;
		virtual CString getAbbreviation() const;

		template <typename T>
		const T* as() const {
			if (dynamic_cast<T*>(_impl)) {
				return (T*)_impl;
			}

			return nullptr;
		}

		template <typename T>
		bool is() const {
			return as<T>() != nullptr;
		}
	};

	struct CurrencyCoin {
		virtual ~CurrencyCoin() {}
	};

	struct CurrencyPaper {
		virtual ~CurrencyPaper() {}
	};

	struct CurrencyDigital {
		virtual ~CurrencyDigital() {}
	};
};

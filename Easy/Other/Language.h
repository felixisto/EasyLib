#pragma once

#include "Impl/LanguageImpl.h"

namespace easy {
	struct Language: StringRepresentable, Hashable {
	private:
		LanguageImpl* _impl;

	public:

		Language();
		Language(const Language& other);
		Language(const LanguageImpl& impl);

		virtual ~Language();

		bool operator==(const Language& other) const;
		Language& operator=(const Language& other);

		virtual CString toString() const;
		virtual ubig hashValue() const const;

		virtual ubig getType() const;
		virtual CString getName() const;
		virtual CString getAbbreviation() const;
		virtual const LanguageWriting& getWriting() const;
		virtual const LanguageFamily& getFamily() const;

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

	struct LanguageDialects {
		virtual int getDialectsCount() const = 0;
		virtual const Language& getDialectAt(int index) const = 0;
	};
};
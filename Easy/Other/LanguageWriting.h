#pragma once

#include "Impl/LanguageWritingImpl.h"

namespace easy {
	struct LanguageWriting {
	private:
		LanguageWritingImpl* _impl;
	public:
		LanguageWriting();
		LanguageWriting(const LanguageWriting& other);
		LanguageWriting(const LanguageWritingImpl& impl);

		virtual ~LanguageWriting();

		bool operator==(const LanguageWriting& other) const;
		LanguageWriting& operator=(const LanguageWriting& other);

		virtual ubig getType() const;
		virtual CString getName() const;

		template <typename T>
		const T* as() const {
			if (dynamic_cast<T*>(this)) {
				return (T*)this;
			}

			return nullptr;
		}

		template <typename T>
		bool is() const {
			return as<T>() != nullptr;
		}
	};

	struct LanguageWritingDirection {
		bool isLeftToRight = false;
	};

	struct LanguageWritingAlphabet {
		virtual ~LanguageWritingAlphabet() {}

		virtual LanguageWritingDirection getDirection() const = 0;
	};

	struct LanguageWritingLogographic {
		virtual ~LanguageWritingLogographic() {}

		virtual LanguageWritingDirection getDirection() const = 0;
	};

	struct LanguageWritingAbjad {
		virtual ~LanguageWritingAbjad() {}

		virtual LanguageWritingDirection getDirection() const = 0;
	};

	struct LanguageWritingAbugida {
		virtual ~LanguageWritingAbugida() {}

		virtual LanguageWritingDirection getDirection() const = 0;
	};

	struct LanguageWritingSyllabary {
		virtual ~LanguageWritingSyllabary() {}

		virtual LanguageWritingDirection getDirection() const = 0;
	};
};
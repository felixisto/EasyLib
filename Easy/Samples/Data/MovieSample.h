#pragma once

#include "../../Foundation/CString.h"
#include "../../Foundation/Date.h"
#include "../../Other/Currency.h"
#include "../../Other/Language.h"

namespace easy {
	namespace samples {
		struct MovieReview {
			CString author;
			Date releaseDate;
			CString reviewTitle;
			CString reviewBody;
			byte ratingOutOf10;

			Language language;
		};

		struct MovieBoxOffice {
			Currency currency;

			ubig domestic;
			ubig international;

			ubig getWorldwide() const {
				return domestic + international;
			}
		};

		struct Movie {
			CString name;
			CString shortDescription;
			Date releaseDate;
			CString longDescription;

			Language language;
		};
	};
};
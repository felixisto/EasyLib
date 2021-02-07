
#include "../Date.h"

using namespace easy;

CString Date::toString() const {
	return DateFormatter(*this).toString();
}

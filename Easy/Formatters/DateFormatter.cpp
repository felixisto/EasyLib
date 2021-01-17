
#include "DateFormatter.h"

using namespace easy;

// # Premade

CString DateFormatter::timestampFormat() {
	return CString("%H:%M:%S.{ms}");
}

// # StringRepresentable

CString DateFormatter::toString() const {
	auto time = TimeReference::fromSecondsSinceCurrentEpoch(date.inSeconds());
	return time.toString(format.buffer());
}

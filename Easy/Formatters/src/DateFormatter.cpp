
#include "../DateFormatter.h"

using namespace easy;

// # Premade

CString DateFormatter::standardFormat() {
	return CString("%Y-%m-%d %H:%M:%S");
}

CString DateFormatter::shortTimestampFormat() {
	return CString("%H:%M:%S.{ms}");
}

CString DateFormatter::timestampFileFriendlyFormat() {
	return CString("%Y_%m_%d_%H_%M_%S");
}

// # StringRepresentable

CString DateFormatter::toString() const {
	auto time = TimeReference::fromSecondsSinceCurrentEpoch(date.inSeconds());
	return time.toString(format.buffer());
}

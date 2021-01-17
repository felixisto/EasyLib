
#include "TimeUnit.h"

using namespace easy;
using namespace time;

const TimeUnit& TimeUnit::PLANCK_TIME() {
	static TimeUnit t(1, "planck time", "planck time", "tp");
	return t;
}

const TimeUnit& TimeUnit::YOCTOSECOND() {
	static TimeUnit t(2, "yoctosecond", "yoctosecond", "ys");
	return t;
}

const TimeUnit& TimeUnit::JIFFY() {
	static TimeUnit t(3, "jiffy", "jiffy", "jiffy");
	return t;
}

const TimeUnit& TimeUnit::ZEPTOSECOND() {
	static TimeUnit t(4, "zeptosecond", "zeptosecond", "zs");
	return t;
}

const TimeUnit& TimeUnit::ATTOSECOND() {
	static TimeUnit t(5, "attosecond", "attosecond", "as");
	return t;
}

const TimeUnit& TimeUnit::FEMTOSECOND() {
	static TimeUnit t(6, "femtosecond", "femtosecond", "fs");
	return t;
}

const TimeUnit& TimeUnit::SVEDBERG() {
	static TimeUnit t(7, "svedberg", "svedberg", "svedberg");
	return t;
}

const TimeUnit& TimeUnit::PICOSECOND() {
	static TimeUnit t(8, "picosecond", "pico", "ps");
	return t;
}

const TimeUnit& TimeUnit::NANOSECOND() {
	static TimeUnit t(9, "nanosecond", "nano", "ns");
	return t;
}

const TimeUnit& TimeUnit::MICROSECOND() {
	static TimeUnit t(10, "microsecond", "microsec", "us");
	return t;
}

const TimeUnit& TimeUnit::MILLISECOND() {
	static TimeUnit t(11, "millisecond", "ms", "ms");
	return t;
}

const TimeUnit& TimeUnit::CENTISECOND() {
	static TimeUnit t(12, "centisecond", "cs", "cs");
	return t;
}

const TimeUnit& TimeUnit::DECISECOND() {
	static TimeUnit t(13, "decisecond", "ds", "ds");
	return t;
}

const TimeUnit& TimeUnit::SECOND() {
	static TimeUnit t(14, "second", "sec", "s");
	return t;
}

const TimeUnit& TimeUnit::MINUTE() {
	static TimeUnit t(15, "minute", "min", "");
	return t;
}

const TimeUnit& TimeUnit::HECTOSECOND() {
	static TimeUnit t(16, "hetosecond", "hsec", "");
	return t;
}

const TimeUnit& TimeUnit::KE() {
	static TimeUnit t(17, "ke", "ke", "");
	return t;
}

const TimeUnit& TimeUnit::KILOSECOND() {
	static TimeUnit t(18, "kilosecond", "ksec", "");
	return t;
}

const TimeUnit& TimeUnit::HOUR() {
	static TimeUnit t(19, "hour", "hr", "");
	return t;
}

const TimeUnit& TimeUnit::DAY() {
	static TimeUnit t(20, "day", "day", "");
	return t;
}

const TimeUnit& TimeUnit::WEEK() {
	static TimeUnit t(21, "week", "week", "");
	return t;
}

const TimeUnit& TimeUnit::MEGASECOND() {
	static TimeUnit t(22, "megasecond", "msec", "");
	return t;
}

const TimeUnit& TimeUnit::FORTNIGHT() {
	static TimeUnit t(23, "fortnight", "fortnight", "");
	return t;
}

const TimeUnit& TimeUnit::MONTH28() {
	static TimeUnit t(24, "month", "month", "");
	return t;
}

const TimeUnit& TimeUnit::MONTH29() {
	static TimeUnit t(25, "month", "month", "");
	return t;
}

const TimeUnit& TimeUnit::MONTH30() {
	static TimeUnit t(26, "month", "month", "");
	return t;
}

const TimeUnit& TimeUnit::MONTH31() {
	static TimeUnit t(27, "month", "month", "");
	return t;
}

const TimeUnit& TimeUnit::SEMESTER() {
	static TimeUnit t(28, "semester", "semester", "");
	return t;
}

const TimeUnit& TimeUnit::COMMON_YEAR() {
	static TimeUnit t(29, "common year", "year", "");
	return t;
}

const TimeUnit& TimeUnit::LEAP_YEAR() {
	static TimeUnit t(30, "leap year", "year", "");
	return t;
}

const TimeUnit& TimeUnit::BIENNIUM() {
	static TimeUnit t(31, "biennium", "biennium", "");
	return t;
}

const TimeUnit& TimeUnit::TRIENNIUM() {
	static TimeUnit t(32, "triennium", "triennium", "");
	return t;
}

const TimeUnit& TimeUnit::QUADRENNIUM() {
	static TimeUnit t(33, "quadrennium", "quadrennium", "");
	return t;
}

const TimeUnit& TimeUnit::OLYMPIAD() {
	static TimeUnit t(34, "olympiad", "olympiad", "");
	return t;
}

const TimeUnit& TimeUnit::LUSTRUM() {
	static TimeUnit t(35, "lustrum", "lustrum", "");
	return t;
}

const TimeUnit& TimeUnit::DECADE() {
	static TimeUnit t(36, "decade", "decade", "");
	return t;
}

const TimeUnit& TimeUnit::GIGASECOND() {
	static TimeUnit t(37, "gigasecond", "gigasecond", "");
	return t;
}

const TimeUnit& TimeUnit::CENTURY() {
	static TimeUnit t(38, "century", "century", "");
	return t;
}

const TimeUnit& TimeUnit::MILLENNIUM() {
	static TimeUnit t(39, "millennium", "millennium", "");
	return t;
}

const TimeUnit& TimeUnit::TERASECOND() {
	static TimeUnit t(40, "terasecond", "terasecond", "");
	return t;
}

const TimeUnit& TimeUnit::MEGAYEAR() {
	static TimeUnit t(41, "megayear", "megayear", "");
	return t;
}

const TimeUnit& TimeUnit::PETASECOND() {
	static TimeUnit t(42, "petasecond", "petasecond", "");
	return t;
}

const TimeUnit& TimeUnit::GALACTIC_YEAR() {
	static TimeUnit t(43, "galactic year", "gyear", "");
	return t;
}
const TimeUnit& TimeUnit::EXASECOND() {
	static TimeUnit t(44, "exasecond", "exasecond", "");
	return t;
}

std::vector<TimeUnit> TimeUnit::BUILD_ALL_VALUES() {
	std::vector<TimeUnit> all;
	all.push_back(PLANCK_TIME());
	all.push_back(YOCTOSECOND());
	all.push_back(JIFFY());
	all.push_back(ZEPTOSECOND());
	all.push_back(ATTOSECOND());
	all.push_back(FEMTOSECOND());
	all.push_back(SVEDBERG());
	all.push_back(PICOSECOND());
	all.push_back(NANOSECOND());
	all.push_back(MICROSECOND());
	all.push_back(MILLISECOND());
	all.push_back(SECOND());
	all.push_back(MINUTE());
	all.push_back(HECTOSECOND());
	all.push_back(KE());
	all.push_back(KILOSECOND());
	all.push_back(HOUR());
	all.push_back(DAY());
	all.push_back(WEEK());
	all.push_back(MEGASECOND());
	all.push_back(FORTNIGHT());
	all.push_back(MONTH28());
	all.push_back(MONTH29());
	all.push_back(MONTH30());
	all.push_back(MONTH31());
	all.push_back(SEMESTER());
	all.push_back(COMMON_YEAR());
	all.push_back(LEAP_YEAR());
	all.push_back(BIENNIUM());
	all.push_back(TRIENNIUM());
	all.push_back(QUADRENNIUM());
	all.push_back(OLYMPIAD());
	all.push_back(LUSTRUM());
	all.push_back(DECADE());
	all.push_back(GIGASECOND());
	all.push_back(CENTURY());
	all.push_back(MILLENNIUM());
	all.push_back(TERASECOND());
	all.push_back(MEGAYEAR());
	all.push_back(PETASECOND());
	all.push_back(GALACTIC_YEAR());
	all.push_back(EXASECOND());
	return all;
}

const std::vector<TimeUnit>& TimeUnit::ALL_VALUES() {
	static const std::vector<TimeUnit> all(BUILD_ALL_VALUES());
	return all;
}

TimeUnit::TimeUnit(int value, const std::string& name, const std::string& shortName, const std::string& symbol) : value(value), name(name), shortName(shortName), symbol(symbol) {

}

TimeUnit::TimeUnit(const TimeUnit& other) : value(other.value), name(other.name), shortName(other.shortName), symbol(other.symbol) {

}

bool TimeUnit::operator==(const TimeUnit& other) const {
	return value == other.value;
}

bool TimeUnit::operator!=(const TimeUnit& other) const {
	return value != other.value;
}

bool TimeUnit::operator>(const TimeUnit& other) const {
	return value > other.value;
}

bool TimeUnit::operator>=(const TimeUnit& other) const {
	return value >= other.value;
}

bool TimeUnit::operator<(const TimeUnit& other) const {
	return value < other.value;
}

bool TimeUnit::operator<=(const TimeUnit& other) const {
	return value <= other.value;
}

std::string TimeUnit::toString() const {
	return name;
}

ubig TimeUnit::hashValue() const {
	return value;
}

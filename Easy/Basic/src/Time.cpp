#pragma once

#include "../Time.h"
#include "../TimeUnit.h"
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace easy;

// # TimeValue

TimeValue TimeValue::zero() {
    return TimeValue(0);
}

TimeValue TimeValue::fromMilliseconds(ubig ms) {
    return TimeValue(time::convert_real::convertMillisecondsToSeconds(ms));
}

TimeValue TimeValue::fromSeconds(real seconds) {
    return TimeValue(seconds);
}

TimeValue TimeValue::fromMinutes(real minutes) {
    return TimeValue(time::convert_real::convertMinutesToSeconds(minutes));
}

TimeValue TimeValue::fromHours(real hours) {
    return TimeValue(time::convert_real::convertHoursToSeconds(hours));
}

TimeValue TimeValue::fromDays(real days) {
    return TimeValue(time::convert_real::convertDaysToSeconds(days));
}

TimeValue TimeValue::fromCommonYears(real years) {
    return TimeValue(time::convert_real::convertCommonYearsToSeconds(years));
}

TimeValue::TimeValue(real seconds) : _seconds(seconds) {

}

TimeValue::TimeValue(const TimeValue& other) : _seconds(other._seconds) {

}

bool TimeValue::operator==(const TimeValue& other) const {
    return _seconds == other._seconds;
}

bool TimeValue::operator<(const TimeValue& other) const {
    return _seconds < other._seconds;
}

bool TimeValue::operator<=(const TimeValue& other) const {
    return _seconds <= other._seconds;
}

bool TimeValue::operator>(const TimeValue& other) const {
    return _seconds > other._seconds;
}

bool TimeValue::operator>=(const TimeValue& other) const {
    return _seconds >= other._seconds;
}

TimeValue& TimeValue::operator=(const TimeValue& other) {
    _seconds = other._seconds;
    return *this;
}

TimeValue TimeValue::operator+(const TimeValue& other) const {
    return _seconds + other._seconds;
}

TimeValue TimeValue::operator-(const TimeValue& other) const {
    return _seconds - other._seconds;
}

TimeValue TimeValue::operator*(const TimeValue& other) const {
    return _seconds * other._seconds;
}

TimeValue TimeValue::operator/(const TimeValue& other) const {
    return _seconds / other._seconds;
}

TimeValue& TimeValue::operator+=(const TimeValue& other) {
    _seconds += other._seconds;
    return *this;
}

TimeValue& TimeValue::operator-=(const TimeValue& other) {
    _seconds -= other._seconds;
    return *this;
}

TimeValue& TimeValue::operator++() {
    // Prefix ++
    _seconds++;
    return *this;
}

TimeValue TimeValue::operator++(int postFix) {
    // Postfix ++
    auto old = *this;
    _seconds++;
    return old;
}

ubig TimeValue::inMilliseconds() const {
    return time::convert_real::convertSecondsToMilliseconds(_seconds);
}

real TimeValue::inSeconds() const {
    return _seconds;
}

real TimeValue::inMinutes() const {
    return time::convert_real::convertSecondsToMinutes(_seconds);
}

real TimeValue::inHours() const {
    return time::convert_real::convertSecondsToHours(_seconds);
}

real TimeValue::inDays() const {
    return time::convert_real::convertSecondsToDays(_seconds);
}

real TimeValue::inCommonYears() const {
    return time::convert_real::convertSecondsToCommonYears(_seconds);
}

real TimeValue::inCenturies() const {
    return time::convert_real::convertSecondsToCenturies(_seconds);
}

// # TimeReference

real TimeReference::timeSinceCurrentEpoch() {
    using namespace std::chrono;

    auto now = system_clock::now();

    milliseconds chronoMS = duration_cast<milliseconds>(now.time_since_epoch());

    ubig ms = chronoMS.count();
    real seconds = (real)ms;
    return seconds / 1000.0;
}

TimeReference TimeReference::systemTime() {
    return TimeReference(timeSinceCurrentEpoch());
}

TimeReference TimeReference::fromSecondsSinceCurrentEpoch(real seconds) {
    return TimeReference(seconds);
}

TimeReference TimeReference::fromTimeT(time_t timeValue) {
    return TimeReference(timeValue);
}

TimeReference::TimeReference() : _seconds(timeSinceCurrentEpoch()) {

}

TimeReference::TimeReference(const TimeReference& other) : _seconds(other._seconds) {

}

TimeReference::TimeReference(real seconds) : _seconds(seconds) {

}

bool TimeReference::operator==(const TimeReference& other) const {
    return _seconds == other._seconds;
}

bool TimeReference::operator<(const TimeReference& other) const {
    return _seconds < other._seconds;
}

bool TimeReference::operator<=(const TimeReference& other) const {
    return _seconds <= other._seconds;
}

bool TimeReference::operator>(const TimeReference& other) const {
    return _seconds > other._seconds;
}

bool TimeReference::operator>=(const TimeReference& other) const {
    return _seconds >= other._seconds;
}

TimeReference& TimeReference::operator=(const TimeReference& other) {
    _seconds = other._seconds;
    return *this;
}

real TimeReference::inSeconds() const {
    return _seconds;
}

integer TimeReference::getMS() const {
    return (integer)(math::fractionalPart(_seconds) * 1000.0);
}

std::string TimeReference::toString() const {
    return toString("%H:%M:%S.{ms}");
}

std::string TimeReference::toString(const char* format) const {
    ubig secondsInteger = (ubig)_seconds;
    auto systemTime = std::chrono::system_clock::from_time_t(secondsInteger);
    auto timeValue = std::chrono::system_clock::to_time_t(systemTime);
    
    tm t;
    localtime_s(&t, &timeValue);

    std::stringstream str;
    str << std::put_time(&t, format);

    std::string result = str.str();

    // Milliseconds support
    stringReplace(result, "{ms}", stringFromFormat("%03d", getMS()));

    // Return
    return result;
}

std::string TimeReference::toStringSeconds() const {
    return stringFromFormat("%.3f", _seconds);
}

std::string TimeReference::toStringDate() const {
    return toString("%Y-%m-%d %H:%M:%S");
}

// # PreciseTimeValue

PreciseTimeValue PreciseTimeValue::zero() {
    return PreciseTimeValue(0);
}

PreciseTimeValue PreciseTimeValue::fromMilliseconds(ubig milliseconds) {
    return PreciseTimeValue(milliseconds);
}

PreciseTimeValue PreciseTimeValue::fromSeconds(ubig seconds) {
    return PreciseTimeValue(time::convert_big::convertSecondsToMilliseconds(seconds));
}

PreciseTimeValue PreciseTimeValue::fromMinutes(ubig minutes) {
    return PreciseTimeValue(time::convert_big::convertMinutesToMilliseconds(minutes));
}

PreciseTimeValue PreciseTimeValue::fromHours(ubig hours) {
    return PreciseTimeValue(time::convert_big::convertHoursToMilliseconds(hours));
}

PreciseTimeValue PreciseTimeValue::fromDays(ubig days) {
    return PreciseTimeValue(time::convert_big::convertDaysToMilliseconds(days));
}

PreciseTimeValue PreciseTimeValue::fromWeek(ubig weeks) {
    return PreciseTimeValue(time::convert_big::convertWeeksToMilliseconds(weeks));
}

PreciseTimeValue PreciseTimeValue::fromCommonYear(ubig years) {
    return PreciseTimeValue(time::convert_big::convertCommonYearsToMilliseconds(years));
}

PreciseTimeValue PreciseTimeValue::fromLeapYear(ubig years) {
    return PreciseTimeValue(time::convert_big::convertLeapYearsToMilliseconds(years));
}

PreciseTimeValue PreciseTimeValue::fromCenturies(ubig centuries) {
    return PreciseTimeValue(time::convert_big::convertCenturiesToMilliseconds(centuries));
}

PreciseTimeValue PreciseTimeValue::fromMillennia(ubig millennia) {
    return PreciseTimeValue(time::convert_big::convertMillenniaToMilliseconds(millennia));
}

PreciseTimeValue::PreciseTimeValue(ubig milliseconds) : _milliseconds(milliseconds) {

}

PreciseTimeValue::PreciseTimeValue(const PreciseTimeValue& other) : _milliseconds(other._milliseconds) {

}

bool PreciseTimeValue::operator==(const PreciseTimeValue& other) const {
    return _milliseconds == other._milliseconds;
}

bool PreciseTimeValue::operator<(const PreciseTimeValue& other) const {
    return _milliseconds < other._milliseconds;
}

bool PreciseTimeValue::operator<=(const PreciseTimeValue& other) const {
    return _milliseconds <= other._milliseconds;
}

bool PreciseTimeValue::operator>(const PreciseTimeValue& other) const {
    return _milliseconds > other._milliseconds;
}

bool PreciseTimeValue::operator>=(const PreciseTimeValue& other) const {
    return _milliseconds >= other._milliseconds;
}

PreciseTimeValue& PreciseTimeValue::operator=(const PreciseTimeValue& other) {
    _milliseconds = other._milliseconds;
    return *this;
}

PreciseTimeValue PreciseTimeValue::operator+(const PreciseTimeValue& other) const {
    return _milliseconds + other._milliseconds;
}

PreciseTimeValue PreciseTimeValue::operator-(const PreciseTimeValue& other) const {
    return _milliseconds - other._milliseconds;
}

PreciseTimeValue PreciseTimeValue::operator*(const PreciseTimeValue& other) const {
    return _milliseconds * other._milliseconds;
}

PreciseTimeValue PreciseTimeValue::operator/(const PreciseTimeValue& other) const {
    return _milliseconds / other._milliseconds;
}

PreciseTimeValue& PreciseTimeValue::operator+=(const PreciseTimeValue& other) {
    _milliseconds += other._milliseconds;
    return *this;
}

PreciseTimeValue& PreciseTimeValue::operator-=(const PreciseTimeValue& other) {
    _milliseconds -= other._milliseconds;
    return *this;
}

PreciseTimeValue& PreciseTimeValue::operator++() {
    // Prefix ++
    _milliseconds++;
    return *this;
}

PreciseTimeValue PreciseTimeValue::operator++(int postFix) {
    // Postfix ++
    auto old = *this;
    _milliseconds++;
    return old;
}

ubig PreciseTimeValue::inMilliseconds() const {
    return _milliseconds;
}

ubig PreciseTimeValue::inSeconds() const {
    return time::convert_big::convertMillisecondsToSeconds(_milliseconds);
}

ubig PreciseTimeValue::inMinutes() const {
    return time::convert_big::convertMillisecondsToMinutes(_milliseconds);
}

ubig PreciseTimeValue::inHours() const {
    return time::convert_big::convertMillisecondsToHours(_milliseconds);
}

ubig PreciseTimeValue::inDays() const {
    return time::convert_big::convertMillisecondsToDays(_milliseconds);
}

ubig PreciseTimeValue::inWeeks() const {
    return time::convert_big::convertMillisecondsToWeeks(_milliseconds);
}

ubig PreciseTimeValue::inCommonYears() const {
    return time::convert_big::convertMillisecondsToCommonYears(_milliseconds);
}

ubig PreciseTimeValue::inLeapYears() const {
    return time::convert_big::convertMillisecondsToLeapYears(_milliseconds);
}

ubig PreciseTimeValue::inCenturies() const {
    return time::convert_big::convertMillisecondsToCenturies(_milliseconds);
}

ubig PreciseTimeValue::inMillennia() const {
    return time::convert_big::convertMillisecondsToMillennia(_milliseconds);
}

// # SmallTimeValue

SmallTimeValue SmallTimeValue::zero() {
    return SmallTimeValue(0);
}

SmallTimeValue SmallTimeValue::fromPicoseconds(ubig picoseconds) {
    return SmallTimeValue(picoseconds);
}

SmallTimeValue SmallTimeValue::fromNanoseconds(ubig nanoseconds) {
    return SmallTimeValue(time::convert_big::convertNanosecondsToPicoseconds(nanoseconds));
}

SmallTimeValue SmallTimeValue::fromMicroseconds(ubig microseconds) {
    return SmallTimeValue(time::convert_big::convertMicrosecondsToPicoseconds(microseconds));
}

SmallTimeValue SmallTimeValue::fromMilliseconds(ubig milliseconds) {
    return SmallTimeValue(time::convert_big::convertMillisecondsToPicoseconds(milliseconds));
}

SmallTimeValue SmallTimeValue::fromSeconds(ubig seconds) {
    return SmallTimeValue(time::convert_big::convertSecondsToPicoseconds(seconds));
}

SmallTimeValue::SmallTimeValue(ubig picoseconds) : _picoseconds(picoseconds) {

}

SmallTimeValue::SmallTimeValue(const SmallTimeValue& other) : _picoseconds(other._picoseconds) {

}

bool SmallTimeValue::operator==(const SmallTimeValue& other) const {
    return _picoseconds == other._picoseconds;
}

bool SmallTimeValue::operator<(const SmallTimeValue& other) const {
    return _picoseconds < other._picoseconds;
}

bool SmallTimeValue::operator<=(const SmallTimeValue& other) const {
    return _picoseconds <= other._picoseconds;
}

bool SmallTimeValue::operator>(const SmallTimeValue& other) const {
    return _picoseconds > other._picoseconds;
}

bool SmallTimeValue::operator>=(const SmallTimeValue& other) const {
    return _picoseconds >= other._picoseconds;
}

SmallTimeValue& SmallTimeValue::operator=(const SmallTimeValue& other) {
    _picoseconds = other._picoseconds;
    return *this;
}

SmallTimeValue SmallTimeValue::operator+(const SmallTimeValue& other) const {
    return _picoseconds + other._picoseconds;
}

SmallTimeValue SmallTimeValue::operator-(const SmallTimeValue& other) const {
    return _picoseconds - other._picoseconds;
}

SmallTimeValue SmallTimeValue::operator*(const SmallTimeValue& other) const {
    return _picoseconds * other._picoseconds;
}

SmallTimeValue SmallTimeValue::operator/(const SmallTimeValue& other) const {
    return _picoseconds / other._picoseconds;
}

SmallTimeValue& SmallTimeValue::operator+=(const SmallTimeValue& other) {
    _picoseconds += other._picoseconds;
    return *this;
}

SmallTimeValue& SmallTimeValue::operator-=(const SmallTimeValue& other) {
    _picoseconds -= other._picoseconds;
    return *this;
}

SmallTimeValue& SmallTimeValue::operator++() {
    // Prefix ++
    _picoseconds++;
    return *this;
}

SmallTimeValue SmallTimeValue::operator++(int postFix) {
    // Postfix ++
    auto old = *this;
    _picoseconds++;
    return old;
}

ubig SmallTimeValue::inPicoseconds() const {
    return _picoseconds;
}

ubig SmallTimeValue::inNanoseconds() const {
    return time::convert_big::convertPicosecondsToNanoseconds(_picoseconds);
}

ubig SmallTimeValue::inMicroseconds() const {
    return time::convert_big::convertPicosecondsToMicroseconds(_picoseconds);
}

ubig SmallTimeValue::inMilliseconds() const {
    return time::convert_big::convertPicosecondsToMilliseconds(_picoseconds);
}

ubig SmallTimeValue::inSeconds() const {
    return time::convert_big::convertPicosecondsToSeconds(_picoseconds);
}

// # PunyTimeValue

PunyTimeValue PunyTimeValue::zero() {
    return PunyTimeValue(0);
}

PunyTimeValue PunyTimeValue::fromYoctoseconds(ubig yoctoseconds) {
    return PunyTimeValue(yoctoseconds);
}

PunyTimeValue PunyTimeValue::fromZeptoseconds(ubig zeptoseconds) {
    return PunyTimeValue(time::convert_big::convertZeptosecondsToYoctoseconds(zeptoseconds));
}

PunyTimeValue PunyTimeValue::fromAttoseconds(ubig attoseconds) {
    return PunyTimeValue(time::convert_big::convertAttosecondsToYoctoseconds(attoseconds));
}

PunyTimeValue PunyTimeValue::fromFemtoseconds(ubig femtoseconds) {
    return PunyTimeValue(time::convert_big::convertFemtosecondsToYoctoseconds(femtoseconds));
}

PunyTimeValue PunyTimeValue::fromPicoseconds(ubig picoseconds) {
    return PunyTimeValue(time::convert_big::convertPicosecondsToYoctoseconds(picoseconds));
}

PunyTimeValue::PunyTimeValue(ubig yoctoseconds) : _yoctoseconds(yoctoseconds) {

}

PunyTimeValue::PunyTimeValue(const PunyTimeValue& other) : _yoctoseconds(other._yoctoseconds) {

}

bool PunyTimeValue::operator==(const PunyTimeValue& other) const {
    return _yoctoseconds == other._yoctoseconds;
}

bool PunyTimeValue::operator<(const PunyTimeValue& other) const {
    return _yoctoseconds < other._yoctoseconds;
}

bool PunyTimeValue::operator<=(const PunyTimeValue& other) const {
    return _yoctoseconds <= other._yoctoseconds;
}

bool PunyTimeValue::operator>(const PunyTimeValue& other) const {
    return _yoctoseconds > other._yoctoseconds;
}

bool PunyTimeValue::operator>=(const PunyTimeValue& other) const {
    return _yoctoseconds >= other._yoctoseconds;
}

PunyTimeValue& PunyTimeValue::operator=(const PunyTimeValue& other) {
    _yoctoseconds = other._yoctoseconds;
    return *this;
}

PunyTimeValue PunyTimeValue::operator+(const PunyTimeValue& other) const {
    return _yoctoseconds + other._yoctoseconds;
}

PunyTimeValue PunyTimeValue::operator-(const PunyTimeValue& other) const {
    return _yoctoseconds - other._yoctoseconds;
}

PunyTimeValue PunyTimeValue::operator*(const PunyTimeValue& other) const {
    return _yoctoseconds * other._yoctoseconds;
}

PunyTimeValue PunyTimeValue::operator/(const PunyTimeValue& other) const {
    return _yoctoseconds / other._yoctoseconds;
}

PunyTimeValue& PunyTimeValue::operator+=(const PunyTimeValue& other) {
    _yoctoseconds += other._yoctoseconds;
    return *this;
}

PunyTimeValue& PunyTimeValue::operator-=(const PunyTimeValue& other) {
    _yoctoseconds -= other._yoctoseconds;
    return *this;
}

PunyTimeValue& PunyTimeValue::operator++() {
    // Prefix ++
    _yoctoseconds++;
    return *this;
}

PunyTimeValue PunyTimeValue::operator++(int postFix) {
    // Postfix ++
    auto old = *this;
    _yoctoseconds++;
    return old;
}

ubig PunyTimeValue::inYoctoseconds() const {
    return _yoctoseconds;
}

ubig PunyTimeValue::inZeptoseconds() const {
    return time::convert_big::convertYoctosecondsToZeptoseconds(_yoctoseconds);
}

ubig PunyTimeValue::inAttoseconds() const {
    return time::convert_big::convertYoctosecondsToAttoseconds(_yoctoseconds);
}

ubig PunyTimeValue::inFemtoseconds() const {
    return time::convert_big::convertYoctosecondsToFemtoseconds(_yoctoseconds);
}

ubig PunyTimeValue::inPicoseconds() const {
    return time::convert_big::convertYoctosecondsToPicoseconds(_yoctoseconds);
}

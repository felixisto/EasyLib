
#include "../CString.h"
#include "../Character.h"
#include "../../Math/Hashing/MurmurHash64B.h"
#include "../../Collections/Array/List.h"
#include <functional>
#include <codecvt>

using namespace easy;

const CString CString::STRING = CString();
const CString CString::EMPTY = CString();
const CString CString::WHITE_SPACE = CString(" ");
const CString CString::DOT = CString(".");
const CString CString::COMMA = CString(",");
const CString CString::ZERO = CString("0");
const CString CString::ONE = CString("1");
const CString CString::BTRUE = CString("true");
const CString CString::BFALSE = CString("false");

CString CString::create() {
    return CString();
}

CString CString::createFromFormat(cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    return CString(string);
}

CString CString::format(cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    return CString(string);
}

CString CString::createFromUTF8Bytes(const byte* buffer, int length) {
    const character* cstr = reinterpret_cast<const character*>(buffer);
    return CString(std::string(cstr, length));
}

CString CString::createFromUTF8Chars(const character* buffer, int length) {
    return CString(std::string(buffer, length));
}

CString CString::createFromASCIIBytes(const byte* buffer, int length) {
    const character* cstr = reinterpret_cast<const character*>(buffer);
    return CString(std::string(cstr, length));
}

CString CString::createFromASCIIChars(const character* buffer, int length) {
    return CString(std::string(buffer, length));
}

CString CString::createHex(big value) {
    CString result = CString::format("%X", value);
    CString lo = CString::format("%X", value);

    if (value > 0xffffffffl) {
        CString hi = CString::format("%X", (int)(value >> 32));

        result = result + hi;

        for (int i = lo.length(); i < 8; i++) {
            result = result + "0";
        }
    }
    result = result + lo;
    return result;
}

CString CString::createBool(bool value) {
    return CString(value ? "true" : "false");
}

CString::CString() {

}

CString::CString(const CString& string) : _string(string._string) {

}

CString::CString(cstring str) {
    _string = std::string(str);
}

CString::CString(character value) : _string(1, value) {

}

CString::CString(byte value) {
    character buff[2];
    snprintf(buff, sizeof(buff), "%d", value);
    _string = std::string(buff);
}

CString::CString(integer value) {
    character buff[32];
    snprintf(buff, sizeof(buff), "%d", value);
    _string = std::string(buff);
}

CString::CString(uinteger value) {
    character buff[32];
    snprintf(buff, sizeof(buff), "%u", value);
    _string = std::string(buff);
}

CString::CString(big value) {
    character buff[48];
    snprintf(buff, sizeof(buff), "%llu", value);
    _string = std::string(buff);
}

CString::CString(real value) {
    if ((integer)value == value) {
        character buff[96];
        snprintf(buff, sizeof(buff), "%d", (integer)value);
        _string = std::string(buff);

    } else {
        character buff[96];
        snprintf(buff, sizeof(buff), "%.1f", value);
        _string = std::string(buff);
    }
}

CString::CString(const std::string& string) : _string(string) {

}

CString::CString(const std::wstring& string) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    _string = converter.to_bytes(string);
}

CString::~CString() {

}

// # Operators

bool CString::operator==(const CString& other) const {
    return _string == other._string;
}

bool CString::operator!=(const CString& other) const {
    return _string != other._string;
}

CString& CString::operator=(const CString& other) {
    _string = other._string;
    return *this;
}

CString CString::operator+(const CString& other) const {
    auto result = _string + other._string;
    return CString(result.rawString());
}

CString& CString::operator+=(const CString& other) {
    _string += other._string;
    return *this;
}

bool CString::operator<(const CString& other) const {
    return _string < other._string;
}

// # Equality

bool CString::isEqual(const CString& other) const {
    return _string.isEqual(other._string);
}

bool CString::isEqualToString(const CString& other) const {
    return _string.isEqualToString(other._string);
}

bool CString::isEqualToString(const CString& other, bool ignoreCase) const {
    return _string.isEqualToString(other._string, ignoreCase);
}

// # Propeties

cstring CString::c() const {
    return _string.buffer();
}

cstring CString::buffer() const {
    return _string.buffer();
}

integer CString::length() const {
    return _string.length();
}

bool CString::isEmpty() const {
    return _string.isEmpty();
}

bool CString::isNumber() const {
    return _string.isNumber();
}

// # Transformation

bool CString::asBool() const {
    return _string.asBool();
}

character CString::asChar() const {
    return _string.asChar();
}

byte CString::asByte() const {
    return _string.asByte();
}

short CString::asShort() const {
    return _string.asShort();
}

ushort CString::asUShort() const {
    return _string.asUShort();
}

integer CString::asInteger() const {
    return _string.asInteger();
}

uinteger CString::asUInteger() const {
    return _string.asUInteger();
}

big CString::asBig() const {
    return _string.asBig();
}

real CString::asReal() const {
    return _string.asReal();
}

std::string CString::asSTDString() const {
    return std::string(_string.buffer());
}

std::wstring CString::asWString() const {
    if (isEmpty()) {
        return std::wstring();
    }

    auto string = asSTDString();

    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;
    const character* first = reinterpret_cast<const character*> (&string[0]);
    const character* last = reinterpret_cast<const character*> (&string[0] + string.size());
    auto result = converter.from_bytes(first, last);
    return result;
}

bool CString::parseToInteger(int radix, int& result) const {
    big lResult = 0;
    
    auto parseResult = parseToLong(radix, lResult);

    result = reinterpret_cast<int&>(lResult);

    return parseResult;
}

bool CString::parseToLong(int radix, big& result) const {
    cstring str = buffer();

    character* end;
    errno = 0;
    result = strtoll(str, &end, radix);

    return errno != ERANGE;
}

// # Accessing string

character CString::operator[](integer index) const {
    return _string[index];
}

character CString::characterAt(integer index) const {
    return _string.characterAt(index);
}

integer CString::indexOf(character c) const {
    return _string.indexOf(c);
}

integer CString::indexOf(character c, uinteger fromIndex) const {
    return _string.indexOf(c, fromIndex);
}

integer CString::lastIndexOf(character c) const {
    return _string.lastIndexOf(c);
}

integer CString::lastIndexOf(character c, uinteger fromIndex) const {
    return _string.lastIndexOf(c, fromIndex);
}

integer CString::indexOf(const CString& other) const {
    return _string.indexOf(other._string);
}

integer CString::indexOf(const CString& other, uinteger fromIndex) const {
    return _string.indexOf(other._string, fromIndex);
}

integer CString::lastIndexOf(const CString& other) const {
    return _string.lastIndexOf(other._string);
}

integer CString::lastIndexOf(const CString& other, uinteger fromIndex) const {
    return _string.lastIndexOf(other._string, fromIndex);
}

// # Query

bool CString::contains(character c) const {
    return _string.contains(c);
}

bool CString::contains(const CString& other) const {
    return _string.contains(other._string);
}

integer CString::numberOfOccurrences(const CString& other) const {
    return _string.numberOfOccurrences(other._string);
}

bool CString::beginsWith(const CString& other) const {
    return _string.beginsWith(other._string);
}

bool CString::endsWith(const CString& other) const {
    return _string.endsWith(other._string);
}

CString CString::substring(uinteger beginIndex) const {
    return _string.substring(beginIndex).rawString();
}

CString CString::substring(uinteger beginIndex, uinteger endIndex) const {
    return _string.substring(beginIndex, endIndex).rawString();
}

// # String manipulation

void CString::set(const CString& other) {
    _string.set(other._string);
}

void CString::clear() {
    _string.clear();
}

void CString::toLowerCase() {
    _string.toLowerCase();
}

void CString::toUpperCase() {
    _string.toUpperCase();
}

void CString::trim() {
    trimLeading();
    trimTrailing();
}

void CString::trimLeading() {
    if (indexOf(' ') == kInvalidIndex) {
        return;
    }

    auto data = _string.rawString();

    data.erase(std::find_if(data.rbegin(), data.rend(), std::bind1st(std::not_equal_to<character>(), ' ')).base(), data.end());

    _string.set(data);
}

void CString::trimTrailing() {
    if (indexOf(' ') == kInvalidIndex) {
        return;
    }

    auto data = _string.rawString();

    data.erase(data.begin(), std::find_if(data.begin(), data.end(), std::bind1st(std::not_equal_to<character>(), ' ')));

    _string.set(data);
}

void CString::concat(character c) {
    _string.concat(c);
}

void CString::concat(const CString& str) {
    _string.concat(str._string);
}

void CString::concatWord(const CString& word) {
    _string.concatWord(word._string);
}

void CString::concatWord(const CString& separator, const CString& word) {
    _string.concatWord(separator._string, word._string);
}

void CString::replaceFirst(const CString& target, const CString& replacement) {
    _string.replaceFirst(target._string, replacement._string);
}

void CString::replaceLast(const CString& target, const CString& replacement) {
    _string.replaceLast(target._string, replacement._string);
}

void CString::replaceAll(const CString& target, const CString& replacement) {
    _string.replaceAll(target._string, replacement._string);
}

void CString::replaceAllWhitespace(const CString& replacement) {
    _string.replaceAllWhitespace(replacement._string);
}

void CString::removeFirst(const CString& target) {
    _string.replaceFirst(target._string, CString::EMPTY._string);
}

void CString::removeLast(const CString& target) {
    _string.replaceLast(target._string, CString::EMPTY._string);
}

void CString::removeAll(const CString& target) {
    _string.replaceAll(target._string, CString::EMPTY._string);
}

void CString::insert(character c, uinteger insertIndex) {
    _string.insert(c, insertIndex);
}

void CString::insert(const CString& str, uinteger insertIndex) {
    _string.insert(str._string, insertIndex);
}

void CString::reverse() {
    _string.reverse();
}

List<CString> CString::split(const CString& separator) const {
    List<CString> result;
    auto split = _string.split(separator._string);
    int size = (int)split.size();

    for (int e = 0; e < size; e++) {
        result.add(CString(split[e].rawString()));
    }

    return result;
}

List<CString> CString::splitWords() const {
    return split(CString::WHITE_SPACE);
}

// # StringRepresentable

CString CString::toString() const {
    return *this;
}

// # Hashable

ubig CString::hashValue() const {
    return easy::MurmurHash64B::global().hash(*this);
}

// # Copyable

CString CString::copy() const {
    return *this;
}

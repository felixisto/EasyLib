#pragma once

#include "../Basic/Utilities.h"
#include <functional>

namespace easy {
    template<typename STR, typename C>
    struct BasicString {
    private:

        STR _string;

    public:

        static STR WHITE_SPACE() {
            char whitespace = ' ';
            C charValue = reinterpret_cast<C&>(whitespace);
            return STR(1, charValue);
        }

        BasicString() {

        }

        BasicString(const BasicString& other) : _string(other._string) {

        }

        BasicString(const STR& string) : _string(string) {

        }

        BasicString(int count, C value) : _string(count, value) {

        }

        virtual ~BasicString() {

        }

        // # Operators

        bool operator==(const BasicString& other) const {
            return _string == other._string;
        }

        bool operator!=(const BasicString& other) const {
            return _string != other._string;
        }

        bool operator<(const BasicString& other) const {
            return _string < other._string;
        }

        BasicString& operator=(const BasicString& other) {
            _string = other._string;
            return *this;
        }

        BasicString operator+(const BasicString& other) const {
            auto result = _string + other._string;
            return result;
        }

        BasicString& operator+=(const BasicString& other) {
            _string += other._string;
            return *this;
        }

        // # Equality

        bool isEqual(const BasicString& other) const {
            return *this == other;
        }

        bool isEqualToString(const BasicString& other) const {
            return *this == other;
        }

        bool isEqualToString(const BasicString& other, bool ignoreCase) const {
            if (!ignoreCase)
            {
                return isEqualToString(other);
            }

            if (length() != other.length()) {
                return false;
            }

            BasicString lowerA(*this);
            lowerA.toLowerCase();

            BasicString lowerB(other);
            lowerB.toLowerCase();

            return lowerA == lowerB;
        }

        // # Properties

        const C* buffer() const {
            return _string.c_str();
        }

        const STR& rawString() const {
            return _string;
        }

        integer length() const {
            return _string.length();
        }

        bool isEmpty() const {
            return length() == 0;
        }

        bool isNumber() const {
            if (isEmpty()) {
                return false;
            }

            C ch;
            char simpleChar;
            bool dot = false;

            for (integer e = 0; e < length(); e++) {
                ch = _string[e];
                simpleChar = reinterpret_cast<char&>(ch);

                if (!IsCharDigit(simpleChar)) {
                    if (ch == '.') {
                        // If the dot is the first or last character, then return false
                        if (e == 0 || e + 1 >= length()) {
                            return false;
                        }
                        else {
                            // Second dot? Return false
                            if (dot)
                            {
                                return false;
                            }

                            dot = true;
                        }
                    }
                    else {
                        if (e == 0) {
                            if (ch == '+' || ch == '-') {
                                continue;
                            }
                        }

                        return false;
                    }
                }
            }

            return true;
        }

        // # Transformation

        bool asBool() const {
            if (isEmpty()) {
                return false;
            }

            return atoi(buffer());
        }

        C asChar() const {
            if (length() != 1) {
                return characterAt(0);
            }

            return 0;
        }

        byte asByte() const {
            if (isEmpty()) {
                return false;
            }

            return atoi(buffer());
        }

        short asShort() const {
            if (isEmpty()) {
                return false;
            }

            return atoi(buffer());
        }

        ushort asUShort() const {
            if (isEmpty()) {
                return false;
            }

            return atoi(buffer());
        }

        integer asInteger() const {
            if (isEmpty()) {
                return false;
            }

            return atoi(buffer());
        }

        uinteger asUInteger() const {
            if (isEmpty()) {
                return false;
            }

            return atoi(buffer());
        }

        big asBig() const {
            if (isEmpty()) {
                return false;
            }

            return atol(buffer());
        }

        real asReal() const {
            if (isEmpty()) {
                return false;
            }

            return atof(buffer());
        }

        // # Accessing string

        C operator[](integer index) const {
            return characterAt(index);
        }

        C characterAt(integer index) const {
            return _string.at(index);
        }

        integer indexOf(C c) const {
            integer i = _string.find(c, 0);

            return (i != std::string::npos ? i : kInvalidIndex);
        }

        integer indexOf(C c, integer fromIndex) const {
            if (fromIndex >= length() || isEmpty()) {
                return kInvalidIndex;
            }

            integer i = _string.find(c, fromIndex);

            return (i != std::string::npos ? i : kInvalidIndex);
        }

        integer lastIndexOf(C c) const {
            if (isEmpty()) {
                return kInvalidIndex;
            }

            integer i = _string.find_last_of(c);

            return (i != std::string::npos ? i : kInvalidIndex);
        }

        integer lastIndexOf(C c, integer fromIndex) const {
            if (fromIndex >= length() || isEmpty()) {
                return kInvalidIndex;
            }

            integer i = _string.find_last_of(c, fromIndex);

            return (i != std::string::npos ? i : kInvalidIndex);
        }

        integer indexOf(const BasicString& str) const {
            if (!str.length() || isEmpty()) {
                return kInvalidIndex;
            }

            integer i = _string.find(str._string.c_str(), 0);

            return (i != std::string::npos ? i : kInvalidIndex);
        }

        integer indexOf(const BasicString& str, integer fromIndex) const {
            if (fromIndex >= length() || isEmpty()) {
                return kInvalidIndex;
            }

            integer i = _string.find(str._string.c_str(), fromIndex);

            return (i != std::string::npos ? i : kInvalidIndex);
        }

        integer lastIndexOf(const BasicString& str) const {
            if (isEmpty()) {
                return kInvalidIndex;
            }

            integer i = _string.find(str._string.c_str());

            while (i != std::string::npos)
            {
                integer next = _string.find(str._string.c_str(), i + 1);

                if (next == std::string::npos)
                {
                    break;
                }

                i = next;
            }

            return (i != std::string::npos ? i : kInvalidIndex);
        }

        integer lastIndexOf(const BasicString& str, integer fromIndex) const {
            if (fromIndex >= length() || isEmpty()) {
                return kInvalidIndex;
            }

            integer i = _string.find(str._string.c_str(), fromIndex);

            while (i != std::string::npos)
            {
                integer next = _string.find(str._string.c_str(), i + 1);

                if (next == std::string::npos)
                {
                    break;
                }

                i = next;
            }

            return (i != std::string::npos ? i : kInvalidIndex);
        }

        // # Query

        bool contains(C c) const {
            return indexOf(c) != kInvalidIndex;
        }

        bool contains(const BasicString& str) const {
            return indexOf(str) != kInvalidIndex;
        }

        integer numberOfOccurrences(const BasicString& str) const {
            integer count = 0;

            integer index = indexOf(str);

            while (index != kInvalidIndex) {
                count++;
                index = indexOf(str, index + 1);
            }

            return count;
        }

        bool beginsWith(const BasicString& str) const {
            if (str.isEmpty()) {
                return true;
            }

            if (isEmpty()) {
                return false;
            }

            if (_string[0] != str._string[0]) {
                return false;
            }

            return indexOf(str) == 0;
        }

        bool endsWith(const BasicString& str) const {
            if (str.isEmpty()) {
                return true;
            }

            if (isEmpty()) {
                return false;
            }

            integer i = lastIndexOf(str);

            if (i == kInvalidIndex) {
                return false;
            }

            return i == (length() - str.length());
        }

        BasicString substring(integer beginIndex) const {
            if (beginIndex >= length() || isEmpty()) {
                return BasicString();
            }

            if (beginIndex == 0) {
                return *this;
            }

            if (beginIndex == length() - 1) {
                if (beginIndex < length())
                {
                    return BasicString(1, characterAt(beginIndex));
                }

                return BasicString();
            }

            return _string.substr(beginIndex, length() - 1);
        }

        BasicString substring(integer beginIndex, integer endIndex) const {
            if (endIndex > length()) {
                endIndex = length();
            }

            if (beginIndex + (endIndex - beginIndex) > length() || beginIndex >= endIndex) {
                return BasicString();
            }

            if (isEmpty()) {
                return BasicString();
            }

            if (beginIndex == endIndex - 1) {
                if (beginIndex < length()) {
                    return BasicString(1, characterAt(beginIndex));
                }

                return BasicString();
            }

            return _string.substr(beginIndex, endIndex - beginIndex);
        }

        // # String manipulation

        void clear() {
            _string.clear();
        }

        void set(const BasicString<STR, C>& other) {
            _string = other._string;
        }

        void set(const STR& other) {
            _string = other;
        }

        static char charToLowerCase(char c) {
            return tolower(c);
        }

        static char charToUpperCase(char c) {
            return toupper(c);
        }

        static char16_t charToLowerCase(char16_t c) {
            return towlower(c);
        }

        static char16_t charToUpperCase(char16_t c) {
            return towupper(c);
        }

        void toLowerCase() {
            for (auto it = _string.begin(); it != _string.end(); ++it) {
                *it = charToLowerCase(*it);
            }
        }

        void toUpperCase() {
            for (auto it = _string.begin(); it != _string.end(); ++it) {
                *it = charToUpperCase(*it);
            }
        }

        void concat(C c) {
            _string.append(1, c);
        }

        void concat(const BasicString& str) {
            _string.append(str._string);
        }

        void concatWord(const BasicString& word) {
            if (word.isEmpty()) {
                return;
            }

            if (isEmpty()) {
                _string = word._string;
            }
            else {
                concat(WHITE_SPACE());
                concat(word);
            }
        }

        void concatWord(const BasicString& separator, const BasicString& word)
        {
            if (word.isEmpty()) {
                return;
            }

            if (separator.isEmpty()) {
                concat(word);
                return;
            }

            if (isEmpty()) {
                *this = word;
            }
            else {
                if (!endsWith(separator)) {
                    concat(separator);
                }

                concat(word);
            }
        }

        void replaceFirst(const BasicString& target, const BasicString& replacement)
        {
            size_t start_pos = _string.find(target._string.c_str());

            if (start_pos != std::string::npos) {
                _string.replace(start_pos, target._string.length(), replacement._string);
            }
        }

        void replaceLast(const BasicString& target, const BasicString& replacement)
        {
            size_t prev_pos = 0;
            size_t start_pos = 0;

            while ((start_pos = _string.find(target._string.c_str(), start_pos)) != std::string::npos) {
                prev_pos = start_pos;
                start_pos += replacement._string.length() + 1;
            }

            _string.replace(prev_pos, target._string.length(), replacement._string);
        }

        void replaceAll(const BasicString& target, const BasicString& replacement)
        {
            size_t start_pos = 0;

            auto targetString = target._string;
            const size_t targetLength = target._string.length();
            const size_t replacementLength = replacement._string.length();

            while ((start_pos = _string.find(targetString, start_pos)) != std::string::npos) {
                _string.replace(start_pos, targetLength, replacement._string);
                start_pos += replacementLength + 1;
            }
        }

        void replaceAllWhitespace(const BasicString& replacement)
        {
            size_t start_pos = 0;

            const size_t targetLength = 1;
            const size_t replacementLength = replacement._string.length();

            while ((start_pos = _string.find(' ', start_pos)) != std::string::npos) {
                _string.replace(start_pos, targetLength, replacement._string);
                start_pos += replacementLength + 1;
            }
        }

        void insert(C c, integer insertIndex)
        {
            _string.insert(insertIndex, 1, c);
        }

        void insert(const BasicString& str, integer insertIndex)
        {
            _string.insert(insertIndex, str._string);
        }

        void reverse() {
            auto copyData = _string;
            std::reverse(copyData.begin(), copyData.end());
            _string = copyData;
        }

        std::vector<BasicString<STR, C>> split(const BasicString& separator) const {
            if (isEmpty()) {
                return std::vector<BasicString>();
            }

            if (separator.isEmpty()) {
                return std::vector<BasicString>();
            }

            std::vector<BasicString> array;

            integer a = 0;
            integer b = -1;

            while ((b = indexOf(separator, b + 1)) != kInvalidIndex) {
                if (b > a) {
                    array.push_back(substring(a, b));
                }

                a = b + separator.length();
            }

            if (a < length()) {
                array.push_back(substring(a, length()));
            }

            return array;
        }
    };
};

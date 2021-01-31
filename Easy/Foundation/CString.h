#pragma once

#include "../Basic/Basic.h"
#include "BasicString.h"

namespace easy {
    template<typename E>
    struct List;

    /*
     * A string of 1 byte wide characters.
     * 
     * Performance:
	 * Access: O(1)
	 * Back insertion: O(1) or O(n)
	 * Other insertion: O(n)
	 * Back erase: O(1)
	 * Other erase: O(n)
	 * Find sorted: O(log n)
	 * Find unsorted: O(n)
     */
    struct CString : StringRepresentable, Hashable, Copyable<CString> {
        // Constants.
        static const CString STRING;
        static const CString EMPTY;
        static const CString WHITE_SPACE;
        static const CString DOT;
        static const CString COMMA;
        static const CString ZERO;
        static const CString ONE;
        static const CString BTRUE;
        static const CString BFALSE;

    private:

        BasicString<std::string, character> _string;

    public:

        static CString create();
        static CString createFromFormat(cstring format, ...);
        static CString format(cstring format, ...);
        static CString createFromUTF8Bytes(const byte* buffer, int length);
        static CString createFromUTF8Chars(const character* buffer, int length);
        static CString createFromASCIIBytes(const byte* buffer, int length);
        static CString createFromASCIIChars(const character* buffer, int length);
        static CString createHex(big value);
        static CString createBool(bool value);

        CString();
        CString(const CString& CString);
        CString(cstring str);
        CString(character value);
        CString(byte value);
        CString(integer value);
        CString(uinteger value);
        CString(big value);
        CString(real value);
        CString(const std::string& CString);
        CString(const std::wstring& CString);

        virtual ~CString();

        // # Operators

        bool operator==(const CString& CString) const;
        bool operator!=(const CString& CString) const;
        bool operator<(const CString& CString) const;
        CString& operator=(const CString& CString);
        CString operator+(const CString& CString) const;
        CString& operator+=(const CString& CString);

        // # Equality

        bool isEqual(const CString& CString) const;
        bool isEqualToString(const CString& CString) const;
        bool isEqualToString(const CString& CString, bool ignoreCase) const;

        // # Properties

        cstring c() const;
        cstring buffer() const;
        integer length() const;
        bool isEmpty() const;
        bool isNumber() const;

        // # Transformation

        bool asBool() const;
        character asChar() const;
        byte asByte() const;
        short asShort() const;
        ushort asUShort() const;
        integer asInteger() const;
        uinteger asUInteger() const;
        big asBig() const;
        real asReal() const;
        std::string asSTDString() const;
        std::wstring asWString() const;

        // Converts the CString value to an integer. Returns true if successful; false otherwise.
        // Use 0 for default radix.
        bool parseToInteger(int radix, int& result) const;
        bool parseToLong(int radix, big& result) const;

        // # Accessing string

        character operator[](integer index) const;
        character characterAt(integer index) const;
        integer indexOf(character c) const;
        integer indexOf(character c, uinteger fromIndex) const;
        integer lastIndexOf(character c) const;
        integer lastIndexOf(character c, uinteger fromIndex) const;
        integer indexOf(const CString& str) const;
        integer indexOf(const CString& str, uinteger fromIndex) const;
        integer lastIndexOf(const CString& str) const;
        integer lastIndexOf(const CString& str, uinteger fromIndex) const;

        // # Query

        bool contains(character c) const;
        bool contains(const CString& str) const;

        integer numberOfOccurrences(const CString& str) const;

        bool beginsWith(const CString& str) const;
        bool endsWith(const CString& str) const;

        CString substring(uinteger beginIndex) const;
        CString substring(uinteger beginIndex, uinteger endIndex) const;

        // # String manipulation

        void set(const CString& other);
        void clear();

        void toLowerCase();
        void toUpperCase();
        void trim();
        void trimLeading();
        void trimTrailing();

        void concat(character c);
        void concat(const CString& str);
        void concatWord(const CString& word);
        void concatWord(const CString& separator, const CString& word);

        void replaceFirst(const CString& target, const CString& replacement);
        void replaceLast(const CString& target, const CString& replacement);
        void replaceAll(const CString& target, const CString& replacement);
        void replaceAllWhitespace(const CString& replacement);
        void removeFirst(const CString& target);
        void removeLast(const CString& target);
        void removeAll(const CString& target);

        void insert(character c, uinteger insertIndex);
        void insert(const CString& str, uinteger insertIndex);

        void reverse();

        List<CString> split(const CString& separator) const;
        List<CString> splitWords() const;

        // # StringRepresentable

        virtual CString toString() const;

        // # Hashable

        virtual ubig hashValue() const;

        // # Copyable

        virtual CString copy() const;
    };

};

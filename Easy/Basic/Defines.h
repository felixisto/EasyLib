#pragma once

#include <math.h>

/// char (1 byte)
/// The C standart does not specify if plain char is signed or unsigned. It's machine dependent.
/// Look up for CHAR_MIN in <limits.h> to see if characters are signed or unsigned.
/// If CHAR_MIN is 0 then char is unsigned. Otherwise it's signed.
//typedef char;

// Same as int. Long int = int.
//typedef long

// 4 bytes. Avoid usage, use double/real instead.
//typedef float

// 1 byte char. Whether its signed or not depends on platform.
typedef char character;
// Signed 2 bytes char.
typedef char16_t wcharacter;
// Unsigned 1 byte char.
typedef unsigned char byte;
// Unsigned 2 bytes short.
typedef unsigned short ushort;
// Signed 4 bytes int.
typedef signed int integer;
// Unsigned 4 bytes int.
typedef unsigned int uinteger;
// Signed 8 byte int.
typedef signed long long int big;
// Unsigned 8 byte int.
typedef unsigned long long int ubig;
// Signed 8 byte double.
// Decimal precision is up to 6 digits: 0.000001
// Value accuracy significantly degrades as it gets closer to either INFINITY value.
typedef double real;
// Pointer size.
typedef const char* cstring;

/// Generally used by collections and strings to represent invalid index/index not found.
#define kInvalidIndex -1

/// Returns true if the given real is +INFINITY or -INFINITY; false otherwise.
#define RealIsInfinity(value) (value == INFINITY || value == -INFINITY)

/// Returns true if the given real is NaN; false otherwise.
#define RealIsNaN(value) (value != value)

/// Returns true if the given real is NaN; false otherwise.
#define RealIsNaNOrInfinity(value) (value != value || value == INFINITY || value == -INFINITY)

/// The ratio of the circumference of a circle to its diameter.
#define MATH_PI M_PI

/// The double value that is closer than any other to e, the base of the natural logarithms.
#define MATH_E M_E

#define IsCharDigit(c) (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')

typedef void (*GenericFunction)();

void GenericFunctionTemplate();

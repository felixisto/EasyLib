#pragma once

#include "Defines.h"
#include "String.h"
#include <math.h>
#include <cstdlib>
#include <ctime>

namespace easy {
    struct Point {
        static Point ZERO() {
            return Point();
        }

        real x;
        real y;

        Point();
        Point(const Point& other);
        Point(real x, real y);

        real distanceBetween(const Point& other) const;
    };

    struct Size {
        static Size ZERO() {
            return Size();
        }

        real width;
        real height;

        Size();
        Size(const Size& other);
        Size(real width, real height);

        real areaSize() const;
    };

    struct Rectangle {
        static Rectangle ZERO() {
            return Rectangle();
        }

        Point origin;
        Size size;

        Rectangle();
        Rectangle(const Rectangle& other);
        Rectangle(const Point& origin, const Size& size);
    };

    struct Range {
        static Range ZERO() {
            return Range(0, 0);
        }

        uinteger start;
        uinteger end;

        static Range CreateStart(uinteger start);
        static Range CreateStartEnd(uinteger start, uinteger end);
        static Range CreateStartLength(uinteger start, uinteger length);

        Range();
        Range(const Range& other);
        Range(uinteger start, uinteger end);

        integer length() const;

        bool overlaps(const Range& other) const;

        void moveForwardsBy(integer value);
    };
};

namespace easy {
	namespace math {
        /// The ratio of the circumference of a circle to its diameter.
        extern real PI;

        /// The double value that is closer than any other to e, the base of the natural logarithms.
        extern real E;

        /// Returns the absolute value of the given value.
        static real absolute(real value) {
            return (value < 0 ? -value : value);
        }

        /// Returns the absolute value of the given value.
        static integer absolute(integer value) {
            return (value < 0 ? -value : value);
        }

        /// Returns whiever is the highest value of the two given parameters.
        static real maximum(real a, real b) {
            return a > b ? a : b;
        }

        /// Returns whiever is the lowest value of the two given parameters.
        static real minimum(real a, real b) {
            return a < b ? a : b;
        }

        /// Returns the given value raised to the given power.
        static real powerOf(real value, real p) {
            return pow(value, p);
        }

        /// Returns the given value raised to the power of 2.
        static real powerOf2(real value) {
            return powerOf(value, 2);
        }

        /// Returns the given value raised to the power of 3.
        static real powerOf3(real value) {
            return powerOf(value, 3);
        }
        
        /// Returns the given value raised to the power of 4.
        static real powerOf4(real value) {
            return powerOf(value, 4);
        }

        /// Returns the given value raised to the power of 10.
        static real powerOf10(real value) {
            return powerOf(value, 10);
        }

        /// Returns the square root value if the specified value.
        static real sqrtOf(real value) {
            return sqrt(value);
        }

        /// Returns the natural logarithm of the given value.
        static real logarithm(real value) {
            return log(value);
        }

        /// Returns the integral part of the given value, with the same sign.
        static real integralPart(real value) {
            real integralPart = 0.0;
            modf(value, &integralPart);
            return integralPart;
        }

        /// Returns the integral part of the given value, with the same sign.
        static float integralPart(float value) {
            float integralPart = 0.0;
            modff(value, &integralPart);
            return integralPart;
        }

        /// Returns the fractional part of the given value, with the same sign.
        static real fractionalPart(real value) {
            real integralPart = 0.0;
            real fractionalPart = modf(value, &integralPart);
            return fractionalPart;
        }

        /// Returns the fractional part of the given value, with the same sign.
        static float fractionalPart(float value) {
            float integralPart = 0.0;
            float fractionalPart = modff(value, &integralPart);
            return fractionalPart;
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static real clampValue(real value, real min, real max) {
            return (value < min ? min : (value > max ? max : (value == value ? value : max)));
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static real clamp(real value, real min, real max) {
            if (!(min <= value && value <= max)) {
                value = value < min ? min : max;
            }

            return value;
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static float clamp(float value, float min, float max) {
            if (!(min <= value && value <= max)) {
                value = value < min ? min : max;
            }

            return value;
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static big clamp(big value, big min, big max) {
            if (!(min <= value && value <= max)) {
                value = value < min ? min : max;
            }

            return value;
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static integer clamp(integer value, integer min, integer max) {
            if (!(min <= value && value <= max)) {
                value = value < min ? min : max;
            }

            return value;
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static void clamp(uinteger& value, uinteger min, uinteger max) {
            if (!(min <= value && value <= max)) {
                value = value < min ? min : max;
            }
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static void clamp(short& value, short min, short max) {
            if (!(min <= value && value <= max)) {
                value = value < min ? min : max;
            }
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static void clamp(ushort& value, ushort min, ushort max) {
            if (!(min <= value && value <= max)) {
                value = value < min ? min : max;
            }
        }

        /// Clamps the given value by making sure that it is within the specified range [min, max].
        static void clamp(byte& value, byte min, byte max) {
            if (!(min <= value && value <= max)) {
                value = value < min ? min : max;
            }
        }

        /// Converts degrees to radians.
        static real degreesToRadians(real a) {
            return a * (PI / 180.0);
        }

        /// Degrees balance between 0 <= and < 360.
        static real degrees(real a) {
            while (a >= 360.0) { a -= 360.0; }
            while (a < 0.0) { a += 360.0; }

            return a;
        }

        /// Converts radians to degrees.
        static real radiansToDegrees(real a) {
            return a * (180.0 / PI);
        }

        /// Returns the distance between two given points.
        static real distance(const Point& a, const Point& b) {
            return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
        }

        /// Returns the cosine of an angle expressed in degrees.
        static real cosine(real angle) {
            return cos(angle * 0.01745329251994);
        }

        /// Returns the sine of an angle expressed in degrees.
        static real sine(real angle) {
            return sin(angle * 0.01745329251994);
        }

        /// Returns the tangent of an angle expressed in degrees.
        static real tangent(real angle) {
            return tan(angle * 0.01745329251994);
        }

        /// Returns the arc sine of an angle expressed in degrees.
        static real arcsine(real angle) {
            return asin(angle * 0.01745329251994);
        }

        /// Returns the arc cosine of an angle expressed in degrees.
        static real arccosine(real angle) {
            return acos(angle * 0.01745329251994);
        }

        /// Returns the arc tangent of an angle expressed in degrees.
        static real arctangent(real angle) {
            return atan(angle * 0.01745329251994) * 57.29577951307854;
        }

        /// Returns the principal value of the arc tangent of y/x, expressed in degrees.
        /// To compute the value, the function takes into account the sign of both arguments in order to determine the quadrant.
        static real arctangent2(real y, real x) {
            return atan2(y, x) * 57.29577951307854;
        }

		static bool isNumberOdd(integer value) {
			return value % 2;
		}

		static bool isNumberEven(integer value) {
			return !isNumberOdd(value);
		}

		struct Random {
        private:

            Random(int seed) {
                srand(seed);
            }

		public:
            static const Random& standard() {
                int seed = (int)time(NULL);
                static Random r(seed);
                return r;
            }

            Random() {
                // Call this, to make sure srand is called at least once
                Random::standard();
            }

			integer integerValue() const {
				return (integer)rand();
			}

			integer integerValue(integer a, integer b) const {
				if (a == b) {
					return a;
				}

				return (integer)((integerValue() % (b - a + 1)) + a);
			}

			real realValue() const {
				return (real)(rand() / 0x100000000);
			}

			real realValue(real a, real b) const {
				if (a == b) {
					return a;
				}

				return ((rand() * (b - a) / 0x100000000) + a);
			}
		};
	};
};